#include "Rational.h"

template<typename T> void testComputation(Rational& first, T& second);
template<typename T> void testComparison(Rational& first, T& second);
void testExceptions(Rational& first);

int main() {

	Rational r1 = Rational(1, 2);
	Rational r2 = Rational(1, 3);
	int i1 = 4;
	cout << "Test computation: " << endl;
	testComputation(r1, r2);
	cout << endl;
	cout << "Test comparison:" << endl;
	testComparison(r1, r2);
	cout << endl;
	cout << "Test exceptions:" << endl;
	testExceptions(r1);
	return 0;
}
template<typename T>
void testComputation(Rational& first, T& second) {
	cout << first << " + " << second << " = " << first + second << endl;
	cout << first << " - " << second << " = " << first - second << endl;
	cout << first << " * " << second << " = " << first * second << endl;
	cout << first << " / " << second << " = " << first / second << endl;

	cout << first << " += " << second << " => ";
	cout << (first += second) << endl;
	cout << first << " -= " << second << " => ";
	cout << (first -= second) << endl;
	cout << first / second << " *= " << second << " => ";
	cout << (first *= second) << endl;
	cout << first * second << " /= " << second << " => ";
	cout << (first /= second) << endl;

	cout << first << "++ => ";
	cout << (first++) << endl;
	cout << first << "-- => ";
	cout << (first--) << endl;
}
template<typename T>
void testComparison(Rational& first, T& second) {
	cout << first << " == " << second << " => " << (first == second) << endl;
	cout << first << " != " << second << " => " << (first != second) << endl;
	cout << first << " == " << first << " => " << (first == first)<<endl;
}

void testExceptions(Rational& first) {
	try{
		cout << "Rational(4,0) => ";
		Rational devZero = Rational(4, 0);
	}
	catch (std::invalid_argument& i) {
		std::cout << i.what() << std::endl;
	}

	try {
		Rational numZero = Rational(0, 3);
		cout << first << " / " << numZero << " => ";
		cout << first / numZero << endl;
	}
	catch (std::invalid_argument& i) {
		std::cout << i.what() << std::endl;
	}
}



