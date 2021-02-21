#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
#include <time.h>

template <class T>
void print(const std::vector<T> gains) {
	for (T v: gains) {
		std::cout << v << std::endl;
	}
}

std::vector<float> getRandom(int len) {
	srand(time(NULL));
	std::vector<float> data;
	float scale = 0.2f;
	for (int i = 0; i < len; ++i) {
		float cent = (rand() % 100) * 0.01f;
		float step = (1 - scale) + cent * (2 * scale);
		data.push_back(step);
	}
	return data;
}

std::vector<int> getDecisions(const std::vector<float> percentChanges) {
	// supposing we had perfect market information, and we could decide what to do on each day
	// decide whether to buy with all our money, sell all our stock, or do nothing each day
	
	std::vector<int> decisions;
	bool hasMoney = true;
	const float threshold = 1.0f;

	for (float v: percentChanges) {
		if (hasMoney && v >= threshold) {
			decisions.push_back(+1);
			hasMoney = false;
		}
		else if (!hasMoney && v <= threshold) {
			decisions.push_back(-1);
			hasMoney = true;
		}
		else decisions.push_back(0);
	}

	return decisions;
}

int main() {
	std::vector<float> data = getRandom(10);
	print(data);

	std::vector<int> decisions = getDecisions(data);
	print(decisions);

	return 0;
}
