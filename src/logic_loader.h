#pragma once

struct horizon_element;

typedef void (*horizon_init_fn)(struct horizon_element *self);

void *horizon_logic_load(const char *path);
horizon_init_fn horizon_logic_get_init(void *handle);
