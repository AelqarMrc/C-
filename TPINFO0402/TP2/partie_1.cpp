#include <iostream>
#include <cstdio>
#include <cstdlib>

class Point
{
private:
    int x_ ,y_;
public:
    Point() = default ;
    Point(int x, int y): x_(x), y_(y) {}
    ~Point();
};


int main(int argc, const char** argv) {
    return EXIT_SUCCESS;
}
