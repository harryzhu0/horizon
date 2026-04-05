// src/compositor.h
#pragma once

#include <wayland-server-core.h>
#include <wlr/backend.h>
#include <wlr/render/wlr_renderer.h>
#include <wlr/types/wlr_output.h>
#include <wlr/types/wlr_xdg_shell.h>

struct horizon_compositor {
    struct wl_display *display;
    struct wlr_backend *backend;
    struct wlr_renderer *renderer;
    struct wlr_compositor *compositor;
    struct wlr_xdg_shell *xdg_shell;
};

struct horizon_compositor *horizon_compositor_create(void);
void horizon_compositor_run(struct horizon_compositor *hc);
void horizon_compositor_destroy(struct horizon_compositor *hc);
