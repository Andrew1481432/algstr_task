#include <iostream>
#include "Utils.h"

void Utils::clearStdAndShowErr() {
    std::cout << endl << "Введено некорректное значение!" << std::endl;
    std::cin.clear();
    std::cin.ignore(10000,'\n');
    cout << "Пожалуйста повторите попытку ввода: ";
}

template<class Type>
Type Utils::getInput(){
    std::cin.clear();

    Type number;

    tryEnterValue:
    if (std::is_same<Type, int>::value) {
        double tempValue;
        cin >> tempValue;

        if(tempValue != int(tempValue)) {
            //cout << "debug: double" << endl;
            clearStdAndShowErr();
            goto tryEnterValue;
        } else {
            number = int(tempValue);
        }
    } else {
        cin >> number;
    }

    if(std::cin.fail() || cin.get() != '\n') {
        //cout << "debug: fall" << endl;
        clearStdAndShowErr();
        goto tryEnterValue;
    }
    return number;
}

// Explicit instantiation for int.
template int Utils::getInput<int>();
