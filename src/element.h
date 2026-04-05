// src/element.h
struct horizon_element {
    char *name;
    void *layout;   // parsed XML
    void *style;    // parsed CSS
    void *logic;    // pointer to loaded .so
    int x, y, w, h; // position on the virtual sheet
};
