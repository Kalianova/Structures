#include"complex.h"

std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) {
	return rhs.writeTo(ostrm);
}

std::istream& operator>>(std::istream& istrm, Complex& rhs) {
	return rhs.readFrom(istrm);
}

Complex::Complex(const double real)
	:Complex(real, 0.0)
{}

Complex::Complex(const double real, const double imaginary)
	: re(real)
	, im(imaginary)
{}

Complex operator +(const Complex& lhs, const Complex& rhs) {
	Complex sum(lhs);
	sum += rhs;
	return sum;
}

Complex operator -(const Complex& lhs, const Complex& rhs) {
	Complex sub(lhs);
	sub -= rhs;
	return sub;
}

Complex operator *(const Complex& lhs, const Complex& rhs) {
	Complex mul(lhs);
	mul *= rhs;
	return mul;
}

Complex operator /(const Complex& lhs, const Complex& rhs) {
	Complex dev(lhs);
	dev /= rhs;
	return dev;
}


Complex& Complex::operator+=(const Complex& rhs) {
	re += rhs.re;
	im += rhs.im;
	return *this;
}

Complex& Complex::operator-=(const Complex& rhs){
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}

Complex& Complex::operator*=(const Complex& rhs){
	double imaginary = re * rhs.im + im * rhs.re;
	re = re * rhs.re - im * rhs.im;
	im = imaginary;
	return *this;
}

Complex& Complex::operator*=(const double rhs){
	re *= rhs;
	im *= rhs;
	return *this;
}

Complex& Complex::operator/=(const Complex& rhs){
	double imaginary = (im * rhs.re - re * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
	re = (re * rhs.re + im * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
	im = imaginary;
	return *this;
}

Complex& Complex::operator/=(const double rhs){
	re /= rhs;
	im /= rhs;
	return *this;
}

Complex& Complex::operator=(const Complex& rhs) {
	re = rhs.re;
	im = rhs.im;
	return *this;
}

std::ostream& Complex::writeTo(std::ostream& ostrm) const{
	ostrm << leftBrace << re << separator << im << rightBrace;
	return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm){
	char leftBrace(0);
	double real(0.0);
	char comma(0);
	double imaginary(0.0);
	char rightBrace(0);
	istrm >> leftBrace >> real >> comma >> imaginary >> rightBrace;
	if (istrm.good()) {
		if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma)
			&& (Complex::rightBrace == rightBrace)) {
			re = real;
			im = imaginary;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}

