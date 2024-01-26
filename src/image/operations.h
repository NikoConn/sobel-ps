// operations.h
#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "mat.h"

Mat<unsigned char> convolution2D(Mat<unsigned char> input, Mat<int> x_kernel, Mat<int> y_kernel);

#endif // OPERATIONS_H
