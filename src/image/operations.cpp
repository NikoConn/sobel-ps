#include <stdexcept>
#include "operations.h"
#include "math.h"

/**
 * Applies a 2D convolution to the input image using the specified X and Y kernels.
 * The convolution results in the gradient magnitude at each pixel, combining both X and Y gradients.
 *
 * @param input        The input image (grayscale) to be convolved.
 * @param x_kernel     The X-axis convolution kernel.
 * @param y_kernel     The Y-axis convolution kernel.
 *
 * @return             A new image representing the gradient magnitude after convolution.
*/
Mat<unsigned char> convolution2D(Mat<unsigned char> input, Mat<int> x_kernel, Mat<int> y_kernel) {
    int rows = input.rows;
    int cols = input.cols;

    int kernel_rows = x_kernel.rows;
    int kernel_cols = x_kernel.cols;

    int half_kernel_rows = kernel_rows / 2;
    int half_kernel_cols = kernel_cols / 2;

    Mat<unsigned char> output(rows, cols);

    //Iterate over each pixel instead of each row or column in case the image is highly unbalanced.
    //must skip first and last column and row
    #pragma omp parallel for
    for (int i = 1; i < rows * cols - 2 * cols; i++){
        int row = i / cols + 1;
        int column = i % (cols - 2) + 1;

        int x_gradient = 0;
        int y_gradient = 0;

        for (int kernel_row = 0; kernel_row < kernel_rows; kernel_row++) {
            for (int kernel_column = 0; kernel_column < kernel_cols; kernel_column++) {
                int image_row = kernel_row - half_kernel_rows + row;
                int image_col =  kernel_column - half_kernel_cols + column;

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

/**
 * Applies the Sobel operator to the input image to calculate the gradient in both the X and Y directions.
 * The Sobel operator uses convolution with specified derivative orders and aperture size.
 *
 * @param image         The input image (grayscale) to which the Sobel operator is applied.
 * @param x_order       The order of the derivative in the X direction (usually -1, 0, or 1).
 * @param y_order       The order of the derivative in the Y direction (usually -1, 0, or 1).
 * @param aperture_size The size of the convolution kernel aperture (must be an odd number >= 3 and <= 7).
 *
 * @return              A new image representing the combined gradient calculated using the Sobel operator.
*/
Mat<unsigned char> sobel(Mat<unsigned char> image, int x_order, int y_order, int aperture_size) {
    if (aperture_size < 3 || aperture_size > 7 || aperture_size % 2 != 1) {
        throw std::invalid_argument("aperture_size must be an odd number between 3 and 7");
    }

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

