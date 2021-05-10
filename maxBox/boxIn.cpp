#include <vector>
#include <iostream>

template <class T>
void print(const std::vector<std::vector<T>>& data) {
	std::cout << "data in 2D grid: " << std::endl;
	for (int i = 0; i < data.size(); ++i) {
		for (int j = 0; j < data[i].size(); ++j) {
			std::cout << data[i][j];
		}
		std::cout << std::endl;
	}
}

// create a box of 1s surrounded by a larger box of 0s
std::vector<std::vector<int>> getBoxInBox(int dim1, int dim2) {
	const float inset = 0.3f;
	int boxIn1 = (int) dim1 * (0.0f + inset);
	int boxOut1 = (int) dim1 * (1.0f - inset);
	int boxIn2 = (int) dim2 * (0.0f + inset);
	int boxOut2 = (int) dim2 * (1.0f - inset);

	std::vector<std::vector<int>> signals;
	for (int i = 0; i < dim1; ++i) {
		signals.push_back(std::vector<int>());
		for (int j = 0; j < dim2; ++j) {
			int signal = 0;
			if (boxIn1 <= i && i <= boxOut1 && boxIn2 <= j && j <= boxOut2)
				signal = 1;
			signals[i].push_back(signal);
		}
	}
	return signals;
}

int main() {
	std::vector<std::vector<int>> box = getRandomBoxInBox(25, 15);
	print(box);
	return 0;
}


