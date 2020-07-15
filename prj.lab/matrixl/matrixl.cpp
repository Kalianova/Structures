#include<matrixl/matrixl.h>
#include <stdexcept>


/*MatrixL::MatrixL(const std::ptrdiff_t row_, const std::ptrdiff_t col_) : n_row_(row_), n_col_(col_)
{
	if ((row_ < 0) && (col_ < 0))
		throw std::invalid_argument("Size is invalid");
	data_ = new float[n_row_ * n_col_];
	rows_ = new float* [n_row_];
	for (int i = 0; i < n_row_; ++i) {
		rows_[i] = &(data_[i * n_col_]);
	}
}

MatrixL::MatrixL(const MatrixL& rhs) : n_row_(rhs.n_row_), n_col_(rhs.n_col_),
data_(new float[n_row_ * n_col_]), rows_(new float* [n_row_])
{
	std::copy(rhs.data_, rhs.data_ + rhs.n_row_ * rhs.n_col_, data_);
	for (int i = 0; i < n_row_; ++i) {
		rows_[i] = &(data_[i * n_col_]);
	}
}

MatrixL::~MatrixL()
{
	delete[] data_;
	delete[] rows_;
}

float& MatrixL::at(const std::ptrdiff_t row_, const std::ptrdiff_t col_)
{
	if ((row_ >= n_row_) || (col_ >= n_col_) || (col_ < 0) || (row_ < 0))
	{
		throw std::invalid_argument("Row or colum is invalid");
	}
	return *(rows_[row_] + col_);
}

const float& MatrixL::at(const std::ptrdiff_t row_, const std::ptrdiff_t col_) const
{
	if ((row_ >= n_row_) || (col_ >= n_col_) || (col_ < 0) || (row_ < 0))
	{
		throw std::invalid_argument("Row or colum is invalid");
	}
	return *(rows_[row_] + col_);
}

MatrixL& MatrixL::operator=(const MatrixL& rhs)
{
	if (this != &rhs)
	{
		delete[] data_;
		delete[] rows_;
		n_row_ = rhs.n_row_;
		n_col_ = rhs.n_col_;
		data_ = new float[n_row_ * n_col_];
		rows_ = new float* [n_row_];
		std::copy(rhs.data_, rhs.data_ + rhs.n_row_ * rhs.n_col_, data_);
		for (int i = 0; i < n_row_; ++i) {
			rows_[i] = &(data_[i * n_col_]);
		}
	}
	return *this;
}
*/

MatrixL::MatrixL(ptrdiff_t row, ptrdiff_t col):n_row_(row),n_col_(col) {
	if (row < 0 || col < 0) {
		throw std::invalid_argument("wrong");
	}
	data_ = std::make_unique<float[]>(row * col);
	rows_ = std::make_unique<float* []>(row);
	for (size_t i = 0; i < row; i++)
	{
		rows_[i] = &data_[row * i + col];
	}
}

MatrixL::MatrixL(const MatrixL& m):n_col_(m.n_col_), n_row_(m.n_row_), data_ (std::make_unique<float[]>(n_row_*n_col_)),
rows_(std::make_unique<float*[]>(n_row_)){
	copy(m, m + n_col_*n_row_, data_)
}

