#include <iostream>
#include <cstdlib>

class Power {
    int first_int = 0;
    int second_int = 0;
public:
    Power() : first_int(2), second_int(3) {}
    Power(int first, int second) {
        first_int=first;
        second_int=second;
    }
    void set(int x, int y) {
        first_int=x;
        second_int=y;
    }
    void calculate() {
        std::cout << pow(first_int, second_int) << std::endl;
    }
};


class RGBA {
    uint8_t m_red;
    uint8_t m_green;
    uint8_t m_blue;
    uint8_t m_alpha;
public:
    RGBA() : m_red(0), m_green(0), m_blue(0), m_alpha(255) {}
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

const int max_array_length = 10;

class Stack {
    int array[max_array_length] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int stack_length = max_array_length;
public:
    void reset() {
        for (int & i : array) { i = 0; }
        stack_length = 0;
    }
    bool push(int i) {
        if (stack_length >= max_array_length) {
            std::cout << "ERROR! Stackoverflow!" << std::endl;
            return false;
        }
        array[stack_length] = i;
        stack_length++;
        return true;
    }
    int pop() {
        if (stack_length == 0) {
            std::cout << "WARNING! Stack is empty!" << std::endl;
            return -1;
        }
        int element = array[stack_length];
        stack_length--;
        return element;
    }
    void print() {
        std::cout << "( ";
        for (int i = 0; i < stack_length; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << ")" << std::endl;
    }
};