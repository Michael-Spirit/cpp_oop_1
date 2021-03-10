#include <iostream>
#include <random>
#include <cstdlib>


using namespace std;


class Power {
    int first_int = 0;
    int second_int = 0;
public:
    Power() : first_int(2), second_int(3) {}
    Power(int first_int, int second_int) {
        first_int=first_int;
        second_int=second_int;
        cout << "Created Power obj first_int=" << first_int << " second_int=" << second_int << endl;
    }
    void setFirstInteger(int x) {
        first_int=x;
    }
    void setSecondInteger(int y) {
        second_int=y;
    }
    void set(int x, int y) {
        first_int=x;
        second_int=y;
    }
    int calculate() {
        cout << "POW" << first_int << second_int << endl;
        return pow(first_int, second_int);
    }
};


class RGBA {
    uint8_t m_red;
    uint8_t m_green;
    uint8_t m_blue;
    uint8_t m_alpha;
public:
    RGBA() : m_red(0), m_green(0), m_blue(0), m_alpha(255) {

    }
    void setRed(uint8_t red) {
        m_red = red;
    }
    void setGreen(uint8_t green) {
        m_green = green;
    }
    void setBlue(uint8_t blue) {
        m_blue = blue;
    }
    void setAlpha(uint8_t alpha) {
        m_alpha = alpha;
    }
    void set(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
        m_red = red;
        m_green = green;
        m_blue = blue;
        m_alpha = alpha;
    }
    void print() {
        printf("RGBA(red=%i, green=%i, blue=%i, alpha=%i)\n", m_red, m_green, m_blue, m_alpha);
    }
};

const int array_length = 10;

class Stack {
    int array[array_length] = {0,1,2,3,4,5,6,7,8,9};
    int stack_length = array_length;
public:
    void reset() {
        for (int & i : array) { i = 0; }
        stack_length = 0;
    }
    bool push(int i) {
        if (stack_length >= array_length) { return false; }
        array[stack_length] = i;
        stack_length++;
        return true;
    }
    bool pop() {
        if (stack_length == 0) { return false; }
        int element = array[stack_length];
        stack_length--;
        return element;
    }
    void print() {
        cout << "Stack values: ";
        for (int i = 0; i < stack_length; i++) {
            cout << array[i] << ", ";
        }
        cout << endl;
    }
};


int main() {
    Power p(4, 4);
    cout << p.calculate() << endl;

    RGBA rgba;
    rgba.print();
    rgba.set(1, 2, 3, 250);
    rgba.print();

    Stack stack_example;
    stack_example.print();
    stack_example.reset();
    stack_example.print();
    stack_example.push(1);
    stack_example.push(2);
    stack_example.print();
    cout << "pop value: " << stack_example.pop() << endl;
    stack_example.print();

    return 0;
}
