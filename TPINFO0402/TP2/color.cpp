#include "color.h"

const char *Color::name[nColor] = {
    "red", "white", "yellow", "orange", "turquoise", "violet", "pink", "green",
    "grey", "cyan", "blue", "brown"
};

std::ostream& operator<<(std::ostream &s, const Color &c) {
    s << c.getName();
    return s;
};

SVGstream& operator<<(SVGstream& s, const Color &c) {
    s << c.getName();
    return s;
}