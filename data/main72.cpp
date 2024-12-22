#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Manip72.h"
#include "FloatToOctal72.h"
namespace Manip72 {
int run() {
    setlocale(LC_ALL, "Russian");

    // Переменные
    char c1, c2;
    float f1, f2;
    int i;

    // Ввод переменных
    std::cout << "Введите переменные в порядке: c1 f1 i f2 c2\n";

    // Считываем символ c1
    std::cin >> c1;

    // Считываем число f1, заменяем ',' на '.'
    std::string f1_str;
    std::cin >> f1_str;
    std::replace(f1_str.begin(), f1_str.end(), ',', '.');
    f1 = std::stof(f1_str);

    // Считываем целое число i
    std::cin >> i;

    // Считываем число f2, заменяем ',' на '.'
    std::string f2_str;
    std::cin >> f2_str;
    std::replace(f2_str.begin(), f2_str.end(), ',', '.');
    f2 = std::stof(f2_str);

    // Считываем символ c2
    std::cin >> c2;

    // Открываем файл для записи
    std::ofstream outFile("output.txt");

    // Параметры манипулятора
    int width = 8;
    int base = 8; // O - восьмеричная система счисления
    char fillChar = '*';
    int precision1 = 2;
    int precision2 = 2;
    int precision3 = 3;

    // Функция для вывода и записи в файл
    auto output = [&](const std::string& str) {
        std::cout << str << std::endl;
        outFile << str << std::endl;
    };

    // Функция для форматирования и вывода переменных
    auto formatAndOutput = [&](auto value, int precision = -1) {
        std::ostringstream oss;

        if constexpr (std::is_same_v<decltype(value), int>) {
            // Обработка целого числа
            oss << Manip(width, base, 0, fillChar) << value;
        } else if constexpr (std::is_same_v<decltype(value), float>) {
            // Обработка числа с плавающей запятой
            std::string formattedFloat = floatToOctal(value, precision);
            oss << std::setw(width) << std::setfill(fillChar) << formattedFloat;
        } else if constexpr (std::is_same_v<decltype(value), char>) {
            // Обработка символа
            oss << value;
        }
        output(oss.str());
    };

    // Последовательность вывода: c2 i f1 c1 f2
    // c2
    formatAndOutput(c2);

    // i
    formatAndOutput(i);

    // f1 с точностью 2 знака после запятой
    formatAndOutput(f1, precision1);

    // f1 с точностью 2 знака (повторно)
    formatAndOutput(f1, precision2);

    // f1 с точностью 3 знака
    formatAndOutput(f1, precision3);

    // c1
    formatAndOutput(c1);

    // f2 с точностью 2 знака
    formatAndOutput(f2, precision1);

    // f2 с точностью 2 знака (повторно)
    formatAndOutput(f2, precision2);

    // f2 с точностью 3 знака
    formatAndOutput(f2, precision3);

    // Закрываем файл
    outFile.close();

    return 0;
}
}