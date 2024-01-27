#include "gtest/gtest.h"
#include "image/mat.h"

// Test fixture for Mat<int>
class MatIntTest : public ::testing::Test {
protected:
    Mat<int> matInt;

    MatIntTest() : matInt(3, 3) {}
};

// Test fixture for Mat<unsigned char>
class MatCharTest : public ::testing::Test {
protected:
    Mat<unsigned char> matChar;

    MatCharTest() : matChar(2, 2) {}
};

// Tests for Mat<int>
TEST_F(MatIntTest, Constructor) {
    EXPECT_EQ(matInt.rows, 3);
    EXPECT_EQ(matInt.cols, 3);
}

TEST_F(MatIntTest, SetAndGet) {
    matInt.set(0, 0, 1);
    matInt.set(1, 1, 2);
    matInt.set(2, 2, 3);

    EXPECT_EQ(matInt.at(0, 0), 1);
    EXPECT_EQ(matInt.at(1, 1), 2);
    EXPECT_EQ(matInt.at(2, 2), 3);
}

// Tests for Mat<unsigned char>
TEST_F(MatCharTest, Constructor) {
    EXPECT_EQ(matChar.rows, 2);
    EXPECT_EQ(matChar.cols, 2);
}

TEST_F(MatCharTest, SetAndGet) {
    matChar.set(0, 0, 1);
    matChar.set(1, 1, 2);

    EXPECT_EQ(matChar.at(0, 0), 1);
    EXPECT_EQ(matChar.at(1, 1), 2);
}

TEST(MatTests, OutOfBoundsAccess) {
    Mat<int> mat(2, 2);

    EXPECT_THROW(mat.at(2, 0), std::out_of_range);
}

