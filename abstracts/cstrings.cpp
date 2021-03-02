#include <iostream>
#include <string>
#include <sstream>

// for all of the s to <T> functions
#include <stdio.h>
// for the c string's strtok
#include <string.h>

int main() {
	std::string initData = "200f 1234 365.24";
	// std::string.c_str() returns a const char*
	// so have to cast to char*
	char* charData = (char*) initData.c_str();

	int counter = 0;
	char* head = strtok(charData, " ");
	// can provide multiple delimiters in second arg
	while (head != nullptr) {
		switch(counter) {
			case 0: 
				std::cout << "array " << head << " as float is " << std::stof(head) << std::endl;
				// stof returns float
				break;
			case 1:
				std::cout << "array " << head << " as int is " << std::stoi(head) << std::endl;
				// stoi returns int
				break;
			case 2:
				std::cout << "array " << head << " as double is " << std::stod(head) << std::endl;
				// stod returns double
				break;
		}
		// when nullptr is provided as first arg, scan restarts on previous string...
		head = strtok(nullptr, " ");
		counter++;
		// note different iteration order. we do the op, then we increment our pointer
	}
	return 0;
}
