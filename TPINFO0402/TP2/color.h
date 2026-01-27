#ifndef _COLOR_H
#define _COLOR_H
#include <cstdint>
#include <iostream>
#include "SVGStream.h"
////////////////////////////////////////////////////////////////////////////////////////
class Color {
    public:
        enum colortype { red = 0, white, yellow, orange,
            turquoise, violet, pink, green, grey, cyan, blue, brown };
    private:
        static const size_t nColor = 12;
        static const char *name[];
        colortype color = red;
    public:
        Color(const colortype &c) : color(c) {}
        Color() = default;
        Color(const Color&) = default;
        Color& operator=(const Color&) = default;
        const char *getName() const { return name[color]; }
        void set(const colortype &c) { color = c; }
        friend std::ostream& operator<<(std::ostream &s, const Color &c); // À compléter
        friend SVGstream& operator<<(SVGstream& s, const Color &c); // À compléter
};

#endif  // _COLOR_H