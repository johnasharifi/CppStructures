#include <stdlib.h>
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

const int len = 10;


void print(const std::vector<std::vector<int>>& mat) {
	for (std::vector<int> vec: mat) {
		for (int elem: vec) {
			std::cout << elem << "\t";
		}
		std::cout << std::endl;
	}
}

std::vector<std::tuple<int,int>> get_adjacents_to(const std::tuple<int,int>& orig, const std::vector<std::vector<bool>> visitRecord) {
	std::vector<std::tuple<int,int>> adjacents;

	for (int i = std::max(std::get<0>(orig) - 1, 0); i < std::min(len, std::get<0>(orig) + 2); ++i) {
		for (int j = std::max(std::get<1>(orig) - 1, 0); j < std::min(len, std::get<1>(orig) + 2); ++j) {
			// skip previously visited nodes
			if (visitRecord[i][j]) continue;
			adjacents.push_back(std::tuple<int,int>(i,j));
		}
	}

	return adjacents;
}

int main() {
	std::vector<std::vector<int>> mat;
	std::vector<std::vector<bool>> visitRecord;
	for (int i = 0; i < len; ++i) {
		mat.push_back(std::vector<int>());
		visitRecord.push_back(std::vector<bool>());
		for (int j = 0; j < len; ++j) {
			mat[mat.size() - 1].push_back(0);
			visitRecord[visitRecord.size() - 1].push_back(false);
		}
	}

	std::tuple<int,int> ind = std::tuple<int,int>(rand() % len, rand() % len);
	std::queue<std::tuple<int,int>> pending;
	pending.push(ind);

	while (pending.size() > 0) {
		std::tuple<int,int> top = pending.front();
		pending.pop();

		for (std::tuple<int,int> adj: get_adjacents_to(top, visitRecord)) {
			pending.push(adj);
			visitRecord[std::get<0>(adj)][std::get<1>(adj)] = true;
		}
	}

	print(mat);
	return 0;
}
