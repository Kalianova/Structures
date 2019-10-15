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
	Long_int(int64_t size) {

	}

private:
	std::vector<int> digits;
};
std::istream& operator>>(std::istream& stream, Long_int& long_int);
std::ostream& operator<<(std::ostream& stream, const Long_int& long_int);
#endif