#include <dynarray/dynarray.h>
#include <exception>
#include <iostream>

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
}


float& DynArray::operator[](const std::ptrdiff_t i) {
	return data_[i];
}

const float& DynArray::operator[](const std::ptrdiff_t i) const {
	return data_[i];
}

void DynArray::resize(const std::ptrdiff_t size) {
	if (capacity_ >= size) {
		size_ = size;
	}
	else {
		DynArray newArray = DynArray(size);
		for (std::ptrdiff_t  i = 0; i < size_; i++) {
			newArray[i] = data_[i];
		}
		*this = newArray;
	}
}

DynArray& DynArray::operator=(const DynArray& rhs) {
	if (this != &rhs) {
		delete[] data_;
		data_ = new float[rhs.size_];
		for (std::ptrdiff_t i = 0; i < rhs.size_; i++)
		{
			data_[i] = rhs.data_[i];
		}
	}
	return *this;
}
