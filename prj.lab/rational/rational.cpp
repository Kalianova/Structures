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
    return *this;
}

Rational operator +(const Rational& lhs, const Rational& rhs) {
    return { (lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator()), lhs.Denominator() * rhs.Denominator() };
}

Rational operator -(const Rational& lhs, const Rational& rhs) {
    return { (lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator()), lhs.Denominator() * rhs.Denominator() };
}

Rational operator *(const Rational& lhs, const Rational& rhs) {
    return { lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator() };
}

Rational operator /(const Rational& lhs, const Rational& rhs) {
    if (rhs.Numerator() == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return { lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator() };
}

bool operator ==(const Rational& lhs, const Rational& rhs) {
    return (lhs.Numerator() == rhs.Numerator()) && (lhs.Denominator() == rhs.Denominator());
}

bool operator !=(const Rational& lhs, const Rational& rhs) {
    return !(lhs == rhs);
}

bool operator >(const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() * rhs.Denominator() > lhs.Denominator() * rhs.Numerator();
}

bool operator <(const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() * rhs.Denominator() < lhs.Denominator() * rhs.Numerator();
}

bool operator >=(const Rational& lhs, const Rational& rhs) {
    return !(lhs < rhs);
}

bool operator <=(const Rational& lhs, const Rational& rhs) {
    return !(lhs > rhs);
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
        stream >> num >> ch >> denom;
        if (ch == '/') {
            rational = Rational(num, denom);
        }
        else {
            throw std::exception();
        }
    }
    return stream;
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

Rational Rational::operator +=(const Rational& rhs) {
    *this = Rational(num, denom) + rhs;
    return *this;
}

Rational Rational::operator -=(const Rational& rhs) {
    *this = Rational(num, denom) - rhs;
    return *this;
}

Rational Rational::operator *=(const Rational& rhs) {
    *this = Rational(num, denom) * rhs;
    return *this;
}

Rational Rational::operator /=(const Rational& rhs) {
    *this = Rational(num, denom) / rhs;
    return *this;
}