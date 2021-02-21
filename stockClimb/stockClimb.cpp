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

int main() {
	std::vector<float> data = getRandom(10);
	print(data);

	return 0;
}
