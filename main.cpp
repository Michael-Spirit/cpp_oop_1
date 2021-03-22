#include <iostream>
#include "oop_2.h"

using namespace std;


int lesson2::Student::studentCounter = 0;

int main() {
    lesson2::Student s("Michael", 25, 90, true, 2007);
    lesson2::Student s2("Victor", 25, 95, true, 2007);
    lesson2::Student s3("Vica", 24, 66, false, 2007);
    std::cout << "Hello student: " << s.getName() << endl;
    std::cout << "Total Student created: " << lesson2::Student::studentCount() << endl << endl;

//  2.
    lesson2::Apple a("Red");
    lesson2::Banana b;
    lesson2::GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}
