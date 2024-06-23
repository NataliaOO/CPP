#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

S21Matrix::S21Matrix(int rows, int cols)
    : rows_(rows), cols_(cols), matrix_(nullptr) {
  if (rows <= 0 || cols <= 0) {
    throw std::invalid_argument(
        "Number of rows and columns must be greater than zero.");
  }
  allocateMemory(rows, cols);
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(nullptr) {
  allocateMemory(rows_, cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.cols_ = 0;
  other.rows_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() { deallocateMemory(); }

int S21Matrix::getRows() const { return rows_; }

int S21Matrix::getCols() const { return cols_; }

void S21Matrix::setCols(int cols) {
  if (cols <= 0) {
    throw std::length_error("Number of columns must be greater than zero.");
  }
  if (cols != cols_) {
    resizeMatrix(rows_, cols);
  }
}

void S21Matrix::setRows(int rows) {
  if (rows <= 0) {
    throw std::length_error("Number of rows must be greater than zero.");
  }
  if (rows != rows_) {
    resizeMatrix(rows, cols_);
  }
}

bool S21Matrix::isValid() const {
  return matrix_ != nullptr && cols_ > 0 && rows_ > 0;
}

bool S21Matrix::EqMatrix(const S21Matrix& other) const {
  if (!other.isValid() || !this->isValid()) {
    throw std::length_error("Matrix is ​​empty");
  }
  if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
    return false;
  }
  const double tolerance = 1e-7;
  for (int i = 0; i < this->rows_; ++i) {
    for (int j = 0; j < this->cols_; ++j) {
      if (std::fabs(this->matrix_[i][j] - other.matrix_[i][j]) > tolerance) {
        return false;
      }
    }
  }
  return true;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (!other.isValid() || !this->isValid()) {
    throw std::length_error("Matrix is ​​empty");
  }
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument(
        "Matrices must have the same dimensions to be summed.");
  }

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (!other.isValid() || !this->isValid()) {
    throw std::length_error("Matrix is ​​empty");
  }
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument(
        "Matrices must have the same dimensions for subtraction.");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  if (!this->isValid()) {
    throw std::logic_error("Matrix is uninitialized or invalid.");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (!other.isValid() || !this->isValid()) {
    throw std::logic_error("Matrix is uninitialized or invalid.");
  }
  if (cols_ != other.rows_) {
    throw std::invalid_argument(
        "Number of columns of the first matrix must be equal to the number of "
        "rows of the second matrix.");
  }
  S21Matrix result(rows_, other.cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < other.cols_; ++j) {
      result.matrix_[i][j] = 0.0;
      for (int k = 0; k < cols_; ++k) {
        result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  *this = std::move(result);
}

// Operator Overloading
double& S21Matrix::operator()(int i, int j) {
  if (i >= rows_ || j >= cols_ || i < 0 || j < 0) {
    throw std::out_of_range("Index out of range");
  }
  return matrix_[i][j];
}

bool S21Matrix::operator==(const S21Matrix& other) const {
  return EqMatrix(other);
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  this->SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  this->SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double num) {
  this->MulNumber(num);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  this->MulMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  S21Matrix result(*this);
  result.SumMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  S21Matrix result(*this);
  result.SubMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const double num) const {
  S21Matrix result(*this);
  result.MulNumber(num);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  S21Matrix result(*this);
  result.MulMatrix(other);
  return result;
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this != &other) {
    if (other.rows_ <= 0 || other.cols_ <= 0) {
      throw std::logic_error(
          "Cannot assign from an uninitialized or invalid matrix.");
    }
    deallocateMemory();
    rows_ = other.rows_;
    cols_ = other.cols_;
    allocateMemory(rows_, cols_);
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        matrix_[i][j] = other.matrix_[i][j];
      }
    }
  }
  return *this;
}

void S21Matrix::allocateMemory(int rows, int cols) {
  matrix_ = new double*[rows];
  for (int i = 0; i < rows; ++i) {
    matrix_[i] = new double[cols]();
  }
}

void S21Matrix::deallocateMemory() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; ++i) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
    matrix_ = nullptr;
  }
}

void S21Matrix::resizeMatrix(int new_rows, int new_cols) {
  double** new_matrix = new double*[new_rows];
  for (int i = 0; i < new_rows; ++i) {
    new_matrix[i] = new double[new_cols]();
    if (i < rows_) {
      for (int j = 0; j < std::min(cols_, new_cols); ++j) {
        new_matrix[i][j] = matrix_[i][j];
      }
    }
  }
  deallocateMemory();
  matrix_ = new_matrix;
  rows_ = new_rows;
  cols_ = new_cols;
}

S21Matrix S21Matrix::Transpose() {
  if (!this->isValid()) {
    throw std::length_error("Matrix is ​​empty");
  }
  S21Matrix result(cols_, rows_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      result.matrix_[j][i] = matrix_[i][j];
    }
  }
  return result;
}

double S21Matrix::Determinant() {
  if (!this->isValid()) {
    throw std::length_error("Matrix is ​​empty");
  }
  if (rows_ != cols_) {
    throw std::invalid_argument(
        "Matrix must be square to calculate the determinant.");
  }
  if (rows_ == 1) {
    return matrix_[0][0];
  }
  if (rows_ == 2) {
    return matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  }
  double det = 0.0;
  for (int i = 0; i < cols_; ++i) {
    S21Matrix minor = getMinor(0, i);
    det += (i % 2 == 0 ? 1 : -1) * matrix_[0][i] * minor.Determinant();
  }
  return det;
}

S21Matrix S21Matrix::CalcComplements() {
  if (!this->isValid()) {
    throw std::length_error("Matrix is ​​empty");
  }
  if (rows_ != cols_ || (rows_ < 2 && cols_ < 2)) {
    throw std::invalid_argument(
        "The matrix must be square to calculate additions and the size is "
        "greater than 1.");
  }
  S21Matrix result(rows_, cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      S21Matrix minor = getMinor(i, j);
      result.matrix_[i][j] = std::pow(-1, i + j) * minor.Determinant();
    }
  }

  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  if (!this->isValid()) {
    throw std::length_error("Matrix is ​​empty");
  }
  if (rows_ != cols_) {
    throw std::invalid_argument(
        "Matrix must be square to calculate its inverse.");
  }
  double det = Determinant();
  if (det == 0) {
    throw std::invalid_argument(
        "Matrix with zero determinant does not have an inverse.");
  }
  S21Matrix cofactors = CalcComplements();
  S21Matrix adjugate = cofactors.Transpose();
  adjugate.MulNumber(1.0 / det);
  return adjugate;
}

S21Matrix S21Matrix::getMinor(int row, int col) const {
  S21Matrix minor(rows_ - 1, cols_ - 1);
  int minorRow = 0;
  for (int i = 0; i < rows_; ++i) {
    if (i == row) continue;
    int minorCol = 0;
    for (int j = 0; j < cols_; ++j) {
      if (j == col) continue;
      minor.matrix_[minorRow][minorCol] = matrix_[i][j];
      minorCol++;
    }
    minorRow++;
  }
  return minor;
}