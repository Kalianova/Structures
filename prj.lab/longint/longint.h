#ifndef LONG_INT_H_2019
#define LONG_INT_H_2019

#pragma once
#include<iostream>
#include<exception>
#include<sstream>
#include<vector>

class Long_int {
public:
	Long_int() {};

	Long_int(std::vector<uint32_t>& data_) {
		data_ = data_;
	}

	Long_int(std::vector<uint32_t>& data_, bool Positive) {
		data_ = data_;
		Positive = positive;
	}

	std::vector<uint32_t> ReadFrom()const;
	uint32_t ReadFrom(int i)const;
	void operator=(Long_int long_int);
	Long_int operator+=(Long_int rhs);
	Long_int operator-=(Long_int rhs);
	Long_int operator*=(Long_int rhs);
	Long_int operator*=(int rhs);
	bool IsPositive() const;
private:
	const int base = 1000000000;
	std::vector<uint32_t> data_;
	bool positive{ true };
};
std::istream& operator>>(std::istream& stream, Long_int& long_int);
std::ostream& operator<<(std::ostream& stream, const Long_int& long_int);
Long_int operator+(Long_int& lhs, Long_int& rhs);
Long_int operator-(Long_int& lhs, Long_int& rhs);
Long_int operator*(Long_int& lhs, Long_int& rhs);

#endif