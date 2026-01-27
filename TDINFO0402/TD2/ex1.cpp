#include "stdlib.h"
#include <iostream>
#include <cstdio>


// DEFINITION
class A1 {
    int a1 = 0;
    public:
        A1() = default;
        A1(int x): a1(x){}
        int get() const {return a1;}
};
class A2 {
    int a2 = 0;
    public:
        A2() = default;
        A2(int x): a2(x){}
        int get() const {return a2;}
};

// EXERCICE 1.5
class B: public A1 {
    A2 x;
    public: 
    B():A1(), x() {}
    B(const B& b): A1(b), x(b.x){}
    bool operator != (const B& b) const {return true;}
    B& operator = (const B& b){
        if (this != &b)
        {
            A1& this_A1 = *this;
            this_A1 = b;
        }
        return *this;
    }
    //EXERCICE 1.9
    std::ostream& operator<<(std::ostream& os, const B& b){

    }

};



int main() {
    return EXIT_SUCCESS;
}