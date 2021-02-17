#include <stdlib.h>
#include <iostream>
#include <vector>

const int len = 10;


void print(const std::vector<std::vector<int>>& mat) {
	for (std::vector<int> vec: mat) {
		for (int elem: vec) {
			std::cout << elem << "\t";
		}
		std::cout << std::endl;
	}
}

int main() {
	std::vector<std::vector<int>> mat;
	for (int i = 0; i < len; ++i) {
		mat.push_back(std::vector<int>());
		for (int j = 0; j < len; ++j) {
			mat[mat.size() - 1].push_back(0);
		}
	}

	print(mat);
	return 0;
}
