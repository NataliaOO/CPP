#include "./MainTest.h"

TEST(CreateMatrix, StandartConstructor) {
  S21Matrix matrix_a;
  ASSERT_TRUE(matrix_a.getCols() == 0);
  ASSERT_TRUE(matrix_a.getRows() == 0);
}

TEST(CreateMatrix, ParamConstr) { ASSERT_NO_THROW(S21Matrix matrix(2, 2)); }

TEST(CreateMatrix, ParamConstWithWrongSizes) {
  EXPECT_THROW(S21Matrix matrix(-1, 2), std::invalid_argument);
}

TEST(CreateMatrix, MoveConstr) {
  S21Matrix matrix_a(2, 2);
  ASSERT_NO_THROW(S21Matrix matrix_b = std::move(matrix_a));
}

TEST(CreateMatrix, CopyConstr) {
  S21Matrix matrix_a(2, 2);
  ASSERT_NO_THROW(S21Matrix matrix_b(matrix_a));
}

TEST(Technical, getRows) {
  auto test1 = S21Matrix();
  EXPECT_EQ(test1.getRows(), 0);
  auto test2 = S21Matrix(2, 2);
  EXPECT_EQ(test2.getRows(), 2);
}

TEST(Technical, getCols) {
  auto test1 = S21Matrix();
  EXPECT_EQ(test1.getCols(), 0);
  auto test2 = S21Matrix(2, 2);
  EXPECT_EQ(test2.getCols(), 2);
}

TEST(Technical, setRows) {
  auto test1 = S21Matrix(1, 1);
  test1.setRows(5);
  EXPECT_EQ(test1.getRows(), 5);
}

TEST(Technical, setRows1) {
  auto test1 = S21Matrix(1, 1);
  EXPECT_THROW(test1.setRows(-1), std::length_error);
}

TEST(Technical, setCols) {
  auto test1 = S21Matrix(1, 1);
  test1.setCols(5);
  EXPECT_EQ(test1.getCols(), 5);
}

TEST(Technical, setCols1) {
  auto test1 = S21Matrix(1, 1);
  EXPECT_THROW(test1.setCols(0), std::length_error);
}

TEST(Constructor, Default) {
  auto test = S21Matrix();
  EXPECT_EQ(test.getRows(), 0);
  EXPECT_EQ(test.getCols(), 0);
}

TEST(Constructor, By2Args) {
  auto test = S21Matrix(3, 3);
  EXPECT_EQ(test.getRows(), 3);
  EXPECT_EQ(test.getCols(), 3);
}

TEST(Constructor, Copy) {
  auto test = S21Matrix(3, 3);
  test(0, 0) = 1;
  auto temp = S21Matrix(test);
  EXPECT_EQ(test, temp);
}

TEST(Constructor, Move) {
  auto test1 = S21Matrix(3, 3);
  test1(1, 1) = 5;
  auto test2 = S21Matrix(test1);
  auto test3 = S21Matrix(std::move(test1));
  EXPECT_EQ(test2, test3);
}