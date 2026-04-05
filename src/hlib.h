// src/hlib.h
#pragma once

struct horizon_element;

void horizon_log(const char *msg);
void horizon_move(struct horizon_element *el, int x, int y);
