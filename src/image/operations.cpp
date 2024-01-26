#include "operations.h"
#include "math.h"

Mat<unsigned char> convolution2D(Mat<unsigned char> input, Mat<int> x_kernel, Mat<int> y_kernel) {
    int rows = input.rows;
    int cols = input.cols;

    int kernel_rows = x_kernel.rows;
    int kernel_cols = x_kernel.cols;

    int half_kernel_rows = kernel_rows / 2;
    int half_kernel_cols = kernel_cols / 2;

    Mat<unsigned char> output(rows, cols);

    #pragma omp parallel for
    for (int i = 0; i < rows * cols; i++){
        int row = i / cols;
        int column = i % cols;

        int x_gradient = 0;
        int y_gradient = 0;

        for (int kernel_row = 0; kernel_row < kernel_rows; kernel_row++) {
            for (int kernel_column = 0; kernel_column < kernel_cols; kernel_column++) {
                int image_row = kernel_row - half_kernel_rows + row;
                int image_col =  kernel_column - half_kernel_cols + column;

                if (image_row < 0 || image_row >= rows || image_col < 0 || image_col >= cols) {
                    continue;
                }

                int x_kernel_value = x_kernel.at(kernel_row, kernel_column);
                int y_kernel_value = y_kernel.at(kernel_row, kernel_column);

                unsigned char image_value = input.at(image_row, image_col);

                x_gradient += x_kernel_value * image_value;
                y_gradient += y_kernel_value * image_value;
            }
        }
        output.set(row, column, sqrt(x_gradient * x_gradient + y_gradient * y_gradient));
    }

    return output;
}

Mat<unsigned char> sobel(Mat<unsigned char> image, int x_order, int y_order, int aperture_size) {
    Mat<int> x_kernel(aperture_size, aperture_size);
    Mat<int> y_kernel(aperture_size, aperture_size);

    int center = aperture_size / 2;

    for (int i = 0; i < aperture_size; i++) {
        for (int j = 0; j < aperture_size; j++) {
            x_kernel.set(i, j, (j - center) * pow(-1, i) * x_order);
            y_kernel.set(i, j, (i - center) * pow(-1, j) * y_order);
        }
    }

    return convolution2D(image, x_kernel, y_kernel);
}

