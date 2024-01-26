// operations.h
#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "mat.h"

Mat<unsigned char> convolution2D(Mat<unsigned char> input, Mat<int> x_kernel, Mat<int> y_kernel);
Mat<unsigned char> sobel(Mat<unsigned char> image, int x_order, int y_order, int aperture_size = 3);

#endif // OPERATIONS_H
