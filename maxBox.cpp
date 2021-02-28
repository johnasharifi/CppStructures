#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

std::vector<std::vector<int>> randomBoxes(int dim) {
	//set up vector of vectors
	std::vector<std::vector<int>> data;

	const int initVal = 0;
	for (int i = 0; i < dim; ++i) {
		data.push_back(std::vector<int>());		
		for (int j = 0; j < dim; ++j) {
			data[i].push_back(initVal);
		}
	}

	const int boxCount = 10;
	
	for (int b = 0; b < boxCount; ++b) {
		int randIndx1 = rand() % dim;
		int randIndx2 = rand() % dim;
		int randIndy1 = rand() % dim;
		int randIndy2 = rand() % dim;

		int xmin = std::min(randIndx1, randIndx2);
		int xmax = std::max(randIndx1, randIndx2);

		int ymin = std::min(randIndy1, randIndy2);
		int ymax = std::max(randIndy1, randIndy2);

		for (int i = xmin; i < xmax; ++i) {
			for (int j = ymin; j < ymax; ++j) {
				data[i][j] = b;
			}
		}
	}

	return data;

}

void print(const std::vector<std::vector<int>>& vec) {
	for (int i = 0; i < vec.size(); ++i) {
		for (int j = 0; j < vec[i].size(); ++j) {
			std::cout << vec[i][j] << ", ";
		}
		std::cout << std::endl;
	}
}

int main() {
	std::vector<std::vector<int>> data = randomBoxes(10);
	print(data);
}
