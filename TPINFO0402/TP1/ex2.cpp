#include <iostream>
#include <cstdio>
#include <cmath>

void incr_affiche(int i) { printf("%d\n", i++); }
void incr_affiche_ref(int& i) { printf("%d\n", i++); }
void incr_affiche_const_ref(const int& i) { printf("%d\n", i+1); }

class  Complex
{
    private: 
        float r, i;
        float Norm(void) const;
    public:
        inline Complex(float u, float v): r(u), i(v) {printf("Initialisation avec 2 float \n");}
        inline Complex(float v): Complex(i,v) {printf("Initialisation avec 1 float \n");}
        inline Complex(): Complex(i,0) {printf("Initialisation par défaut  \n");}
        inline Complex(const Complex& c): Complex(c.r, c.i) {}
        ~Complex() {};
        void view() const {
            std::cout << "Complex c(" << r << "," << i << ")" << std::endl;
        }
        
};
float Complex::Norm(void) const{
    return sqrtf(r*r+i*i);
}

int main() {
    Complex c1;
    Complex c2(1.f);
    Complex c3(2.f, 3.f);
    c3.view();

    return EXIT_SUCCESS;
}