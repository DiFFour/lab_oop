#include "STRING5.h"
namespace STRING5 {
/* Реализация конструктора для инициализации строкой */
STRING::STRING(const char* what) {
    len = strLength(what);
    strCopy(buf, what);
}

/* Реализация перемещающего конструктора */
STRING::STRING(STRING&& what) noexcept {
    len = what.len;
    strCopy(buf, what.buf);
    what.len = 0;
    what.buf[0] = '\0';
}

/* Реализация перегрузки функции Setstr */
void STRING::Setstr(const char* what) {
    len = strLength(what);
    strCopy(buf, what);
}

void STRING::Setstr(const STRING& strObj) {
    len = strObj.len;
    strCopy(buf, strObj.buf);
}

/* Реализация перегрузки оператора присваивания (перемещение) */
STRING& STRING::operator=(STRING&& rhs) noexcept {
    if (this != &rhs) { /* Защита от самоприсваивания */
        len = rhs.len;
        strCopy(buf, rhs.buf);

        rhs.len = 0;
        rhs.buf[0] = '\0';
    }
    return *this;
}

/* Реализация перегрузки оператора сложения для конкатенации */
STRING STRING::operator+(const STRING& rhs) const {
    STRING newString("");
    unsigned totalLength = len + rhs.len;
    if (totalLength > MAX_LENGTH) {
        totalLength = MAX_LENGTH;
    }
    unsigned i = 0;

    /* Копируем текущую строку */
    for (; i < len && i < MAX_LENGTH; ++i) {
        newString.buf[i] = buf[i];
    }

    /* Конкатенируем вторую строку */
    for (unsigned j = 0; i < totalLength; ++i, ++j) {
        newString.buf[i] = rhs.buf[j];
    }
    newString.buf[totalLength] = '\0';
    newString.len = totalLength;

    return newString;
}

/* Реализация фуниктора (): возвращает длину строки */
unsigned STRING::operator()() const {
    return len;
}

/* Реализация метода сравнения строк */
unsigned STRING::Strcmp(const STRING& s2) const {
    int cmp_result = strCompare(buf, s2.buf);
    if (cmp_result == 0) {
        return 1; /* Равно */
    } else if (cmp_result > 0) {
        return 2; /* Больше */
    } else {
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
    while (*str++ && length < MAX_LENGTH) {
        ++length;
    }
    return length;
}

/* Вспомогательный метод для копирования строки */
void STRING::strCopy(char* dest, const char* src) const {
    unsigned i = 0;
    while (i < MAX_LENGTH && (dest[i] = src[i]) != '\0') {
        ++i;
    }
    dest[MAX_LENGTH] = '\0'; // Убедиться, что строка завершена
}

/* Вспомогательный метод для сравнения строк */
int STRING::strCompare(const char* str1, const char* str2) const {
    while (*str1 && (*str1 == *str2)) {
        ++str1;
        ++str2;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}
}