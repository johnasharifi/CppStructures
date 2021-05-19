#include <unordered_map>
#include <iostream>
#include <vector>

template <typename keyType, typename valueType>
std::vector<std::unordered_map<keyType, valueType>> cartesianProductWith(const std::vector< std::unordered_map<keyType, valueType> >& currentGeneration, const keyType& key, const std::vector<valueType>& values) {
	std::vector< std::unordered_map<keyType, valueType> > nextGeneration;

	// do ij iteration through a vector of maps and a range of values here
	for (int i = 0; i < (int) currentGeneration.size(); ++i) {
		for (int j = 0; j < (int) values.size(); ++j) {
			nextGeneration.push_back(currentGeneration[i]);
			nextGeneration[nextGeneration.size() - 1][key] = values[j];
			std::cout << "to vec " << i << " attached value " << values[j] << " for total len " << nextGeneration[i].size() << std::endl;
		}
	}
	return nextGeneration;
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

	// iterate through a cartesian product generation
	products = cartesianProductWith(products, 'c', points);
	// iterate through a second cartesian product generation
	products = cartesianProductWith(products, 'd', points);

	for (int i = 0; i < (int) products.size(); ++i) {
		print(std::string("nextProduct " + std::to_string(i)), products[i]);
	}
}
