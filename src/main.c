// src/main.c
#include "compositor.h"

int main() {
    struct horizon_compositor *compositor = horizon_compositor_create();
    horizon_compositor_run(compositor);
    horizon_compositor_destroy(compositor);
    return 0;
}
