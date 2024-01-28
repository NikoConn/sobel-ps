#include "opencv2/core.hpp"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "operations.h"
#include "mat.h"

/**
 * @brief Converts an OpenCV Mat object to a Mat<unsigned char> object.
 *
 * This function takes an OpenCV Mat object and creates a Mat<unsigned char> object
 * with the same dimensions and pixel values.
 *
 * @param mat The OpenCV Mat object to be converted.
 * @return A Mat<unsigned char> object representing the same image.
*/
Mat<unsigned char> cvMat2Mat(cv::Mat mat) {
    Mat<unsigned char> out(mat.rows, mat.cols);

    for (int i = 0; i < mat.rows * mat.cols; i++) {
        int row = i / mat.cols;
        int col = i % mat.cols;

        out.set(row, col, mat.at<unsigned char>(row, col));
    }

    return out;
}

/**
 * @brief Converts a Mat<unsigned char> object to an OpenCV Mat object.
 *
 * This function takes a Mat<unsigned char> object and creates an OpenCV Mat object
 * with the same dimensions and pixel values.
 *
 * @param mat The Mat<unsigned char> object to be converted.
 * @return An OpenCV Mat object representing the same image.
*/
cv::Mat Mat2cvMat(Mat<unsigned char> mat) {
    cv::Mat out(mat.rows, mat.cols, CV_8U);

    for (int i = 0; i < mat.rows * mat.cols; i++) {
        int row = i / mat.cols;
        int col = i % mat.cols;

        out.at<unsigned char>(row, col) = mat.at(row, col);
    }

    return out;
}


/**
 * @brief Main function to read an image, apply the Sobel operator, and save the result.
 *
 * This program takes as input the paths to an input image file and an output image file.
 * It reads the input image, converts it to grayscale, applies the Sobel operator, and saves
 * the resulting gradient image to the specified output file.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line argument strings.
 * @return An integer representing the exit status of the program.
*/
int main(int argc, char** argv) {
    char* input_file = argv[1];
    char* output_file = argv[2];

    cv::Mat img = cv::imread(input_file);
    cv::Mat gray;

    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

    Mat<unsigned char> mat = cvMat2Mat(gray);

    Mat<unsigned char> result = sobel(mat, 1, 1, 3);

    cv::Mat out = Mat2cvMat(result);
    cv::imwrite(output_file, out);
}
