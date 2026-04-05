// src/compositor.c
#include "compositor.h"
#include <wlr/backend.h>
#include <wlr/render/wlr_renderer.h>
#include <wlr/types/wlr_output.h>
#include <wlr/types/wlr_compositor.h>
#include <wlr/types/wlr_xdg_shell.h>
#include <wlr/util/log.h>

struct horizon_compositor *horizon_compositor_create() {
    wlr_log_init(WLR_DEBUG, NULL);

    struct horizon_compositor *hc = calloc(1, sizeof(*hc));
    hc->display = wl_display_create();
    hc->backend = wlr_backend_autocreate(hc->display, NULL);
    hc->renderer = wlr_renderer_autocreate(hc->backend);
    hc->compositor = wlr_compositor_create(hc->display, hc->renderer);
    hc->xdg_shell = wlr_xdg_shell_create(hc->display);
    hc->output_frame.notify = handle_output_frame;
    wl_signal_add(&output->events.frame, &hc->output_frame);

    return hc;
}

void horizon_compositor_run(struct horizon_compositor *hc) {
    wl_display_run(hc->display);
}

void horizon_compositor_destroy(struct horizon_compositor *hc) {
    wl_display_destroy(hc->display);
    free(hc);
}

static void handle_output_frame(struct wl_listener *listener, void *data) {
    struct wlr_output *output = data;
    struct horizon_compositor *hc = wl_container_of(listener, hc, output_frame);

    struct wlr_renderer *renderer = hc->renderer;

    // Begin rendering
    wlr_output_attach_render(output, NULL);
    wlr_renderer_begin(renderer, output->width, output->height);

    // Clear background
    float bg[4] = { 0.1f, 0.1f, 0.1f, 1.0f };
    wlr_renderer_clear(renderer, bg);

    // Draw a rectangle
    float color[4] = { 0.2f, 0.4f, 1.0f, 1.0f }; // blue
    float box_x = 100;
    float box_y = 100;
    float box_w = 300;
    float box_h = 200;

    wlr_render_rect(renderer,
                    &(struct wlr_box){ box_x, box_y, box_w, box_h },
                    color,
                    output->transform_matrix);

    // Finish rendering
    wlr_renderer_end(renderer);
    wlr_output_commit(output);
}
