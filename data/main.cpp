#include <iostream>
#include "STRING71.h"
#include "Manip72.h"
#include "SequenceHandler6.h"
#include "STRING5.h"
#include "NumberProcessor3.h"
#include "Matrix2.h"
#include "STRING1.h"
#include "STRING4.h"

int main() {

    int choice{ 0 };
    while (true) {
        std::cout << "\n\nВыберите проект:\n";
        std::cout << "1. КЛАССЫ. КОНСТРУКТОРЫ. ДЕСТРУКТОРЫ\n";
        std::cout << "2. ИСПОЛЬЗОВАНИЕ УКАЗАТЕЛЕЙ В C++\n";
        std::cout << "3. ДИНАМИЧЕСКОЕ СОЗДАНИЕ ЭКЗЕМПЛЯРОВ. ИСПОЛЬЗОВАНИЕ ОПЕРАЦИЙ NEW, DELETE\n";
        std::cout << "4. НАСЛЕДОВАНИЕ. ВИРТУАЛЬНЫЕ ФУНКЦИИ\n";
        std::cout << "5. ПЕРЕГРУЗКА ОПЕРАТОРОВ. ПЕРЕГРУЗКА ФУНКЦИЙ\n";
        std::cout << "6. ШАБЛОНЫ КЛАССОВ И ФУНКЦИЙ\n";
        std::cout << "7. ПОТОКОВЫЙ ВВОД/ВЫВОД ч.1\n";
        std::cout << "8. ПОТОКОВЫЙ ВВОД/ВЫВОД ч.2\n";
        std::cout << "0. Выход\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                STRING1::run(); // Вызываем функцию run()
            break;
            case 2:
                Matrix::run(); // Вызываем функцию run()
            break;
            case 3:
                NP::run(); // Вызываем функцию run()
            break;
            case 4:
                STRING4::run(); // Вызываем функцию run()
            break;
            case 5:
                STRING5::run(); // Вызываем функцию run()
            break;
            case 6:
                Print6::run(); // Вызываем функцию run()
            break;
            case 71:
                STRING71::run(); // Вызываем функцию run()
            break;
            case 72:
                Manip72::run(); // Вызываем функцию run()
            break;
            case 0:
                std::cout << "Выход из программы\n";
            return 0;
            default:
                std::cout << "Некорректный выбор. Повторите попытку.\n";
        }
    }
}
