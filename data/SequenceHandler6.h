#ifndef SEQUENCE_HANDLER_H
#define SEQUENCE_HANDLER_H

#include <iostream>
#include <limits>
namespace Print6 {
template <typename T>
class SequenceHandler {
public:
    SequenceHandler();
    ~SequenceHandler();

    void inputSequence();
    void handleSequence();

private:
    T* data;    // Указатель на массив данных
    size_t size;

    bool isDescending() const;  // Проверяем упорядоченность массива
    void reverse();             // Реализация переворота массива
    void printData() const;     // Выводим массив на экран
};

// Конструктор
template <typename T>
SequenceHandler<T>::SequenceHandler() : data(nullptr), size(0) {}

// Деструктор
template <typename T>
SequenceHandler<T>::~SequenceHandler() {
    delete[] data; // Освобождаем память
}

// Метод для ввода данных
template <typename T>
void SequenceHandler<T>::inputSequence() {
    std::cout << "Введите количество элементов последовательности: ";
    while (!(std::cin >> size) || size <= 0) {
        std::cout << "Ошибка: Размер последовательности должен быть положительным числом! Попробуйте снова: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Создаем динамический массив
    data = new T[size];

    std::cout << "Введите " << size << " элементов последовательности:\n";
    for (size_t i = 0; i < size; ++i) {
        while (!(std::cin >> data[i])) { // Проверяем корректность ввода числа
            std::cout << "Ошибка: Введите число! Попробуйте снова: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

// Метод для обработки данных
template <typename T>
void SequenceHandler<T>::handleSequence() {
    if (size <= 0) {
        std::cout << "Нет данных для обработки.\n";
        return;
    }

    if (isDescending()) {
        std::cout << "Последовательность упорядочена по убыванию. Изменений не требуется.\n";
    } else {
        reverse(); // Переворачиваем массив
        std::cout << "Последовательность не упорядочена. Перевернутая последовательность:\n";
    }
    printData();
}

// Метод для проверки упорядоченности
template <typename T>
bool SequenceHandler<T>::isDescending() const {
    for (size_t i = 1; i < size; ++i) {
        if (data[i] > data[i - 1]) {
            return false;
        }
    }
    return true;
}

// Метод для переворачивания массива
template <typename T>
void SequenceHandler<T>::reverse() {
    for (size_t i = 0; i < size / 2; ++i) {
        T temp = data[i];
        data[i] = data[size - i - 1];
        data[size - i - 1] = temp;
    }
}

// Метод для вывода массива
template <typename T>
void SequenceHandler<T>::printData() const {
    for (size_t i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}
int run();
}
#endif
