#include <iostream>
#include <string>

class canMultiply {
	private:
		int i;
		const int scale = 2;

	public:
		canMultiply(int _i) {
			i = _i;
		}

		void multiply() {
			i = i * scale;
		}

		// cannot implement a const method which modifies a property of the object
		/*
		std::string multiplyAndReport() const {
			i = i * scale;
			return std::to_string(i);
		}
		*/

		std::string str11 () const {
			return std::to_string(i);
		}
};

int main() {
	canMultiply* doubleTest = new canMultiply(2);
	std::cout << "initialized. value is now " << doubleTest->str11() << "\n";

	doubleTest->multiply();

	std::cout << "doubled. value is now " << doubleTest->str11() << "\n";

	delete doubleTest;
}
