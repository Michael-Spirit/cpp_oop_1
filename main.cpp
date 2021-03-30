#include <iostream>
#include "oop_3.h"

using namespace std;

int main() {
    cout << "1." << endl;
    lesson3::Circle circle(5);
    lesson3::Rectangle rectangle(3, 4);
    lesson3::Square square(5);
    lesson3::Rhombus rhombus(6, 8);

    cout << "Circle area: " << circle.area() << endl;
    cout << "Rectangle area: " << rectangle.area() << endl;
    cout << "Square area: " << square.area() << endl;
    cout << "Rhombus area: " << rhombus.area() << endl;

    cout << endl << "2." << endl;
    lesson3::Car car("Company", "Model");
    lesson3::PassengerCar passengerCar("Company2", "Model2");
    lesson3::Bus bus("Bus", "Model3");
    lesson3::Minivan minivan("Minivan", "Model4");

    cout << endl << "3." << endl;
    lesson3::Fraction fraction(1, 2);
    lesson3::Fraction fraction2(2, 3);
    lesson3::Fraction add = fraction + fraction2;
    lesson3::Fraction minus = fraction2 - fraction;
    lesson3::Fraction divide = fraction2 / fraction;
    lesson3::Fraction multiply = fraction * fraction2;

    cout << "Fraction1= "; fraction.print();
    cout << "Fraction2= "; fraction2.print();
    cout << "Equal? " << (fraction == fraction2) << endl;
    cout << "Not Equal? " << (fraction != fraction2) << endl;
    cout << "Lower or Equal? " << (fraction <= fraction2) << endl;
    cout << "Larger or Equal? " << (fraction >= fraction2) << endl;
    cout << "Larger? " << (fraction > fraction2) << endl;
    cout << "Lower? " << (fraction < fraction2) << endl;
    cout << "Add func: "; add.print();
    cout << "Minus func: "; minus.print();
    cout << "Divide func: "; divide.print();
    cout << "Multiply func: "; multiply.print();

    cout << endl << "4." << endl;
    lesson3::Card card;
    cout << card.GetValue() << endl;

    return 0;
}
