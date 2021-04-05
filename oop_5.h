#ifndef CPP_LESSON8_OOP_5_H
#define CPP_LESSON8_OOP_5_H

#endif //CPP_LESSON8_OOP_5_H

namespace lesson5
{

    template <class T>
    class Pair1 {
        T val1;
        T val2;
    public:
        Pair1(T v1, T v2) {
            val1 = v1;
            val2 = v2;
        }
        T first() const {
            return val1;
        }
        T second() const {
            return val2;
        }
    };

    template <class T, class T2>
    class Pair2 {
        T val1;
        T2 val2;
    public:
        Pair2(T v1, T2 v2) {
            val1 = v1;
            val2 = v2;
        }
        T first() const {
            return val1;
        }
        T2 second() const {
            return val2;
        }
    };


    template <class T, class T2>
    class Pair {};

    template<class T>
    class Pair<std::string, T> {
        std::string val1;
        T val2;
    };

    template<class T, class T2>
    class StringValuePair : Pair<T, T2> {};

    template<class T>
    class StringValuePair<std::string, T> : public Pair<std::string, T> {
        std::string val1;
        T val2;
    public:
        std::string first() const {
            return val1;
        }
        T last() const {
            return val2;
        }
        StringValuePair(std::string v1, T v2);
    };

    template<class T>
    StringValuePair<std::string, T>::StringValuePair(std::string v1, T v2) {
        val1 = v1;
        val2 = v2;
    }

}