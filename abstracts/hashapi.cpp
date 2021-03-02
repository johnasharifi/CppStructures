#include <iostream>
// for sort
#include <algorithm>

#include <set>
#include <map>
#include <unordered_map>

int main() {
	std::set<int> set;
	std::map<int,int> map;
	std::unordered_map<int,int> umap;

	const int len = 10;
	for (int i = 0; i < len; ++i) {
		// O(1)
		set.insert(i);

		// O(n log n) due to rb tree
		map[i] = i * i;

		// O(1)
		umap[i] = i * i;

		// O(1)
		bool setContains = set.count(i) > 0;
		// O(n log n)
		bool mapContains = map.count(i) > 0;
		// O(1)
		bool umapContains = map.count(i) > 0;

		std::cout << "for i " << i << ": in set? " << setContains << ". in map? " << mapContains << ". in umap? " << umapContains << std::endl;	
	}

	// key-value iteration

	std::map<int, float> distances;
	distances[0] = 10.0f;
	distances[1] = 20.0f;
	distances[2] = 30.0f;

	for (auto kvp : distances) {
		std::cout << "key " << kvp.first << " has value " << kvp.second << std::endl;
	}

	return 0;
}
