#include <iostream>
// for sort
#include <algorithm>

#include <set>
#include <map>
#include <unordered_map>

void printUmap(const std::unordered_map<int,int> umap) {
	std::cout << "umap (" << umap.size() << "): " << std::endl;

	for (auto kvp: umap) {
		std::cout << "\t" << kvp.first << ": " << kvp.second << std::endl;
	}

	std::cout << std::endl;
}

void printSet(const std::set<int> set) {
	std::cout << "set (" << set.size() << "): ";
	for (int i: set) {
		std::cout << i << ", ";
	}
	std::cout << std::endl;
}

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
	
	// set erase by value
	std::set<int> myset;
	const int len = 3;
	for (int i = 0; i < len; ++i)
		myset.insert(i * i * len);

	printSet(myset);
	myset.erase((len-1)*(len-1) * len);
	printSet(myset);
	
	// unordered map erase by value
	std::unordered_map<int,int> umap_erase;
	umap_erase[0] = 10;
	umap_erase[1] = 100;
	umap_erase[2] = 1000;

	printUmap(umap_erase);

	umap_erase.erase(0);
	umap_erase.erase(2);

	printUmap(umap_erase);

	
	return 0;
}
