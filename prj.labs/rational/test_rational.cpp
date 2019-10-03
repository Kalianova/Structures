#include "rational.h"

using std::cout;
using std::endl;
using std::cin;

void testConstructor();
template<typename T> void testComputation(Rational first, T second);
template<typename T> void testComparison(Rational first, T second);
bool testParse(const std::string& str);

int main() {
	Rational r1 = Rational(1, 2);
	Rational r2 = Rational(1, 3);
	int i1 = 4;
	cout << "Test parse:" << endl;
	testParse("1 / 2");
	testParse("1 . 2");
	testParse("1  2");
	cout << endl;
	cout << "Test constructor: " << endl;
	testConstructor();
	cout << endl;
	cout << "Test computation: " << endl;
	testComputation(r1, r2);
	cout << endl;
	cout << "Test comparison:" << endl;
	testComparison(r1, r2);
	return 0;
}

bool testParse(const std::string& str) {
	using namespace std;
	istringstream istrm(str);
	Rational x;
	try {
		istrm >> x;
		cout << "Read success: " << str << " -> " << x << endl;
		return true;
	}
	catch (std::exception e) {
		cout << "Read error: " << str << " -> " << x << endl;
		return false;
	}
}


void testConstructor() {
	Rational first = Rational();
	cout << "Rational()      => " << "Numerator = " << first.Numerator() << " Denominator = " << first.Denominator() << endl;
	first = Rational(-2, 3);
	cout << "Rational(-2, 3) => " << "Numerator = " << first.Numerator() << " Denominator = " << first.Denominator() << endl;
	first = Rational(3, -2);
	cout << "Rational(3, -2) => " << "Numerator = " << first.Numerator() << " Denominator = " << first.Denominator() << endl;
	first = Rational(4);
	cout << "Rational(4)     => " << "Numerator = " << first.Numerator() << " Denominator = " << first.Denominator()<<endl;
	try {
		cout << "Rational(4,0) => ";
		Rational devZero = Rational(4, 0);
	}
	catch (std::invalid_argument& i) {
		std::cout << i.what() << std::endl;
	}

}


template<typename T>
void testComputation(Rational first,T second) {

	cout << first << " + " << second << " = " << first + second << endl;
	cout << first << " - " << second << " = " << first - second << endl;
	cout << first << " * " << second << " = " << first * second << endl;
	cout << first << " / " << second << " = " << first / second << endl;
	try {
		Rational numZero = Rational(0, 3);
		cout << first << " / " << numZero << " => ";
		cout << first / numZero << endl;
	}
	catch (std::invalid_argument& i) {
		std::cout << i.what() << std::endl;
	}

	cout << first << " += " << second << " => "<< (first += second) << endl;
	cout << first << " -= " << second << " => "<< (first -= second) << endl;
	cout << first / second << " *= " << second << " => " << (first *= second) << endl;
	cout << first * second << " /= " << second << " => " << (first /= second) << endl;

	cout << first << "++ => ";
	cout << (first++) << endl;
	cout << first << "-- => ";
	cout << (first--) << endl;
}
template<typename T>
void testComparison(Rational first, T second) {

	cout << first << " == " << second << " => " << (first == second) << endl;
	cout << first << " != " << second << " => " << (first != second) << endl;
	cout << first << " > " << first << " => " << (first > second) << endl;
	cout << first << " < " << first << " => " << (first < second) << endl;
	cout << first << " <= " << first << " => " << (first <= second) << endl;
	cout << first << " >= " << first << " => " << (first >= second) << endl;
}







