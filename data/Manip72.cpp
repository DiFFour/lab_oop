#include "Manip72.h"
#include <iomanip>
namespace Manip72 {
Manip::Manip(int w, int b, int p, char f)
    : width(w), base(b), precision(p), fill(f) {}

std::ostream& operator<<(std::ostream& os, const Manip& m) {
    os << std::setw(m.width)
       << std::setfill(m.fill)
       << std::fixed; // Фиксированный формат вывода чисел с плавающей запятой

    if (m.base == 8)
        os << std::oct;
    else if (m.base == 10)
        os << std::dec;
    else if (m.base == 16)
        os << std::hex;

    os << std::setprecision(m.precision);

    return os;
}
}