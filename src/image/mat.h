#ifndef MAT_H
#define MAT_H

#include "vector"

/**
 * @brief A template class representing a 2D matrix with elements of type T.
 *
 * The Mat class provides a simple and versatile container for 2D matrices,
 * allowing access, modification, and manipulation of individual elements.
 *
 * @tparam T The type of elements stored in the matrix.
 */
template<class T> class Mat
{
private:
    std::vector<std::vector<T>> data;
public:
    int rows, cols;

    /**
     * @brief Constructs a matrix with the specified number of rows and columns.
     *
     * @param rows The number of rows in the matrix.
     * @param cols The number of columns in the matrix.
    */
    Mat(int rows, int cols);

    /**
     * @brief Retrieves the value at the specified row and column in the matrix.
     *
     * @param row The row index of the element to retrieve.
     * @param col The column index of the element to retrieve.
     * @return The value at the specified position in the matrix.
     */
    T at(int row, int col);

    /**
     * @brief Sets the value at the specified row and column in the matrix.
     *
     * @param row   The row index of the element to set.
     * @param col   The column index of the element to set.
     * @param value The value to set at the specified position in the matrix.
     */
    void set(int row, int col, T value);
};

#endif // MAT_H
