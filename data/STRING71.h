#ifndef STRING71_H
#define STRING71_H

#include <iostream>

namespace STRING71 {
    class STRING {
    public:
        static const unsigned MAX_LENGTH = 255; // Максимальная длина строки

        STRING();                               // Конструктор по умолчанию
        STRING(const char* what);               // Конструктор с инициализацией строкой
        STRING(const STRING& what);             // Копирующий конструктор

        void Setstr(const char* what);          // Метод для изменения строки
        unsigned Strcmp(const STRING& s2) const;// Метод для сравнения строк
        void Print() const;                     // Метод для вывода строки на экран

        friend std::ostream& operator<<(std::ostream& os, const STRING& str); // Оператор вывода
        friend std::istream& operator>>(std::istream& is, STRING& str);       // Оператор ввода

        ~STRING();                              // Деструктор

    private:
        char buf[MAX_LENGTH + 1];               // Буфер для хранения строки
        unsigned len;                           // Длина строки

        unsigned strLength(const char* str) const;  // Метод вычисления длины строки
        void strCopy(char* dest, const char* src) const; // Метод копирования строки
        int strCompare(const char* str1, const char* str2) const; // Метод сравнения строк
    };

    void run(); // Объявление функции run()
}

#endif // STRING71_H
