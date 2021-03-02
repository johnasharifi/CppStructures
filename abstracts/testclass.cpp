#include <iostream>
// for ostringstream
#include <sstream>

struct TestStruct {
	// no public/private distinction
	int i;
	int j;

	// string cast operator
	operator std::string() {
		std::ostringstream stringStream;
		stringStream << "(std::string) i: " << i << ", j: " << j;
		// note: .str, not c_str
		return stringStream.str();
	}
};

// note: std::ostream, not unqualified ostream
// ostream is within iostream
std::ostream& operator<<(std::ostream& stream, const TestStruct& mstruct) {
	stream << "(ostream) i: " << mstruct.i << ", j: " << mstruct.j;
	return stream;
}

class TestClass {
	public:
		TestStruct v1;
		TestStruct v2;
		TestStruct v3;
};

int main() {
	TestClass* class1 = new TestClass { {0,1}, {2,3}};

	// deref operator, then property access
	// note: the (*class1) deref must be enclosed in parenthesis because * operator is very weak
	std::cout << "struct as std::string: " << (std::string) (*class1).v1 << std::endl;

	// pointer deref operator
	std::cout << "struct through ostream: " << class1->v2 << std::endl;

	delete class1;
}
