#include <memory>
#include <iostream>

class testClass {
	public:
		int i;
		int j;

	// private: // destructor cannot be private
	~testClass() {
		std::cout << "destructor. values " << i << ", " << j << std::endl;
	}


};

int main() {
	std::cout << "cplusplus version " << __cplusplus << std::endl;

	testClass* t1 = new testClass {3,4};
	std::cout << "t1 pointer has i = " << t1->i << " and j = " << t1->j << std::endl;
	delete t1;

	std::unique_ptr<testClass> uptr(new testClass{ 5,6});
	std::cout << "t1 pointer has i = " << uptr->i << " and j = " << uptr->j << std::endl;
}

