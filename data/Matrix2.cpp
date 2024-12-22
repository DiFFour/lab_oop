#include "Matrix2.h"
namespace Matrix {
// Конструктор: выделение динамической памяти
Matrix::Matrix(int r, int c) : rows(r), cols(c), data(nullptr) {
    if (rows > 0 && cols > 0) {
        data = new int*[rows]; // Выделяем память для массива строк
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols]; // Для каждой строки выделяем память под массив столбцов
        }
    }
}

// Деструктор: освобождение памяти
Matrix::~Matrix() {
    if (data != nullptr) {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i]; // Удаляем динамически выделенную память массива строк
        }
        delete[] data; // Удаляем массив указателей
    }
}

// Метод для установки значений
void Matrix::setElement(const Point& point, int value) {
    if (point.row >= 0 && point.row < rows && point.col >= 0 && point.col < cols) {
        data[point.row][point.col] = value;
    } else {
        std::cerr << "Ошибка: индекс выходит за пределы матрицы!" << std::endl;
    }
}

// Метод для получения значений
int Matrix::getElement(const Point& point) const {
    if (point.row >= 0 && point.row < rows && point.col >= 0 && point.col < cols) {
        return data[point.row][point.col];
    } else {
        std::cerr << "Ошибка: индекс выходит за пределы матрицы!" << std::endl;
        return 0;
    }
}

// Ввод элементов матрицы
void Matrix::inputMatrix() {
    std::cout << "Введите элементы матрицы (" << rows << "x" << cols << "):" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "Элемент [" << i << "][" << j << "]: ";
            std::cin >> data[i][j];
        }
    }
}

// Вывод матрицы
void Matrix::displayMatrix() const {
    std::cout << "Матрица:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << data[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

// Проверка строки на чередование знаков
bool Matrix::hasAlternatingSigns(int row) const {
    if (row < 0 || row >= rows) return false; // Проверка корректности индекса
    for (int j = 0; j < cols - 1; ++j) {
        if (data[row][j] * data[row][j + 1] >= 0) { // Условие для чередования знаков
            return false;
        }
    }
    return true;
}

// Поиск строк с чередующимися знаками
void Matrix::findAlternatingSignRows() const {
    bool found = false;
    for (int i = 0; i < rows; ++i) {
        if (hasAlternatingSigns(i)) {
            found = true;
            std::cout << "Строка номер " << i << " имеет чередующиеся знаки. Адрес строки: " << static_cast<const void*>(data[i]) << std::endl;
        }
    }
    if (!found) {
        std::cout << "Нет строк с чередующимися знаками." << std::endl;
    }
}
}
