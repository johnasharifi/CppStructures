#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

bool sameKey(const std::vector<std::vector<int>>& data, int startx, int starty, int endx, int endy) {
	if (startx == endx && starty == endy) return true;

	int key = data[startx][starty];

	// confirm that smaller rect is same key
	if (endx > startx && endy > starty) {
		bool smaller_square = sameKey(data, startx, starty, endx - 1, endy - 1);
		if (!smaller_square) return false;
	}

	// check edge where x varies
	for (int x = startx; x <= endx; ++x) {
		if (data[x][endy] != key) return false;
	}

	// check edge where y varies
	for (int y = starty; y <= endy; ++y) {
		if (data[endx][y] != key) return false;
	}

	return data[startx][starty] == data[endx][endy];
}

// given startx, starty returns endx, endy
std::vector<int> findBox(const std::vector<std::vector<int>>& data, int startx, int starty) {
	int maxx = startx;
	int maxy = starty;

	while (maxx+1 < data.size() && maxy+1 < data[0].size() && sameKey(data, startx, starty, maxx + 1, maxy + 1)) {
		maxx++;
		maxy++;
	}
	while (maxx+1 < data.size() && sameKey(data, startx, starty, maxx + 1, maxy + 0)) {
		maxx++;
	}
	while (maxy+1 < data[0].size() && sameKey(data, startx, starty, maxx + 0, maxy + 1)) {
		maxy++;
	}

	std::vector<int> maxinds;
	maxinds.push_back(maxx);
	maxinds.push_back(maxy);

	return maxinds;
}

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

	int key = data[5][5];
	std::vector<int> maxFrom5 = findBox(data, 5,5);
	std::cout << "key " << key << "spans from 5,5 to " << maxFrom5[0] << ", " << maxFrom5[1] << std::endl;
}
