#include <memory>
#include <iostream>

class testClass {
	public:
		int i;
		int j;

	// private: // destructor cannot be private
	~testClass() {
		std::cout << "destroying " << *this << std::endl;
	}

	// have to mark as friend class
	friend std::ostream& operator<<(std::ostream& stream, const testClass& mobj) {
		stream << typeid(mobj).name() << " with i = " << mobj.i << " and j = " << mobj.j;
		return stream;
	}


};

int main() {
	std::cout << "cplusplus version " << __cplusplus << std::endl;

	testClass* t1 = new testClass {3,4};
	std::cout << "t1: " << *t1 << std::endl;
	delete t1;

	std::unique_ptr<testClass> uptr(new testClass{ 5,6});
	std::cout << "uptr: " << *uptr << std::endl;
}

