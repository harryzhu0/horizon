// src/hlib.c
#include "hlib.h"
#include <stdio.h>

void horizon_log(const char *msg) {
    printf("[Horizon] %s\n", msg);
}

void horizon_move(struct horizon_element *el, int x, int y) {
    el->x = x;
    el->y = y;
}
