#ifndef CIAOD_UTILS_H
#define CIAOD_UTILS_H

#include <string>

using namespace std;

namespace Utils {
    namespace backGroundColor{
        enum COLOR{
            COLOR_RESET = 0,
            BLACK = 40,
            RED,
            GREEN,
            YELLOW,
            BLUE,
            MAGENTA,
            CYAN,
            WHITE
        };
    }
    namespace foreGroundColor{
        enum COLOR{
            COLOR_RESET = 0,
            BLACK = 30,
            RED,
            GREEN,
            YELLOW,
            BLUE,
            MAGENTA,
            CYAN,
            WHITE
        };
    }

    typedef backGroundColor::COLOR BACKCOLOR;
    typedef foreGroundColor::COLOR FORECOLOR;

    string getColor(BACKCOLOR C);
    string getColor(FORECOLOR C);

    extern void clearStdAndShowErr();

    template<class Type>
    extern Type getInput();
}

#endif //CIAOD_UTILS_H
