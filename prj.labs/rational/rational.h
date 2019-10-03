#ifndef RATIONAL_H_2019
#define RATIONAL_H_2019

#pragma once
#include<iostream>
#include<exception>
#include<sstream>

class Rational {
public:
	Rational() {};
	Rational(int32_t num);
	Rational(int32_t num, int32_t denom);
	Rational operator += (const Rational& rhs);
	Rational operator -= (const Rational& rhs);
	Rational operator *= (const Rational& rhs);
	Rational operator /= (const Rational& rhs);
	Rational operator ++(int i);
	Rational operator --(int i);
	Rational operator =(const Rational& rhs);

	int Numerator() const {
		return num;
	}

	int Denominator() const {
		return denom;
	}

private:
	int32_t num{ 0 };
	int32_t denom{ 1 };
};
Rational operator +(const Rational& lhs, const Rational& rhs);
Rational operator -(const Rational& lhs, const Rational& rhs);
Rational operator *(const Rational& lhs, const Rational& rhs);
Rational operator /(const Rational& lhs, const Rational& rhs);
bool operator ==(const Rational& lhs, const Rational& rhs);
bool operator !=(const Rational& lhs, const Rational& rhs);
bool operator >(const Rational& lhs, const Rational& rhs);
bool operator <(const Rational& lhs, const Rational& rhs);
bool operator >=(const Rational& lhs, const Rational& rhs);
bool operator <=(const Rational& lhs, const Rational& rhs);
std::ostream& operator<<(std::ostream& stream, const Rational& rational);
std::istream& operator>>(std::istream& stream, Rational& rational);
int NOD(int32_t n, int32_t d);

#endif