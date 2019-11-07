#include<longint/longint.h>

int main() {
	std::string s = "27398728524058023492309482309";
	LongInt LongInt1;
	LongInt LongInt2;
	std::cin >> LongInt1;
	std::cin >> LongInt2;
	TestParse(s);
	TestAdd(LongInt1, LongInt2);
	TestSubstract(LongInt1, LongInt2);
	TestMultiply(LongInt1, LongInt2);
}

void TestParse(const std::string& str) {

}
 
void TestAdd(LongInt& lhs, LongInt& rhs) {

}

void TestSubstract(LongInt& lhs, LongInt& rhs) {

}

void TestMultiply(LongInt& lhs, LongInt& rhs) {

}