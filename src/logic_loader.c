#include "logic_loader.h"
#include <dlfcn.h>
#include <stdio.h>

void *horizon_logic_load(const char *path) {
    char so_path[256];
    snprintf(so_path, sizeof(so_path), "%s/logic.so", path);
    return dlopen(so_path, RTLD_NOW);
}

horizon_init_fn horizon_logic_get_init(void *handle) {
    return (horizon_init_fn)dlsym(handle, "horizon_init");
}
