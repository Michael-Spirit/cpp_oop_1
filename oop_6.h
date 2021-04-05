#ifndef CPP_LESSON8_OOP_6_H
#define CPP_LESSON8_OOP_6_H

#include <limits>
#include <iostream>

namespace lesson6
{
    void cin_only_number_format(int *number) {
        while (!(std::cin >> *number)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input format. Enter a number: ";
        }
    }

    std::ostream& endll(std::ostream& _os) {
        _os.put(_os.widen('\n'));
        _os.put(_os.widen('\n'));
        _os.flush();
        return _os;
    }
}

#endif //CPP_LESSON8_OOP_6_H
