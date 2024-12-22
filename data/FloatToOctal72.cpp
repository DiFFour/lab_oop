#include "FloatToOctal72.h"
namespace Manip72 {
std::string floatToOctal(double num, int precision) {
    int integerPart = static_cast<int>(num);
    double fractionalPart = num - integerPart;

    // Конвертируем целую часть в восьмеричную систему
    std::string integerStr;
    int tempInt = integerPart;
    if (tempInt == 0)
        integerStr = "0";
    else {
        while (tempInt > 0) {
            int digit = tempInt % 8;
            integerStr = std::to_string(digit) + integerStr;
            tempInt /= 8;
        }
    }

    // Конвертируем дробную часть в восьмеричную систему
    std::string fractionalStr;
    double tempFrac = fractionalPart;
    for (int i = 0; i < precision; ++i) {
        tempFrac *= 8;
        int digit = static_cast<int>(tempFrac);
        fractionalStr += std::to_string(digit);
        tempFrac -= digit;
    }

    // Используем запятую ',' как десятичный разделитель
    return integerStr + "," + fractionalStr;
}
}