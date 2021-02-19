#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

/*
 * given a 2D vector of vectors of ints, store the ints as
 * a collection of structures with a startx, starty, xlen, ylen, and offset
 * 
 * algo:
 * 	start at first nonzero point ij
 * 	set offset = mat[i][j]
 * 	for each index in span from ij to maxi, maxj subtract offset
 * 	next repeat
 * */

struct ijMat {
	int startx, starty;
	int xlen, ylen;
	int offset;
};

std::vector<ijMat> compress(std::vector<std::vector<int>> data) {
	std::vector<ijMat> lenses;

	bool encounteredNonzero = true;

	while (encounteredNonzero) {
		encounteredNonzero = false;

		ijMat mat;

		for (int i = 0; i < data.size(); ++i) {
			for (int j = 0; j < data.size(); ++j) {
				if (data[i][j] != 0 && !encounteredNonzero) {
					encounteredNonzero = true;
					mat.startx = i;
					mat.starty = j;
					mat.xlen = data.size() - i;
					mat.ylen = data.size() - j;
					mat.offset = data[i][j];
				}
				if (encounteredNonzero) {
					data[i][j] = data[i][j] - mat.offset;
				}
			}
		}

		if (encounteredNonzero) lenses.push_back(mat);
	}

	return lenses;
}

void print(const std::vector<std::vector<int>>& data) {
	for (int i = 0; i < data.size(); ++i) {
		for (int j = 0; j < data[i].size(); ++j) {
			std::cout << data[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

int main() {
	const int len = 10;
	std::vector<std::vector<int>> rawDataset1;
	for (int i = 0; i < len; ++i) {
		rawDataset1.push_back(std::vector<int>());
		for (int j = 0; j < len; ++j) {
			rawDataset1[rawDataset1.size() - 1].push_back(i);
		}
	}

	print(rawDataset1);

	return 0;
}
