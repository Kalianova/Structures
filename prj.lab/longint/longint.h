#ifndef LongInt_H_2019
#define LongInt_H_2019

#pragma once
#include<iostream>
#include<exception>
#include<sstream>
#include<vector>

class LongInt {
public:
	LongInt() = default;

	LongInt(const LongInt& Data_);

	LongInt(const std::vector<uint32_t>& Data_);

	LongInt(const std::vector<uint32_t>& Data_, bool Positive);

	~LongInt();


	void operator=(LongInt LongInt);
	LongInt operator+=(LongInt rhs);
	LongInt operator-=(LongInt rhs);
	LongInt operator*=(LongInt rhs);
	LongInt operator*=(int rhs);
	bool IsPositive() const;
	std::vector<uint32_t> ReadFrom()const;
	uint32_t ReadFrom(int i)const;
	bool operator == (const LongInt& rhs);
	bool operator != (const LongInt& rhs);
	bool operator > (const LongInt& rhs);
	bool operator >= (const LongInt& rhs);
	bool operator < (const LongInt& rhs);
	bool operator <= (const LongInt& rhs);
private:
	const int base = 1000000000;
	std::vector<uint32_t> data_;
	bool positive{ true };
};
std::istream& operator>>(std::istream& stream, LongInt& LongInt);
std::ostream& operator<<(std::ostream& stream, const LongInt& LongInt);
LongInt operator+(LongInt& lhs, LongInt& rhs);
LongInt operator-(LongInt& lhs, LongInt& rhs);
LongInt operator*(LongInt& lhs, LongInt& rhs);

#endif