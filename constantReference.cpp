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

	const canMultiply* ptrToClass = doubleTest;

	std::cout << "before re-pointing, const ptrToClass address is " << ptrToClass << "\n";
	// will compile, as the ptr is still a ptr to a constant thing
	ptrToClass = new canMultiply(3);
	std::cout << "after re-pointing const ptrToClass to new ptrToClass(3), address is " << ptrToClass << "\n";

	// will not compile, as the const ptr cannot call a potentially-mutating method
	// ptrToClass->multiply();
	
	// can call ptr->str11, as this is a constant method which maintains the const ptr's promise to not mutate
	std::cout << "ptr value was initialized to 3. value is still " << ptrToClass->str11() << "\n";

	delete ptrToClass;
	delete doubleTest;
}
