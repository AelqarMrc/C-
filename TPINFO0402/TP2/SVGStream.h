#ifndef _SVGSTREAM_H
#define _SVGSTREAM_H
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////
class SVGstream {
private:
        std::ofstream    svgstream;
        void write_header(bool PureSVG = false); // À compléter
        void write_trailer(); // À compléter
public:
        void close() {
                if (svgstream.is_open()) {
                        write_trailer();
                        svgstream.close();
                }
        }
        bool open(const char *fname, bool PureSVG = false) {
                close();
                svgstream.open(fname, std::ios::out | std::ios::trunc);
                bool status = svgstream.is_open();
                if (status) write_header(PureSVG);
                return status;
        }
        SVGstream(const char *fname, bool PureSVG = false) :
                svgstream(fname, std::ios::out | std::ios::trunc) {
                if (svgstream.is_open()) write_header(PureSVG);
        }
        ~SVGstream(); // À compléter

        friend SVGstream& operator<<(SVGstream& s, const char *str); // À compléter
        friend SVGstream& operator<<(SVGstream& s, float str); // À compléter
};
#endif  // _SVGSTREAM_H
