#include<long_int/long_int.h>

int main() {
	std::string s = "27398728524058023492309482309";
	Long_int long_int1;
	Long_int long_int2;
	std::cin >> long_int1;
	std::cin >> long_int2;
	TestParse(s);
	TestAdd(long_int1, long_int2);
	TestSubstract(long_int1, long_int2);
	TestMultiply(long_int1, long_int2);
}

void TestParse(const std::string& str) {

}
 
void TestAdd(Long_int& lhs, Long_int& rhs) {

}

void TestSubstract(Long_int& lhs, Long_int& rhs) {

}

void TestMultiply(Long_int& lhs, Long_int& rhs) {

}