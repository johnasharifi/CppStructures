#include <iostream>
#include<vector>
#include <string.h>

void print(const char* array) {
	int len = strlen(array);
	for (int i = 0; i < len; ++i) {
		std::cout << "array[" << i << "] = " << array[i] << "\n";
	}
	std::cout << "\n";
}

template <class T>
void print(const std::vector<T>& data) {
	for (uint i = 0; i < (int) data.size(); ++i) {
		std::cout << "array[" << i << "] = " << data[i] << "\n";
	}
	std::cout << "\n";
}

int main() {
	const char* charArray1 = "test";
	// we can convert a UTF string to a char array
	const char charArray2[] = "test";
	// remember the null terminate when specifying a collection of chars
	const char charArray3[] = {'t', 'e', 's', 't', '\0'};

	for (const char* ptr: {charArray1, charArray2, charArray3}) {
		print(ptr);
	}

	// this is not possible = const int* intArray = {1,2,3,4};
	const int intArray1[] = {1,2,3,4};

	// g++ version 11+
	// fails to compile if you do g++ -std=c++98 initializers.cpp
	std::vector<int> intVector1 = {1,2,3,4};

	// this is not possible because vector initialization using {} is a token optimization, not a type conversion
	// std::vector<int> intVector2 = intArray1;
	std::vector<int> intVector2(intArray1, intArray1 + 4);

	for (std::vector<int> vector: {intVector1, intVector2}) {
		print(vector);
	}
}
