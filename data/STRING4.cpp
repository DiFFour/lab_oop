#include "STRING4.h"
namespace STRING4 {
    // Конструктор инициализирующий строкой
    STRING::STRING(const char* what) {
        len = strLength(what);
        strCopy(buf, what);
    }
    // Копирующий конструктор
    STRING::STRING(const STRING& what) {
        len = what.len;
        strCopy(buf, what.buf);
    }
    // Метод для изменения строки
    void STRING::Setstr(const char* what) {
        len = strLength(what);
        strCopy(buf, what);
    }
    // Метод сравнения строк
    unsigned STRING::Strcmp(const STRING& s2) const {
        int cmp_result = strCompare(buf, s2.buf);
        if (cmp_result == 0) {
            return 1; // Равно
        }
        else if (cmp_result > 0) {
            return 2; // Больше
        }
        else {
            return 3; // Меньше
        }
    }
    // Метод для вывода строки на экран
    void STRING::Print() const {
        std::printf("%s\n", buf);
    }
    // Публичный метод для доступа к строке
    const char* STRING::c_str() const {
        return buf;
    }
    // Виртуальный деструктор
    STRING::~STRING() {
        // Освобождение памяти не требуется, поскольку используется статический массив
    }
    // Вспомогательный метод для вычисления длины строки
    unsigned STRING::strLength(const char* str) const {
        unsigned length = 0;
        while (*str++ && length < MAX_LENGTH) {
            ++length;
        }
        return length;
    }
    // Вспомогательный метод для копирования строки
    void STRING::strCopy(char* dest, const char* src) const {
        unsigned i = 0;
        while (i < MAX_LENGTH && (dest[i] = src[i]) != '\0') {
            ++i;
        }
        dest[MAX_LENGTH] = '\0'; // Убедиться, что строка завершена
    }
    // Вспомогательный метод для сравнения строк
    int STRING::strCompare(const char* str1, const char* str2) const {
        while (*str1 && (*str1 == *str2)) {
            ++str1;
            ++str2;
        }
        return static_cast<unsigned char>(*str1) - static_cast<unsigned char>(*str2);
    }
}