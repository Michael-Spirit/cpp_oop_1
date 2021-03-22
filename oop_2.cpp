#include <iostream>
#include <string>
#include "oop_2.h"

void lesson2::Person::setName(std::string new_name) {
    name = new_name;
}

void lesson2::Person::setAge(unsigned int new_age) {
    age = new_age;
}

void lesson2::Person::setWeight(unsigned int new_weight) {
    weight = new_weight;
}

void lesson2::Person::setSex(bool new_sex) {
    sex = new_sex;
}

std::string lesson2::Person::getName() {
    return name;
}

unsigned int lesson2::Person::getAge() {
    return age;
}

unsigned int lesson2::Person::getWeight() {
    return weight;
}

std::string lesson2::Person::getSex() {
    return sex ? "M" : "F";
}

void lesson2::Student::setYear(unsigned int new_year_value) {
    year = new_year_value;
}

void lesson2::Student::incrementYear() {
    year++;
}

unsigned int lesson2::Student::studentCount() {
    return studentCounter;
}

std::string lesson2::Fruit::getName() {
    return name;
}
std::string lesson2::Fruit::getColor() {
    return color;
}
