#include <unordered_map>
#include <iostream>
#include <vector>

template <typename keyType, typename valueType>
std::unordered_map<keyType, valueType> cartesianProductWith(std::unordered_map<keyType, valueType> current, const keyType& key, const std::vector<valueType>& values) {
	return current;
}

template <typename keyType, typename valueType>
void print(const std::string& header, const std::unordered_map<keyType, valueType>& map) {
	std::cout << header << std::endl;
	for (auto kvp: map) {
		std::cout << "\tkey " << kvp.first << " maps to value " << kvp.second << std::endl;
	}
}

int main() {
	std::cout << "test" << std::endl;

	std::unordered_map<char, int> map;
	map['a'] = 30;
	std::unordered_map<char, int> map2 = map;

	std::unordered_map<char, int> clone = cartesianProductWith(map, '0', std::vector<int>());
	map['c'] = 10;

	print(std::string("map"), map);
	print(std::string("map2"), map2);
	print(std::string("clone"), clone);
	// std::cout << "map2 value at 'c' is " << map2['c'] << std::endl;

	// std::cout << "clone map value at 'c' is " << clone['c'] << std::endl;
}
