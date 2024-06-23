#include "./MainTest.h"

TEST(OperatorParentheses, MatrixsetterWrongIndexes) {
  S21Matrix matrix_a(2, 2);
  EXPECT_THROW(matrix_a(3, 0) = 1, std::logic_error);
}

TEST(eqMatrix, NonEqMatrix) {
  S21Matrix matrix_a(1, 3);
  matrix_a(0, 0) = 1;
  matrix_a(0, 1) = 2;
  matrix_a(0, 2) = 3;
  S21Matrix matrix_b(2, 2);
  matrix_b(0, 0) = 1;
  matrix_b(0, 1) = 2;
  matrix_b(1, 0) = 3;
  matrix_b(1, 1) = 4;
  ASSERT_FALSE(matrix_a == matrix_b);
}

TEST(OperatorEqal, Invalid) {
  S21Matrix matrix_a(2, 1);
  S21Matrix matrix_b;

  EXPECT_THROW(matrix_a = matrix_b, std::logic_error);
}

TEST(OperatorSumMatrix, OperatorSumWithNoEqSizesMatrix) {
  S21Matrix matrix_a(1, 2);
  S21Matrix matrix_b(2, 2);

  matrix_a(0, 0) = 1;
  matrix_a(0, 1) = 2;

  matrix_b(0, 0) = 1;
  matrix_b(0, 1) = 2;
  matrix_b(1, 0) = 3;
  matrix_b(1, 1) = 4;

  EXPECT_THROW(matrix_a += matrix_b, std::logic_error);
}

TEST(SimpleMathOperations, SumMatrix1) {
  auto test1 = S21Matrix(2, 2);
  auto test_res = S21Matrix(2, 2);
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      test1(i, j) = 1;
      test_res(i, j) = 2;
    }
  }
  auto test2 = test1;
  test1 = (test1 + test2);
  EXPECT_EQ(test1, test_res);
}

TEST(OperatorSubMatrix, False) {
  S21Matrix matrix_a(1, 2);
  S21Matrix matrix_b(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;

  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3;
  matrix_b(1, 1) = 2;

  EXPECT_THROW(matrix_a -= matrix_b, std::logic_error);
}

TEST(SimpleMathOperations, SubMatrix1) {
  auto test1 = S21Matrix(1, 1);
  test1(0, 0) = 1;
  auto test2 = test1;
  test1 = test1 - test2;
  EXPECT_EQ(test1(0, 0), 0);
}

TEST(SimpleMathOperations, MulNumber1) {
  auto test1 = S21Matrix(1, 1);
  test1(0, 0) = 1;
  auto test2 = test1;
  test1 = (test1 * 0);
  EXPECT_EQ(test1(0, 0), 0);
}

TEST(OperatorMulMatrix, MulNumber2) {
  auto test1 = S21Matrix(1, 1);
  test1(0, 0) = 1;
  auto test2 = test1;
  test1 *= 2;
  EXPECT_EQ(test1(0, 0), 2);
}

TEST(SimpleMathOperations, MulMatrix2) {
  auto test1 = S21Matrix(3, 3);
  for (int i = 0; i < test1.getRows(); i++) {
    for (int j = 0; j < test1.getCols(); j++) {
      test1(i, j) = test1.getRows() * i + j + 1;
    }
  }
  auto test2 = test1;
  test1 = test1 * test2;

  test2(0, 0) = 30;
  test2(0, 1) = 36;
  test2(0, 2) = 42;
  test2(1, 0) = 66;
  test2(1, 1) = 81;
  test2(1, 2) = 96;
  test2(2, 0) = 102;
  test2(2, 1) = 126;
  test2(2, 2) = 150;
  EXPECT_EQ(test1, test2);
}

TEST(OperatorMulMatrix2, False) {
  S21Matrix matrix_a(2, 1);
  S21Matrix matrix_b(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(1, 0) = -6.6;

  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3.5;
  matrix_b(1, 1) = 2;

  EXPECT_THROW(matrix_a *= matrix_b, std::logic_error);
}

TEST(SimpleMathOperations, MulMatrix1) {
  auto test1 = S21Matrix(3, 3);
  for (int i = 0; i < test1.getRows(); i++) {
    for (int j = 0; j < test1.getCols(); j++) {
      test1(i, j) = test1.getRows() * i + j + 1;
    }
  }
  auto test2 = test1;
  test1 *= test2;

  test2(0, 0) = 30;
  test2(0, 1) = 36;
  test2(0, 2) = 42;
  test2(1, 0) = 66;
  test2(1, 1) = 81;
  test2(1, 2) = 96;
  test2(2, 0) = 102;
  test2(2, 1) = 126;
  test2(2, 2) = 150;
  EXPECT_EQ(test1, test2);
}