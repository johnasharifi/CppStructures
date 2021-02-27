#include <iostream>

class TreeFilter {
	public:
		TreeFilter* ltree;
		TreeFilter* rtree;
		bool isContainer;

		void insert(int v) {
			// set up vars
			int ones = v & (1 << 1);
			bool hasRemainder = v > 1;

			if (hasRemainder) {
				if (ones == 0 && ltree == nullptr) ltree = new TreeFilter;
				if (ones == 0) ltree->insert(v / 2);
				if (ones == 1 && rtree == nullptr) rtree = new TreeFilter;
				if (ones == 1) rtree->insert(v / 2);
			}
			else {
				isContainer = true;
			}
		}
		bool contains(int v) {
			int ones = v & (1 << 1);
			bool hasRemainder = v > 1;

			if (hasRemainder) {
				if (ones == 0 && ltree == nullptr) return false;
				if (ones == 0) return ltree->contains(v / 2);
				if (ones == 1 && rtree == nullptr) return false;
				if (ones == 1) return rtree->contains(v / 2);
			}
			else return isContainer;
		}

};

int main() {

}
