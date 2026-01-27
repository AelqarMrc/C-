#include "stdlib.h"
#include <iostream>
#include <cstdio>


// DEFINITION
struct Point2d
{
    float x_ = 0, y_ = 0;

    Point2d()= default;
    Point2d(const Point2d&) = default;
    Point2d(float x, float y): x_(x), y_(y){}
    Point2d& set (float x, float y) {
        x_=x; y_=y;
        return *this;
    }
    float x() const {return x_;}
    float y() const {return y_;}
    
};

class Stroke {
    Point2d start;
    public:
        Stroke()= default;
        Stroke(const Stroke&)=default;
        Stroke(const Point2d& p): start(p){}
        virtual ~Stroke() = default;
        Stroke& operator=(const Stroke& other){
            if (this != &other)
            {
                start = other.start;
            }
            
        }
};


class Circle: public Stroke
{
private:
    float radius = 1.f;
public:
    Circle(/* args */) = default;
    Circle(const Circle&) = default;
    Circle(const Point2d& p): Stroke(p) {}
    Circle(const Point2d& p, float r): Stroke(p), radius(r >= 0.f ? r : 1.f) {}
    Circle(float r): radius(r >= 0.f ? r : 1.f) {}
    friend std::ostream& operator<<(std::ostream os, const Circle& c){
        return os <<"Circle: {" << c.start << ",r:" << c.radius << "}";
    }
    ~Circle();
};

Circle::Circle(/* args */)
{
}

Circle::~Circle()
{
}


int main() {
    return EXIT_SUCCESS;
}