#include <stdlib.h>
#include <iostream>
#include <cassert>

int PGCD(int a, int b) {
    // On s'assure que les nombres sont positifs
    // car le PGCD est défini sur les entiers naturels.
    assert(a >= 0 && b >= 0);

    while (b != 0) {
        int reste = a % b;
        a = b;
        b = reste;
    }
    return a;
}

struct Fraction
{
    private:
    //ATTRIBUTS
        int num;
        int den;
    
    public: 
    //CONSTRUCTEUR ET DESTRUCTEUR
        Fraction(int n, int d): num(n), den(d) { assert(den != 0); }
        Fraction(int i): num(i), den(1) {};
        Fraction(): Fraction(0,1) {};
        ~Fraction() {};

    //GETTERS ET SETTERS
        Fraction& setNum(int n){ num = n; return *this; }
        Fraction& setDen(int d) { 
            assert(d != 0);
            den = d;
            return *this;            
        }
        int& getNum() { return num; }
        int& getDen() { return den; }

    //METHODES
        void reduireFraction(Fraction& f){
            int p = PGCD(std::abs(f.num), std::abs(f.den));
            f.num = f.num/p;
            f.den = f.den/p;
        }
        
        void inverserFraction(Fraction& f){
            int tmp = f.num;
            f.num = f.den;
            f.den = tmp ;
        }

        Fraction addFraction(Fraction& f1, Fraction& f2){
            Fraction res = Fraction();
            res.den = f1.den * f2.den;
            res.num = (f1.num * f2.den) + (f2.num * f1.den);
            reduireFraction(res);

            return res;
        } 
    
    //SURCHARGE OPERATEUR AFFICHAGE
        friend std::ostream& operator<<(std::ostream& os, const Fraction& f){
            os << f.num << "/" << f.den;
            return os;
        }
    
};


int main() {
    return EXIT_SUCCESS;
}
