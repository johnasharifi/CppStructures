#include <stdlib.h>
#include <time.h>
#include <iostream>

int main() {
	std::cout << "test" << std::endl;
	srand(time(NULL));

	for (int i = 0; i < 10; ++i) 
		std::cout << "rand " << (rand() % 100) << std::endl;

	return 0;
}
