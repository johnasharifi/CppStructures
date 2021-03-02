#include <iostream>

const int v4len = 4;

void print(int* ptr) {
	std::cout << "\t";
	for (int i = 0; i < v4len; ++i) 
		std::cout << ptr[i] << ", ";
	std::cout << std::endl;
}

// could also const the pointer and data of the pointer - const int** const ptr
// provide a pointer to an array of arrays
void print(int (*ptr)[v4len][v4len]) {
	for (int i = 0; i < v4len; ++i) {
		std::cout << "i: " << i << std::endl << "\t";
		print((*ptr)[i]);
		std::cout << std::endl;
	}
}

int main() {
	// static init of empty array of size 4
	int data[v4len] = {0};
	// stack init of 1d array
	int data1d2[] = {1,2,3,4};

	// simplest array init possible
	int* data1dnew = new int[v4len];

	// note: have to specify all but first array dimension
	int data2[][v4len] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16} };

	// note: critical to resolve the (*ptr) before specifying the array dims
	// get a pointer to an array of arrays
	int (*ptrToData2)[v4len][v4len] = &data2;

	// 1, 2, 3, 4
	print(&data1d2[0]);
	// 0, 0, 0, 0
	print(data1dnew);

	// i: 0 1,2,3,4 i: 1 5,6,7,8 i: 2 9, 10, 11, 12 i: 3 13, 14, 15, 16
	print(ptrToData2);
	
	// delete array
	delete[] data1dnew;
	return 0;
}
