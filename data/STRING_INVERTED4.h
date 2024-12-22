#ifndef STRING_INVERTED_H
#define STRING_INVERTED_H
#include "STRING4.h"
namespace STRING4 {
    class STRING_INVERTED : public STRING {
    public:
        // Конструктор инициализирующий строкой
        STRING_INVERTED(const char* what);
        // Копирующий конструктор
        STRING_INVERTED(const STRING_INVERTED& what);
        // Переопределенный метод для вывода строки на экран
        virtual void Print() const override;
        // Переопределенный метод для доступа к строке (может быть добавлен при необходимости)
        virtual const char* c_str() const override;
    };
}
#endif // STRING_INVERTED_H
