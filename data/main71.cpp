#include "STRING71.h"
#include <iostream>
namespace STRING71 {
    void run() {
        STRING str1("Hello");
        STRING str2(str1);

        // Демонстрация вывода строки через оператор <<
        std::cout << "str1: " << str1 << "\n";
        std::cout << "str2: " << str2 << "\n";

        // Изменение строки str1 через ввод пользователя
        std::cout << "Введите новую строку для str1: ";
        std::cin.ignore(); // Очистить буфер ввода
        std::cin >> str1;
        std::cout << "str1 после изменения: " << str1 << "\n";

        // Сравнение строк str1 и str2
        unsigned comparisonResult = str1.Strcmp(str2);
        std::cout << "Результат сравнения str1 и str2: " << comparisonResult << "\n";
    }
}
