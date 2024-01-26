#include <gtest/gtest.h>
#include "image/mat.h"
#include "image/operations.h"

// Define a fixture for the tests
class OperationsTest : public ::testing::Test {
protected:
    // Helper function to compare two matrices
    template<class T>
    bool areMatricesEqual(Mat<T> mat1, Mat<T> mat2) {
        if (mat1.rows != mat2.rows || mat1.cols != mat2.cols) {
            return false;
        }

        for (int i = 0; i < mat1.rows; ++i) {
            for (int j = 0; j < mat1.cols; ++j) {
                if (mat1.at(i, j) != mat2.at(i, j)) {
                    return false;
                }
            }
        }

        return true;
    }
};

// Test case for normal operation
TEST_F(OperationsTest, Convolution2D_NormalOperation) {
    Mat<unsigned char> input(3, 3);
    input.set(0, 0, 1); input.set(0, 1, 2); input.set(0, 2, 3);
    input.set(1, 0, 4); input.set(1, 1, 5); input.set(1, 2, 6);
    input.set(2, 0, 7); input.set(2, 1, 8); input.set(2, 2, 9);

    Mat<int> x_kernel(3, 3);
    x_kernel.set(0, 0, -1); x_kernel.set(0, 1, 0); x_kernel.set(0, 2, 1);
    x_kernel.set(1, 0, -2); x_kernel.set(1, 1, 0); x_kernel.set(1, 2, 2);
    x_kernel.set(2, 0, -1); x_kernel.set(2, 1, 0); x_kernel.set(2, 2, 1);

    Mat<int> y_kernel(3, 3);
    y_kernel.set(0, 0, -1); y_kernel.set(0, 1, -2); y_kernel.set(0, 2, -1);
    y_kernel.set(1, 0, 0); y_kernel.set(1, 1, 0); y_kernel.set(1, 2, 0);
    y_kernel.set(2, 0, 1); y_kernel.set(2, 1, 2); y_kernel.set(2, 2, 1);

    Mat<unsigned char> expected_output(3, 3);
    expected_output.set(0, 0, 15); expected_output.set(0, 1, 20); expected_output.set(0, 2, 19);
    expected_output.set(1, 0, 26); expected_output.set(1, 1, 25); expected_output.set(1, 2, 26);
    expected_output.set(2, 0, 24); expected_output.set(2, 1, 20); expected_output.set(2, 2, 27);

    Mat<unsigned char> result = convolution2D(input, x_kernel, y_kernel);
    ASSERT_TRUE(areMatricesEqual(result, expected_output));
}

// Test case for edge cases (empty matrices)
TEST_F(OperationsTest, Convolution2D_EmptyMatrices) {
    Mat<unsigned char> input(0, 0);
    Mat<int> x_kernel(0, 0);
    Mat<int> y_kernel(0, 0);

    Mat<unsigned char> result = convolution2D(input, x_kernel, y_kernel);

    ASSERT_EQ(result.rows, 0);
    ASSERT_EQ(result.cols, 0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
