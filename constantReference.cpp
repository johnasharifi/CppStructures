#include <iostream>
#include <string>

class canMultiply {
	private:
		int i;
	public:
		canMultiply(int _i) {
			i = _i;
		}

		void multiply() {
			
		}
		explicit operator std::string const () {
			return std::string("");
		}
};

int main() {
	canMultiply* doubleTest = new canMultiply(2);
	doubleTest->multiply();

	std::cout << "doubled\n";

	delete doubleTest;
}
