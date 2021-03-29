#include <utility>
#include <string>

#ifndef CPP_LESSON8_OOP_2_H
#define CPP_LESSON8_OOP_2_H

#endif //CPP_LESSON8_OOP_2_H

namespace lesson2
{
    class Person {
    protected:
        std::string name;
        unsigned int age;
        unsigned int weight;
        bool sex;
    public:
        void setName(std::string new_name);
        std::string const getName();
        void setAge(unsigned int new_age);
        unsigned int const getAge();
        void setWeight(unsigned int new_weight);
        unsigned int const getWeight();
        void setSex(bool new_sex);
        std::string const getSex();
        Person(std::string p_name, unsigned int p_age, unsigned int p_weight, bool p_sex) {
            name = p_name;
            age = p_age;
            weight = p_weight;
            sex = p_sex;
        }
        Person() {}
    };

    class Student: public Person {
        unsigned int year;
        static int studentCounter;
    public:
        void setYear(unsigned int new_year_value);
        void incrementYear();
        static unsigned int studentCount();
        Student(std::string p_name, unsigned int s_age, unsigned int s_weight, bool s_sex, unsigned int s_year) {
            name = p_name;
            age = s_age;
            weight = s_weight;
            sex = s_sex;
            year = s_year;
            studentCounter++;
        }
        ~Student() {
            studentCounter--;
        }
    };

    class Fruit {
    protected:
        std::string name;
        std::string color;
    public:
        std::string getName();
        std::string getColor();
    };

    class Apple: public Fruit {
    public:
        Apple(std::string this_color) {
            name = "Apple";
            color = this_color;
        };
        Apple() {
            name = "Apple";
            color = "Red";
        };
    };

    class Banana: public Fruit {
    public:
        Banana() {
            name = "Banana";
            color = "Yellow";
        };
    };

    class GrannySmith: public Apple {
    public:
        GrannySmith() {
            name = "Granny Smith apple";
            color = "Green";
        };
    };
}