#include "STRING_INVERTED4.h"
namespace STRING4 {
    // Конструктор инициализирующий строкой
    STRING_INVERTED::STRING_INVERTED(const char* what) : STRING(what) {
        // Дополнительная инициализация не требуется
    }
    // Копирующий конструктор
    STRING_INVERTED::STRING_INVERTED (const STRING_INVERTED & what) : STRING(what) {
        // Дополнительное копирование не требуется, базовый класс уже это делает
    }
    // Переопределенный метод для вывода строки на экран (например, вывод в обратном порядке)
    void STRING_INVERTED::Print() const {
        for (int i = len - 1; i >= 0; --i) {
            std::printf("%c", buf[i]);
        }
        std::printf("\n");
    }

    // Переопределенный метод для доступа к строке
    const char* STRING_INVERTED::c_str() const {
        return buf;
    }
}