#ifndef CPP_LESSON8_OOP_4_H
#define CPP_LESSON8_OOP_4_H

#include <cassert> // для assert()
#include <iostream>
#include <vector>


#define SWAP_INT(x, y) int temp; temp = x; x = y; y = temp

namespace lesson4
{
    class ArrayInt {
    private:
        int m_length;
        int *m_data;

    public:
        ArrayInt(): m_length(0), m_data(nullptr) { }
        ArrayInt(int length): m_length(length) {
            assert(length >= 0);

            if (length > 0)
                m_data = new int[length];
            else
                m_data = nullptr;
        }
        ~ArrayInt() {
            delete[] m_data;
        }

        void erase() {
            delete[] m_data;

            m_data = nullptr;
            m_length = 0;
        }
        int getLength() { return m_length; }
        int& operator[](int index) {
            assert(index >= 0 && index < m_length);
            return m_data[index];
        }
        void resize(int newLength) {
            if (newLength == m_length)
                return;

            if (newLength <= 0)
            {
                erase();
                return;
            }

            int *data = new int[newLength];

            if (m_length > 0)
            {
                int elementsToCopy = (newLength > m_length) ? m_length : newLength;
                for (int index=0; index < elementsToCopy ; ++index)
                    data[index] = m_data[index];
            }

            delete[] m_data;

            m_data = data;
            m_length = newLength;
        }
        void insertBefore(int value, int index)
        {
            assert(index >= 0 && index <= m_length);

            int *data = new int[m_length+1];

            for (int before=0; before < index; ++before)
                data[before] = m_data[before];

            data [index] = value;

            for (int after=index; after < m_length; ++after)
                data[after+1] = m_data[after];

            delete[] m_data;
            m_data = data;
            ++m_length;
        }
        void push_back(int value) {
            insertBefore(value, m_length);
        }
        void pop_back() {
            assert(m_length >= 1);
            --m_length;
        }
        void pop_front() {
            assert(m_length >= 1);

            int *data = new int[m_length - 1];
            for (int i=1; i < m_length; i++) {
                data[i-1] = m_data[i];
            }

            delete[] m_data;
            m_data = data;
            --m_length;
        }
        void sort() {
            bool sort_end = false;

            while (!sort_end) {
                sort_end = true;
                for (int i = 0; i < m_length - 1; i++) {
                    if (m_data[i] > m_data[i + 1]) {
                        sort_end = false;
                        SWAP_INT(m_data[i], m_data[i + 1]);
                    }
                }
            }
        }
        void print() {
            for (int i = 0; i < m_length; i++) {
                std::cout << m_data[i] << " ";
            }
            std::cout << std::endl;
        }
    };



    int count_different_ints_in_vector(std::vector<int> vector, int size) {
        int diffs = 0;
        std::vector<int> counted;
        std::vector<int>::iterator it;

        for (int i = 0; i < size; i++) {
            it = std::find(counted.begin(), counted.end(), vector[i]);
            if (it != counted.end()) {
                continue;
            } else {
                counted.push_back(vector[i]);
                diffs++;
            }
        }

        return diffs;
    }

}




#endif //CPP_LESSON8_OOP_4_H
