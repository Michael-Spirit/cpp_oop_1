#include <string>
#include <iostream>
#include <sstream>
#include <cmath>

#ifndef CPP_LESSON8_OOP_3_H
#define CPP_LESSON8_OOP_3_H

#endif //CPP_LESSON8_OOP_3_H

namespace lesson3
{
//  1.
    class Figure {
    public:
        virtual float area()=0;
    };

    class Parallelogram: public Figure {
    public:
        unsigned int a;
        unsigned int b;
        Parallelogram(unsigned int x, unsigned int y) {
            a=x;
            b=y;
        }
        float area() {
            return static_cast<float>(a * b);
        }
    };

    class Circle: public Figure {
        unsigned int radius;
    public:
        Circle(unsigned int r) {
            radius = r;
        }
        float area() {
            return M_PI * pow(radius, 2);
        }
    };

    class Rectangle: public Parallelogram {
    public:
        Rectangle(unsigned int x, unsigned int y) : Parallelogram(x, y) {
            a=x;
            b=y;
        }
    };

    class Square: public Parallelogram {
    public:
        Square(unsigned int x) : Parallelogram(x, x) {
            a=x;
            b=x;
        }
    };

    class Rhombus: public Parallelogram {
    public:
        Rhombus(unsigned int d1, unsigned int d2) : Parallelogram(d1, d2) {
            a = d1;
            b = d2;
        }
    };


//  2.
    class Car {
    public:
        std::string company;
        std::string model;
        Car(std::string c, std::string m) {
            std::cout << "Car" << std::endl;
            company = c;
            model = m;
        }
    };

    class PassengerCar: public Car {
    public:
        PassengerCar(std::string c, std::string m) : Car(c, m) {
            std::cout << "PassengerCar" << std::endl;
            company = c;
            model = m;
        }
    };

    class Bus: public Car {
    public:
        Bus(std::string c, std::string m): Car(c, m) {
            std::cout << "Bus" << std::endl;
            company = c;
            model = m;
        }
    };

    class Minivan: public PassengerCar, public Bus {
    public:
        Minivan(std::string c, std::string m) : PassengerCar(c, m), Bus(c, m) {
            std::cout << "Minivan" << std::endl;
        }
    };


//  3.
    class Fraction {
        float numenator;
        float denominator;
        friend bool operator==(const Fraction &f, const Fraction &f2) {
            return f.numenator / static_cast<float>(f.denominator) == f2.numenator / static_cast<float>(f2.denominator);
        }
        friend bool operator!=(const Fraction &f, const Fraction &f2) {
            return !(f == f2);
        }
        friend bool operator<(const Fraction &f, const Fraction &f2) {
            return f.numenator / static_cast<float>(f.denominator) < f2.numenator / static_cast<float>(f2.denominator);
        }
        friend bool operator>(const Fraction &f, const Fraction &f2) {
            return !(f < f2);
        }
        friend bool operator<=(const Fraction &f, const Fraction &f2) {
            return f.numenator / static_cast<float>(f.denominator) <= f2.numenator / static_cast<float>(f2.denominator);
        }
        friend bool operator>=(const Fraction &f, const Fraction &f2) {
            return f.numenator / static_cast<float>(f.denominator) >= f2.numenator / static_cast<float>(f2.denominator);
        }
        friend Fraction operator+=(Fraction &f, const Fraction &f2) {
            f.numenator += f2.numenator;
            f.denominator += f2.denominator;
            return f;
        }
        friend Fraction operator+(Fraction &f, const Fraction &f2) {
            return Fraction(f.numenator + f2.numenator, f.denominator + f2.denominator);
        }
        friend Fraction operator-(Fraction &f, const Fraction &f2) {
            return Fraction(f.numenator - f2.numenator, f.denominator - f2.denominator);
        }
        friend Fraction operator*(Fraction &f, const Fraction &f2) {
            return Fraction(f.numenator * f2.numenator, f.denominator * f2.denominator);
        }
        friend Fraction operator/(Fraction &f, const Fraction &f2) {
            return Fraction(f.numenator / static_cast<float>(f2.numenator), f.denominator / static_cast<float>(f2.denominator));
        }
    public:
        Fraction(int n, int d) {
            if (d != 0) {
                numenator = static_cast<float>(n);
                denominator = static_cast<float>(d);
            }
        }
        Fraction(float n, float d) {
            if (d != 0) {
                numenator = n;
                denominator = d;
            }
        }
        void print() {
            std::cout << numenator << "/" << denominator << std::endl;
        }
    };
}


