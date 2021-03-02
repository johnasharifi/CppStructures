#include <iostream>
// for sort
#include <algorithm>

#include <vector>
#include <stack>
#include <queue>

// pointer to a vector
void mysort(std::vector<int>* vec_ptr) {
	// note: std::sort works with an iterator to vector begin and end
	std::sort((*vec_ptr).begin(), (*vec_ptr).end());
}

int main() {
	const int len = 10;

	std::vector<int> vec;
	for (int i = 0; i < len; ++i) {
		vec.push_back(i);
		std::cout << "added " << i << ". vec size is now " << vec.size() << std::endl;

		// remove vec[3] aka 4th element
		if (vec.size() > 5) {
			std::cout << "removing an element" << std::endl;
			vec.erase(vec.begin() + 3);
		}		
	}
	mysort(&vec);

	std::queue<int> queue;
	for (int i = 0; i < len; ++i) {
		// push, queue, pop
		queue.push(i);
		int top = queue.front();
		queue.pop();

		std::cout << "added " << i << ", dequeued top " << top << ". size: " << queue.size () << std::endl;
	}

	std::stack<int> stack;
	for (int i = 0; i < len; ++i) {
		// push, top, pop
		stack.push(i);
		int top = stack.top();
		
		if (i % 2 == 0) {
			stack.pop();
			std::cout << "popped off stack: " << top << std::endl;
		}
		std::cout << "pushed " << i << ". size is now " << stack.size() << std::endl;
	}

	return 0;
}
