#include "STRING5.h"
#include <iostream>
namespace STRING5 {
int run() {
    int choice;
    STRING str1;
    STRING str2;
    STRING result;

    while (true) {
        std::cout << "\nМеню:\n"
                     "1. Ввести две строки\n"
                     "2. Сложение строк\n"
                     "3. Присваивание с перемещением (оператор `=`)\n"
                     "4. Функтор (длина строки)\n"
                     "5. Завершить программу\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;
        std::cin.ignore(); // Удаляем остаток строки после ввода числа

        switch (choice) {
            case 1: {
                char temp[MAX_LENGTH + 1];

                std::cout << "Введите первую строку: ";
                std::cin.getline(temp, MAX_LENGTH);
                str1.Setstr(temp);

                std::cout << "Введите вторую строку: ";
                std::cin.getline(temp, MAX_LENGTH);
                str2.Setstr(temp);

                std::cout << "Строки успешно заданы.\n";
                break;
            }
            case 2: {
                if (str1() == 0 || str2() == 0) {
                    std::cout << "Ошибка: сначала задайте строки через пункт 1.\n";
                    break;
                }

                std::cout << "Сложение строк: '" << str1() << "' и '" << str2() << "'\n";
                result = str1 + str2;
                std::cout << "Результат: ";
                result.Print();
                break;
            }
            case 3: {
                if (str1() == 0) {
                    std::cout << "Ошибка: сначала задайте первую строку через пункт 1.\n";
                    break;
                }

                std::cout << "Присваивание с перемещением через оператор `=`...\n";

                str2 = std::move(str1); // Присваивание с перемещением

                std::cout << "Результат перемещения во второй строке: ";
                str2.Print();

                // Проверяем, что str1 пустой после перемещения
                std::cout << "Состояние первой строки после перемещения: ";
                str1.Print();
                break;
            }
            case 4: {
                if (str2() == 0) {
                    std::cout << "Ошибка: сначала задайте вторую строку через пункт 1.\n";
                    break;
                }

                std::cout << "Длина строки str2 через функтор (): " << str2() << " символов.\n";
                break;
            }
            case 5: {
                std::cout << "Завершение программы.\n";
                return 0;
            }
            default:
                std::cout << "Неверный выбор. Попробуйте ещё раз.\n";
        }
    }
    return 0;
}
}