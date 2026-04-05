// src/element.c
#include "element.h"
#include "logic_loader.h"
#include "xml.h"
#include "css.h"

struct horizon_element *horizon_element_load(const char *path) {
    struct horizon_element *el = calloc(1, sizeof(*el));

    el->layout = horizon_xml_load(path);
    el->style  = horizon_css_load(path);
    el->logic  = horizon_logic_load(path);

    return el;
}
