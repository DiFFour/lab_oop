    #ifndef STRING4_H
#define STRING4_H

#include <cstdio>
#define MAX_LENGTH 256
namespace STRING4 {
    // Определяем максимальную длину строк

    class STRING {
    protected:
        char buf[MAX_LENGTH + 1]; // +1 для завершающего нуля
        unsigned len;
    public:
        // Конструктор инициализирующий строкой
        STRING(const char* what);
        // Копирующий конструктор
        STRING(const STRING& what);
        // Виртуальный деструктор
        virtual ~STRING();
        // Виртуальный метод для изменения строки
        virtual void Setstr(const char* what);
        // Виртуальный метод для сравнения строк
        virtual unsigned Strcmp(const STRING& s2) const;
        // Виртуальный метод для вывода строки на экран
        virtual void Print() const;
        // Публичный метод для доступа к строке
        virtual const char* c_str() const;

    protected:
        // Виртуальные вспомогательные методы
        virtual unsigned strLength(const char* str) const;
        virtual void strCopy(char* dest, const char* src) const;
        virtual int strCompare(const char* str1, const char* str2) const;
    };

    int run();
}

#endif // STRING4_H
