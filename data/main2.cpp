#include <iostream>
#include "Matrix2.h"
namespace Matrix {
int run() {
    int m, n;
    std::cout << "Введите количество строк матрицы: ";
    std::cin >> m;
    std::cout << "Введите количество столбцов матрицы: ";
    std::cin >> n;

    // Создание объекта матрицы
    Matrix matrix(m, n);
    matrix.inputMatrix();

    std::cout << "\nМатрица после ввода:\n";
    matrix.displayMatrix();

    // Установка значения элемента
    int row, col, value;
    std::cout << "\nУстановим значение элемента. Введите строку, столбец и значение: ";
    std::cin >> row >> col >> value;
    matrix.setElement(Point(row, col), value);

    std::cout << "\nМатрица после изменения элемента:\n";
    matrix.displayMatrix();

    // Получение значения элемента
    std::cout << "\nВведите строку и столбец для получения элемента: ";
    std::cin >> row >> col;
    std::cout << "Значение элемента [" << row << "][" << col << "]: "
              << matrix.getElement(Point(row, col)) << std::endl;

    // Проверка строк с чередующимися знаками
    std::cout << "\nРезультаты проверки чередующихся знаков:\n";
    matrix.findAlternatingSignRows();

    return 0;
}
}