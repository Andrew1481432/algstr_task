#include <iostream>
#include "Utils.h"


string Utils::getColor(BACKCOLOR c) {
    //https://stackoverflow.com/questions/33309136/change-color-in-os-x-console-output
    return "\x1b["+std::to_string(static_cast<int>(c))+"m";
}

string Utils::getColor(FORECOLOR c) {
    //https://stackoverflow.com/questions/33309136/change-color-in-os-x-console-output
    return "\x1b["+std::to_string(static_cast<int>(c))+"m";
}

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
        if(cin.eof()) throw std::invalid_argument("Input end!");

        if(tempValue != int(tempValue)) {
            clearStdAndShowErr();
            goto tryEnterValue;
        } else {
            number = int(tempValue);
        }
    } else {
        cin >> number;
        if(cin.eof()) throw std::invalid_argument("Input end!");
    }

    if(std::cin.fail() || cin.get() != '\n') {
        clearStdAndShowErr();
        goto tryEnterValue;
    }
    return number;
}

// Explicit instantiation for int.
template int Utils::getInput<int>();

template double Utils::getInput<double>();
