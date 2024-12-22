#ifndef FORMATTED_PRINT6_H
#define FORMATTED_PRINT6_H

#include <iostream>
#include <string>
#include <stdexcept>
namespace Print6 {
// ▎Шаблонная функция для обработки одного аргумента
template <typename T>
void PrintFormatted(const std::string& format, T value) {
    size_t index = format.find("{}");
    if (index == std::string::npos) {
        throw std::invalid_argument("Не хватает {} для подстановки аргумента.");
    }
    std::cout << format.substr(0, index) << value;
    std::cout << format.substr(index + 2);
}

// ▎Шаблонная функция для обработки нескольких аргументов
template <typename T, typename... Args>
void PrintFormatted(const std::string& format, T value, Args... args) {
    size_t index = format.find("{}");
    if (index == std::string::npos) {
        throw std::invalid_argument("Не хватает {} для подстановки аргумента.");
    }
    std::cout << format.substr(0, index) << value;
    PrintFormatted(format.substr(index + 2), args...);
}
}
#endif
