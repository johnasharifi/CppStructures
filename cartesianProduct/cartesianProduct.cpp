#include <unordered_map>
#include <iostream>
#include <vector>

template <typename keyType, typename valueType>
std::vector<std::unordered_map<keyType, valueType>> cartesianProductWith(std::unordered_map<keyType, valueType> current, const keyType& key, const std::vector<valueType>& values) {
	std::vector< std::unordered_map<keyType, valueType> > data;

	// TODO do ij iteration through a vector of maps and a range of values here
	for (int i = 0; i < (int) values.size(); ++i) {
		data.push_back(current);
		data[i][key] = values[i];
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
	std::string keys("test");
	std::vector<int> points = range(0,5);

	// set up our seed generation 
	std::unordered_map<char, int> map;
	std::vector< std::unordered_map<char, int> > products;
	products.push_back(map);

	// iterate through a cartesian product generations
	std::vector <std::unordered_map<char, int> > nextProduct = cartesianProductWith(map, 'c', range(0,5));
	for (int i: range(0,5)) {
		print(std::string("nextProduct " + std::to_string(i)), nextProduct[i]);
	}


	print(std::string("map"), products[0]);
}
