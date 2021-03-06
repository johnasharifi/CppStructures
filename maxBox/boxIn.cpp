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

// the line structure permits the tester to test whether a grid-aligned point is above or below the line
struct line {
	public:
	float xstart, ystart, slope;

	bool sepTest(int xcoord, int ycoord) {
		return (xcoord - xstart) * slope - (ycoord - ystart) >= 0.0f;
	}
};

std::vector<std::vector<int>> testContainmentOf(const std::vector<std::vector<int>> signals, line l1, line l2, line l3, line l4) {
	std::vector<std::vector<int>> testResult;

	for (int i = 0; i < signals.size(); ++i) {
		testResult.push_back(std::vector<int>());
		for (int j = 0; j < signals[0].size(); ++j) {
			bool contained = l1.sepTest(i,j) && l2.sepTest(i,j) && l3.sepTest(i,j) && l4.sepTest(i,j);
			// signals are 0 - outside, 1 - contained
			int correctness = contained == signals[i][j];
			testResult[i].push_back(correctness);
		}
	}

	return testResult;
}

int main() {
	std::vector<std::vector<int>> box = getBoxInBox(15, 25);

	line l1 {0.0f, 0.0f, 0.5f};
	line l2 {0.0f, 0.0f, 0.2f};
	line l3 {0.0f, 0.0f, 0.3f};
	line l4 {0.0f, 0.0f, 0.1f};

	auto testResults = testContainmentOf(box, l1, l2, l3, l4);

	print(box);

	print(testResults);
	return 0;
}


