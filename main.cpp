#include <iostream>
#include "oop_5.h"
#include "oop_3.h"
#include "blackjack.h"

using namespace std;

int main() {
//  1.
    cout << "1." << endl;
    lesson5::Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << " " << p1.second() << endl;

    const lesson5::Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << " " << p2.second() << endl;

//  2.
    cout << endl << "2." << endl;
    lesson5::Pair2<int, double> pair(6, 7.8);
    cout << "double Pair: " << pair.first() << " " << pair.second() << endl;
    lesson5::Pair2<double, int> pair2(3.4, 5);
    cout << "double Pair: " << pair2.first() << " " << pair2.second() << endl;

//  3.
    cout << endl << "3." << endl;
    lesson5::StringValuePair<std::string, int> stringValuePair("Amazing", 7);
    cout << "String Pair: " << stringValuePair.first() << " " << stringValuePair.last() << endl;

//  4. TODO
    cout << endl << "4." << endl;
    blackjack::Card card;
    cout << card.GetValue() << endl;

    return 0;
}
