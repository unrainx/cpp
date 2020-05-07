#include "string.h"

using namespace rain;

template<typename T>
inline void testUnit(T lhs, T rhs) {
	static unsigned int count = 0;
	static unsigned int pass = 0;
	if (rhs == lhs) {
		pass++;
		std::cout << "Example " << count++ << ": Test passed;\n";
	} else {
		std::cout << "Example " << count++ << ": Test failed;\n";
	}
	//std::cout << "Pass Rate: " << pass << " / " << count <<";\n";
}


inline void test() {
	String s("abcafa1sd561f5gsfdgfs");
	String s1("你好");
	String s2("hahah哈");
	String s3("hahah哈");
	s.include("");
	testUnit(s1.include(""), true);
	testUnit(s1.include(""), true);
	testUnit(s1.include("hao"), false);
	testUnit(s1.include("你"), true);
	testUnit(s1.include("好"), true);
	testUnit(s.include("abcafa1sd561f5gsfdgfsd45g"), true);
	testUnit(s.include("abcabc"), true);
	testUnit(s.include("abcabca"), false);
	testUnit(s.include(s1), false);
	testUnit(s2.include(s2), true);
	std::cout << "Test end\n";
}

int main(const int argc, const char ** argv) {
	test();
}