#include <iostream>
#include<vector>
#include <string.h>

void print(const char* array) {
	int len = strlen(array);
	for (int i = 0; i < len; ++i) {
		std::cout << "array[" << i << "] = " << array[i] << "\n";
	}
}

template <class T>
void print(const std::vector<T>& data) {
	for (uint i = 0; i < (int) data.size(); ++i) {
		std::cout << "array[" << i << "] = " << data[i] << "\n";
	}
}

int main() {
	const char* charArray1 = "test";
	// we can convert a UTF string to a char array
	const char charArray2[] = "test";
	// remember the null terminate when specifying a collection of chars
	const char charArray3[] = {'t', 'e', 's', 't', '\0'};

	for (const char* ptr: {charArray1, charArray2}) {
		print(ptr);
	}

	std::vector<int> data = {1,2,3,4};
	print(data);
}
