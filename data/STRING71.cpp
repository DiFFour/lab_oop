#include "STRING71.h"
#include <iostream>

namespace STRING71 {

/* Реализация конструктора по умолчанию */
STRING::STRING() {
    buf[0] = '\0';
    len = 0;
}

/* Реализация конструктора для инициализации строкой */
STRING::STRING(const char* what) {
    len = strLength(what);
    strCopy(buf, what);
}

/* Реализация копирующего конструктора */
STRING::STRING(const STRING& what) {
    len = what.len;
    strCopy(buf, what.buf);
}

/* Реализация метода для изменения строки */
void STRING::Setstr(const char* what) {
    len = strLength(what);
    strCopy(buf, what);
}

/* Реализация метода сравнения строк */
unsigned STRING::Strcmp(const STRING& s2) const {
    int cmp_result = strCompare(buf, s2.buf);
    if (cmp_result == 0) {
        return 1; /* Равно */
    }
    else if (cmp_result > 0) {
        return 2; /* Больше */
    }
    else {
        return 3; /* Меньше */
    }
}

/* Реализация метода для вывода строки на экран */
void STRING::Print() const {
    std::printf("%s\n", buf);
}

/* Реализация деструктора */
STRING::~STRING() {
    /* Не требуется освобождение памяти, так как используется статический массив */
}

/* Вспомогательный метод для вычисления длины строки */
unsigned STRING::strLength(const char* str) const {
    unsigned length = 0;
    while (str[length] != '\0' && length < MAX_LENGTH) {
        ++length;
    }
    return length;
}

/* Вспомогательный метод для копирования строки */
void STRING::strCopy(char* dest, const char* src) const {
    unsigned i = 0;
    while (i < MAX_LENGTH && src[i] != '\0') {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0'; // Убедиться, что строка завершена
}

/* Вспомогательный метод для сравнения строк */
int STRING::strCompare(const char* str1, const char* str2) const {
    while (*str1 && (*str1 == *str2)) {
        ++str1;
        ++str2;
    }
    return static_cast<unsigned char>(*str1) - static_cast<unsigned char>(*str2);
}

/* Оператор вывода */
std::ostream& operator<<(std::ostream& os, const STRING& str) {
    os << str.buf; // Выводим строку
    return os;     // Возвращаем поток
}

/* Оператор ввода */
std::istream& operator>>(std::istream& is, STRING& str) {
    char temp[STRING::MAX_LENGTH + 1];          // Временная строка для ввода
    is.getline(temp, STRING::MAX_LENGTH + 1);   // Читаем с ограничением длины
    str.Setstr(temp);                           // Устанавливаем строку в объекте
    return is;                                  // Возвращаем поток
}

}
