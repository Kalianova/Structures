#include<matrixa/matrixa.h>
#include<exception>
#include<iostream>

MatrixA::MatrixA(const MatrixA& matrixa)
	:n_row_(matrixa.row_count()), n_col_(matrixa.col_count()) {
	data_ = std::make_unique<float[]>(n_row_ * n_col_);
	for (ptrdiff_t i = 0; i < n_row_ * n_col_; i++)
	{
		data_[i] = matrixa.data_[i];
	}
}

MatrixA::MatrixA(const std::ptrdiff_t col_count, const std::ptrdiff_t row_count)
	:n_col_(col_count), n_row_(row_count)
{
	if (col_count <= 0 || row_count <= 0) {
		throw std::invalid_argument("Row or colum < 0");
	}
	data_ = std::make_unique<float[]>(n_col_ * n_row_);
}

MatrixA& MatrixA::operator=(const MatrixA& matrixa) {
	if (this != &matrixa) {
		*this = MatrixA(matrixa);
	}
	return *this;
}

float& MatrixA::at(const std::ptrdiff_t row_i, const std::ptrdiff_t col_i)
{
	if (row_i < 0 || row_i >= n_row_ || col_i < 0 || col_i >= n_col_) {
		throw std::invalid_argument("Invalid row or colum");
	}
	return data_[row_i * n_col_ + col_i];
}

const float& MatrixA::at(const std::ptrdiff_t row_i, const std::ptrdiff_t col_i) const
{
	if (row_i < 0 || row_i >= n_row_ || col_i < 0 || col_i >= n_col_) {
		throw std::invalid_argument("Invalid row or colum");
	}
	return data_[row_i * n_col_ + col_i];
}
