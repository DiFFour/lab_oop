#include "NumberProcessor3.h"
namespace NP {
// Реализация конструктора
NumberProcessor::NumberProcessor(double* nums, int s) {
    size = s;
    numbers = new double[size]; // Выделяем память под массив
    for (int i = 0; i < size; i++) {
        numbers[i] = nums[i]; // Копируем значения в массив
    }
}

// Реализация деструктора
NumberProcessor::~NumberProcessor() {
    delete[] numbers; // Освобождаем память
}

// Реализация метода для вычисления суммы положительных чисел после нечетных отрицательных
double NumberProcessor::calculateSum() {
    double sum = 0.0;

    for (int i = 0; i < size - 1; ++i) {
        // Проверяем, является ли текущее число нечетным отрицательным
        if (numbers[i] < 0 && static_cast<int>(numbers[i]) % 2 != 0) {
            // Если следующее число положительное, добавляем его к сумме
            if (numbers[i + 1] > 0) {
                sum += numbers[i + 1];
            }
        }
    }

    return sum;
}
}