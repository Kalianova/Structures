#include <dynarrayt/dynarrayt.h>
#include <exception>
#include <iostream>
#include <algorithm>

template<typename T>
DynArrayT<T>::DynArrayT(const DynArrayT& arr)
	:capacity_(arr.capacity_),
	size_(arr.size_)
{
	data_ = new T[capacity_];
	for (std::ptrdiff_t i = 0; i < size_; i++)
	{
		data_[i] = arr.data_[i];
	}
}

template<typename T>
DynArrayT<T>::DynArrayT(const std::ptrdiff_t size)
	:capacity_(size),
	size_(size)
{
	if (size < 0) {
		throw std::invalid_argument("Size is less than 0");
	}
	data_ = new T[size];
	for (std::ptrdiff_t i = 0; i < size_; i++){
		data_[i] = 0;
	}
}

template<typename T>
T& DynArrayT<T>::operator[](const std::ptrdiff_t i) {
	if (i < 0 || i>=size_) {
		throw std::invalid_argument("Invalid i");
	}
	return data_[i];
}

template<typename T>
const T& DynArrayT<T>::operator[](const std::ptrdiff_t i) const {
	if (i < 0 || i>=size_) {
		throw std::invalid_argument("Invalid i");
	}
	return data_[i];
}


template<typename T>
void DynArrayT<T>::resize(const std::ptrdiff_t size) {
	if (size < 0) {
		throw std::invalid_argument("Size is less than 0");
	}
	else {
		if (capacity_ >= size) {
			size_ = size;
		}
		else {
			DynArrayT newArray = DynArrayT(size);
			for (std::ptrdiff_t i = 0; i < size_; i++) {
				newArray[i] = data_[i];
			}
			*this = newArray;
		}
	}
}


template<typename T>
DynArrayT<T>& DynArrayT<T>::operator=(const DynArrayT& rhs) {
	if (this != &rhs) {
		delete[] data_;
		data_ = new T[rhs.size_];
		for (std::ptrdiff_t i = 0; i < rhs.size_; i++) {
			data_[i] = rhs.data_[i];
		}
		capacity_ = rhs.capacity_;
		size_ = rhs.size_;
	}
	return *this;
}
