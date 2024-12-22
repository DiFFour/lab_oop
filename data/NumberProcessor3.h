#ifndef NUMBER_PROCESSOR3_H
#define NUMBER_PROCESSOR3_H
namespace NP {
class NumberProcessor {
private:
    double* numbers; // Указатель на массив чисел
    int size; // Размер массива

public:
    // Конструктор для инициализации с переданным массивом и его размером
    NumberProcessor(double* nums, int s);

    // Деструктор для освобождения памяти
    ~NumberProcessor();

    // Метод для вычисления суммы положительных чисел после нечетных отрицательных
    double calculateSum();
};
int run();
}
#endif // NUMBER_PROCESSOR3_H
