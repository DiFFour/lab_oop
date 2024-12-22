#include <iostream>
#include "NumberProcessor3.h"
namespace NP {
int run() {
    int N;
    std::cout << "Введите количество чисел (N): ";
    std::cin >> N;

    if (N <= 0) {
        std::cout << "Количество чисел должно быть положительным." << std::endl;
        return 1; // Выход из программы при некорректном вводе
    }

    double* numbers = new double[N]; // Выделяем память под массив

    // Ввод чисел
    std::cout << "Введите " << N << " действительных чисел:" << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cin >> numbers[i];
    }

    // Создаем объект класса NumberProcessor
    NumberProcessor processor(numbers, N);

    // Вычисляем сумму и выводим результат
    double sum = processor.calculateSum();
    std::cout << "Сумма положительных чисел, стоящих после нечетных отрицательных чисел: " << sum << std::endl;

    delete[] numbers; // Освобождаем память под исходный массив

    return 0;
}
}