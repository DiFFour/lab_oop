#include "STRING4.h"
#include "STRING_INVERTED4.h"
#include <cstdio>
namespace STRING4 {
    int run() {
        // Создаем объект базового класса
        STRING str1("Hello");
        // Создаем объект производного класса
        STRING_INVERTED str2("World");
        // Выводим через метод базового класса
        printf("Вывод базового класса:\n");
        str1.Print();
        // Выводим через метод производного класса
        printf("Вывод производного класса:\n");
        str2.Print();
        // Демонстрируем полиморфизм
        printf("\nДемонстрация полиморфизма:\n");
        // Массив указателей на базовый класс
        STRING* strings[2];
        strings[0] = &str1;
        strings[1] = &str2;
        for (int i = 0; i < 2; ++i) {
            strings[i]->Print();
        }
        // Сравнение строк
        unsigned comparisonResult = str1.Strcmp(str2);
        printf("Результат сравнения между '%s' и '%s': %u\n", str1.c_str(), str2.c_str(), comparisonResult);
        // Изменяем строку в производном объекте
        str2.Setstr("C++");
        // Выводим снова
        printf("\nПосле изменения строки в производном объекте:\n");
        for (int i = 0; i < 2; ++i) {
            strings[i]->Print();
        }
        // Сравнение снова
        comparisonResult = str1.Strcmp(str2);
        printf("Результат сравнения между '%s' и '%s': %u\n", str1.c_str(), str2.c_str(), comparisonResult);
        return 0;
    }
}