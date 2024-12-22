#include <iostream>
#include <cstdio>
#include <cstring>

#define MAX_LENGTH 256
namespace STRING1 {
    class STRING {
    private:
        char buf[MAX_LENGTH + 1] = {0};  // Хранение строки (статический массив)
        unsigned len = 0;               // Длина строки

        // Вспомогательная функция для вычисления длины строки
        unsigned strLength(const char* str) const;
        // Вспомогательная функция для копирования строки
        void strCopy(char* dest, const char* src) const;
        // Вспомогательная функция для сравнения строк
        int strCompare(const char* str1, const char* str2) const;

    public:
        // Конструктор для инициализации строкой
        STRING(const char* what = "");
        // Перемещающий конструктор
        STRING(STRING&& what) noexcept;
        // Деструктор
        ~STRING();

        // Методы
        void Setstr(const char* what);
        void Setstr(const STRING& strObj);
        unsigned Strcmp(const STRING& s2) const; // Сравнение строк
        void Print() const;

        // Перегрузка операторов
        STRING& operator=(STRING&& rhs) noexcept; // Перемещающее присваивание
        STRING operator+(const STRING& rhs) const; // Конкатенация строк
        unsigned operator()() const;               // Функтор: возвращает длину строки
    };
    int run();
}