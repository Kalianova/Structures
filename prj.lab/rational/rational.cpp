#include <rational/rational.h>


Rational::Rational(int32_t num) {
    this->num = num;
    this->denom = 1;
}

Rational::Rational(int32_t num, int32_t denom) {
    if (denom == 0) {
        throw std::invalid_argument("Invalid argument: Denominator = 0");
    }
    if (denom < 0) {
        denom = -denom;
        num = -num;
    }
    int n = NOD(abs(num), abs(denom));
    this->num = num / n;
    this->denom = denom / n;
}

Rational Rational::operator ++(int i) {
    num += denom;
    return *this;
}

Rational Rational::operator --(int i) {
    num -= denom;
    return *this;
}

Rational Rational::operator =(const Rational& rhs) {
    num = rhs.Numerator();
    denom = rhs.Denominator();
	normalize();
    return *this;
}

Rational operator +(const Rational& lhs, const Rational& rhs) {
	Rational n = lhs;
	n += rhs;
	return n;
}

Rational operator -(const Rational& lhs, const Rational& rhs) {
	Rational n = lhs;
	n -= rhs;
    return n;
}

Rational operator *(const Rational& lhs, const Rational& rhs) {
    return { lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator() };
}

Rational operator /(const Rational& lhs, const Rational& rhs) {
    if (rhs.Numerator() == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return {lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator() };
}

bool operator ==(const Rational& lhs, const Rational& rhs) {
    return (lhs.Numerator() == rhs.Numerator()) && (lhs.Denominator() == rhs.Denominator());
}

bool operator !=(const Rational& lhs, const Rational& rhs) {
    return !(lhs == rhs);
}

bool operator >(const Rational& lhs, const Rational& rhs) {
	return lhs.Numerator() * rhs.Denominator() > lhs.Denominator()* rhs.Numerator();
}

bool operator <(const Rational& lhs, const Rational& rhs) {
	return lhs.Numerator() * rhs.Denominator() < lhs.Denominator()* rhs.Numerator();
}


bool operator >=(const Rational& lhs, const Rational& rhs) {
    return !(lhs < rhs);
}

bool operator <=(const Rational& lhs, const Rational& rhs) {
    return !(lhs > rhs);
}

void Rational::normalize(){
	int k = NOD(abs(num), abs(denom));
	num /= k;
	denom /= k;
}

std::ostream& operator<<(std::ostream& stream, const Rational& rational) {
    stream << rational.Numerator() << '/' << rational.Denominator();
    return stream;
}
std::istream& operator>>(std::istream& stream, Rational& rational) {
    int num;
    int denom;
    char ch;
    if (stream) {
		stream >> num;
		if (stream.peek() == '/') {
			stream.ignore(1);
			if (stream.peek() >= '0' && stream.peek() <= '9') {
				stream >> denom;
				rational = Rational(num, denom);
				return stream;
			}
		}
    }
	stream.setstate(std::ios::failbit);
}

int NOD(int32_t n, int32_t d) {
    while (n > 0 && d > 0) {
        if (n > d) {
            n %= d;
        }
        else {
            d %= n;
        }
    }
    return (n + d);
}

Rational operator-(const Rational& rhs) {
	return rhs*Rational(-1);
}

Rational& Rational::operator +=(const Rational& rhs) {
	num = num * rhs.Denominator() + rhs.Numerator() * denom;
	denom = denom * rhs.Denominator();
	normalize();
    return *this;
}

Rational& Rational::operator -=(const Rational& rhs) {
	num = num * rhs.Denominator() - rhs.Numerator() * denom;
	denom = denom * rhs.Denominator();
	normalize();
	return *this;
}

Rational& Rational::operator *=(const Rational& rhs) {
    *this = *this * rhs;
	normalize();
    return *this;
}

Rational& Rational::operator /=(const Rational& rhs) {
    *this = *this / rhs;
	normalize();
    return *this;
}