#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
namespace Matrix {
class Point {
public:
    int row;
    int col;

    Point(int r = 0, int c = 0) : row(r), col(c) {}
};

class Matrix {
private:
    int rows;
    int cols;
    int** data;

public:

    Matrix(int r = 0, int c = 0);

    ~Matrix();

    void setElement(const Point& point, int value);

    int getElement(const Point& point) const;

    void inputMatrix();

    void displayMatrix() const;

    bool hasAlternatingSigns(int row) const;

    void findAlternatingSignRows() const;
};
int run();
}
#endif MATRIX_H