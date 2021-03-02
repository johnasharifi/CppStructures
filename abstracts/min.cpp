#include <iostream>

int main() {
	int v1 = -5; int v2 = +7;

	for (int i = 0; i < 10; ++i) {
		int minDist = std::min(abs(i - v1), abs(i - v2));
		std::cout << "min distance from " << i << " to " << v1 << " or " << v2 << ": " << minDist << std::endl;
	}

	return 0;
}
