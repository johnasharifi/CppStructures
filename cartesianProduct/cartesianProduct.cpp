#include <unordered_map>
#include <iostream>
#include <vector>

template <typename keyType, typename valueType>
std::vector<std::unordered_map<keyType, valueType>> cartesianProductWith(std::unordered_map<keyType, valueType> current, const keyType& key, const std::vector<valueType>& values) {
	std::vector< std::unordered_map<keyType, valueType> > data;

	for (int i = 0; i < (int) values.size(); ++i) {
		data.push_back(current);
	}

	return data;
}

template <typename keyType, typename valueType>
void print(const std::string& header, const std::unordered_map<keyType, valueType>& map) {
	std::cout << header << std::endl;
	for (auto kvp: map) {
		std::cout << "\tkey " << kvp.first << " maps to value " << kvp.second << std::endl;
	}
}

std::vector<int> range(int starti, int endi) {
	std::vector<int> data;
	for (int i = starti; i < endi; ++i) data.push_back(i);
	return data;
}

int main() {
	std::unordered_map<char, int> map;
	std::vector< std::unordered_map<char, int> > products;
	products.push_back(map);
	products[0]['c'] = 10;
	products = cartesianProductWith(products[0], 'c', range(0,10));

	print(std::string("map"), products[0]);
}
