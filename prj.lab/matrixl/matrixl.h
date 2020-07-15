#ifndef MATRIX_LIST_H_2019
#define MATRIX_LIST_H_2019

#pragma once
#include <cstddef>
#include <memory>

class MatrixL {
	MatrixL() = default;
	MatrixL(const MatrixL&);
	MatrixL(const std::ptrdiff_t col_count, const std::ptrdiff_t row_count);
	~MatrixL() = default;
	MatrixL& operator=(const MatrixL&);

	//MatrixA(MatrixA&&) = default;
	//MatrixA& operator=(MatrixA&&) = default;

	std::ptrdiff_t row_count() const { return n_row_; }
	std::ptrdiff_t col_count() const { return n_col_; }
	float& at(const std::ptrdiff_t row_i, const std::ptrdiff_t col_i);
	const float& at(const std::ptrdiff_t row_i, const std::ptrdiff_t col_i) const;
private:
	std::ptrdiff_t n_row_{ 0 };
	std::ptrdiff_t n_col_{ 0 };
	//float* data_{ nullptr };
	//float** rows_{ nullptr };
	std::unique_ptr<float[]> data_;
	std::unique_ptr<float* []> rows_;
};

#endif