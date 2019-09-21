#include<iostream>
#include<sstream>

struct Complex {
	Complex() {};
	explicit Complex(const double real);
	Complex(const double real, const double imaginary);
	bool operator==(const Complex& rhs) const { return (re == rhs.re) && (im == rhs.im); }
	bool operator!=(const Complex& rhs) { return (!operator == (rhs)); }
	Complex& operator+=(const Complex& rhs);
	Complex& operator+=(const double rhs) { return operator+=(Complex(rhs)); }
	Complex& operator-=(const Complex& rhs);
	Complex& operator-=(const double rhs) { return operator-=(Complex(rhs)); }	
	Complex& operator*=(const Complex& rhs);
	Complex& operator*=(const double rhs);
	Complex& operator/=(const Complex& rhs);
	Complex& operator/=(const double rhs);
	Complex& operator++() { re++; }
	Complex& operator--() { re--; }
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);
	double re{ 0.0 };
	double im{ 0.0 };

	static const char leftBrace{ '{' };
	static const char separator{ ',' };
	static const char rightBrace{ '}' };
};


inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) {
	return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Complex& rhs) {
	return rhs.readFrom(istrm);
}

bool testParse(const std::string& str) {
	using namespace std;
	istringstream istrm(str);
	Complex x;
	istrm >> x;
	if (istrm.good()) {
		cout << "Read success: " << str << " -> " << x << endl;
	}
	else {
		cout << "Read error: " << str << " -> " << x << endl;
	}
	return istrm.good();
}

int main() {
	using namespace std;
	Complex x;
	x += Complex(9.0);
	testParse("{8.9,9}");
	testParse("{8.9,     9}");
	testParse("{8.9, 9");
	return 0;
}

Complex::Complex(const double real)
	:Complex(real, 0.0)
{}

Complex::Complex(const double real, const double imaginary)
	:re(real)
	,im(imaginary)
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

Complex& Complex::operator-=(const Complex& rhs)
{
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}

Complex& Complex::operator*=(const Complex& rhs)
{
	re = re*rhs.re - im*rhs.im;
	im = im*rhs.im + re*rhs.re;
	return *this;
}

Complex& Complex::operator*=(const double rhs)
{
	re *= rhs;
	im *= rhs;
	return *this;
}

Complex& Complex::operator/=(const Complex& rhs)
{
	re = (re * rhs.re + im * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
	im = (im * rhs.re - re * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
	return *this;
}

Complex& Complex::operator/=(const double rhs)
{
	re /= rhs;
	im /= rhs;
	return *this;
}

std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
	ostrm << leftBrace << re << separator << im << rightBrace;
	return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm)
{
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
