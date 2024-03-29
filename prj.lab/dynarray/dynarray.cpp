#include <dynarray/dynarray.h>
#include <exception>
#include <iostream>
#include <algorithm>

DynArray::DynArray(const DynArray& arr)
	:capacity_(arr.capacity_),
	size_(arr.size_)
{
	data_ = new float[capacity_];
	for (std::ptrdiff_t i = 0; i < size_; i++)
	{
		data_[i] = arr.data_[i];
	}
}

DynArray::DynArray(const std::ptrdiff_t size)
	:capacity_(size),
	size_(size)
{
	if (size < 0) {
		throw std::invalid_argument("Size is less than 0");
	}
	data_ = new float[size];
	for (std::ptrdiff_t i = 0; i < size_; i++){
		data_[i] = 0;
	}
}


float& DynArray::operator[](const std::ptrdiff_t i) {
	if (i < 0 || i>=size_) {
		throw std::invalid_argument("Invalid i");
	}
	return data_[i];
}

const float& DynArray::operator[](const std::ptrdiff_t i) const {
	if (i < 0 || i>=size_) {
		throw std::invalid_argument("Invalid i");
	}
	return data_[i];
}

void DynArray::resize(const std::ptrdiff_t size) {
	if (size < 0) {
		throw std::invalid_argument("Size is less than 0");
	}
	else {
		if (capacity_ >= size) {
			size_ = size;
		}
		else {
			DynArray newArray = DynArray(size);
			for (std::ptrdiff_t i = 0; i < size_; i++) {
				newArray[i] = data_[i];
			}
			*this = newArray;
		}
	}
}

DynArray& DynArray::operator=(const DynArray& rhs) {
	if (this != &rhs) {
		delete[] data_;
		data_ = new float[rhs.size_];
		for (std::ptrdiff_t i = 0; i < rhs.size_; i++) {
			data_[i] = rhs.data_[i];
		}
		capacity_ = rhs.capacity_;
		size_ = rhs.size_;
	}
	return *this;
}
