#pragma once
#ifndef DYN_ARRAY_2019
#define DYN_ARRAY_2019

#include <cstddef>

template<typename T>
class DynArrayT {
public:
	DynArrayT() = default;
	DynArrayT(const DynArrayT& arr);
	DynArrayT(const std::ptrdiff_t size);
	DynArrayT& operator=(const DynArrayT& rhs);
	~DynArrayT() = default;
	std::ptrdiff_t size() const { return size_; }
	T& operator[](const std::ptrdiff_t i);
	const T& operator[](const std::ptrdiff_t i) const;
	void resize(const std::ptrdiff_t size);
private:
	std::ptrdiff_t capacity_{ 0 }; 
	std::ptrdiff_t size_{ 0 }; 
	std::unique_ptr<T[]> data_{ nullptr };
};



#endif