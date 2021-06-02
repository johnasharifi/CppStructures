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

	// this will not cmpile due to conflicting definition.
	// we marked a const ptr to class, but now we are reassigning it!
	// canMultiply* const ptrToClass = new canMultiply(4);
	
	// read right to left: const pointer to a <type> of an immutable/const object
	const canMultiply* const ptrToClass2 = new canMultiply(4);
	std::cout << "ptr2 address is " << ptrToClass2->str11() << "\n";
	delete ptrToClass2;

	delete ptrToClass;
	delete doubleTest;

	int mint = 4;
	int const* ptrToConstInt = &mint;
	// equivalent to const int*
	std::cout << "ptrToConstInt originally pointed at value " << *ptrToConstInt << "\n";

	ptrToConstInt = &mint;
	int mint2 = 5;
	ptrToConstInt = &mint2;

	std::cout << "ptrToConstInt now points at value " << *ptrToConstInt << "\n";

	// we can update the intPtr. intPtr is a pointer to a constant int
	// but we cannot change the value pointed to by the intPtr
	// *ptrTpConstInt = 3;

	int *const constPtrToInt = &mint;
	// not possible because our constant pointer-to-integer cannot be reassigned
       	// constPtrToInt = &mint2;
}
