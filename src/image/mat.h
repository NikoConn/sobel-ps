#ifndef MAT_H
#define MAT_H

#include "vector"

template<class T> class Mat
{
private:
    std::vector<std::vector<T>> data;
public:
    int rows, cols;

    Mat(int rows, int cols);

    T at(int row, int col);
    void set(int row, int col, T value);
};

#endif // MAT_H
