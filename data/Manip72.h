#ifndef MANIP72_H
#define MANIP72_H

#include <iostream>
namespace Manip72 {
    // Класс для манипуляции форматированием вывода
    class Manip {
    public:
        Manip(int w, int b, int p, char f);
        friend std::ostream& operator<<(std::ostream& os, const Manip& m);

    private:
        int width;
        int base;
        int precision;
        char fill;
    };
    int run();
}
#endif // MANIP72_H
