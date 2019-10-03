#include"complex.h"
#include<iostream>
bool testParse(const std::string& str);
void testComputation(Complex lhs, Complex rhs);

int main() {
	using namespace std;
	Complex x;
	x += Complex(9.0);
	testParse("{8.9,9}");
	testParse("{8.9,     9}");
	testParse("{8.9, 9");
	Complex p1 = Complex(1, 2);
	Complex p2 = Complex(2, 1);
	cout << endl;
	cout << "Test comparison:" << endl;
	testComparison(p1, p2);
	return 0;
}

bool testParse(const std::string& str) {
	using namespace std;
	istringstream istrm(str);
	Complex x;
	istrm >> x;
	if (istrm.good()) {
		cout << "Read success: " << str << " -> " << x << endl;
		return true;
	}
	else {
		cout << "Read error: " << str << " -> " << x << endl;
		return false;
	}
}

void testComputation(Complex lhs, Complex rhs) {
	using namespace std;

	cout << lhs << " + : " << rhs << " => " << lhs + rhs << endl;
	cout << lhs << " - : " << rhs << " => " << lhs - rhs << endl;
	cout << lhs << " * : " << rhs << " => " << lhs * rhs << endl;
	cout << lhs << " / : " << rhs << " => " << lhs / rhs << endl;

    cout << lhs << " += " << rhs << " => " << (lhs += rhs) << endl;
	cout << lhs << " -= " << rhs << " => " << (lhs -= rhs) << endl;
	cout << lhs << " *= " << rhs << " => " << (lhs *= rhs) << endl;
	cout << lhs << " /= " << rhs << " => " << (lhs /= rhs) << endl;
	double y = 0.5;
	cout << lhs << " += " << y << " => " << (lhs += y) << endl;
	cout << lhs << " -= " << y << " => " << (lhs -= y) << endl;
	cout << lhs << " *= " << y << " => " << (lhs *= y) << endl;
	cout << lhs << " /= " << y << " => " << (lhs /= y) << endl;
}



