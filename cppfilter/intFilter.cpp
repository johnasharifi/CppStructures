#include <iostream>

class TreeFilter {
	public:
		TreeFilter* ltree;
		TreeFilter* rtree;
		bool isContainer;

		void insert(int v) {
			// set up vars
			int ones = v & (1 << 0);
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
			int ones = v & (1 << 0);
			bool hasRemainder = v > 1;

			if (hasRemainder) {
				if (ones == 0 && ltree == nullptr) return false;
				if (ones == 0) return ltree->contains(v / 2);
				if (ones == 1 && rtree == nullptr) return false;
				if (ones == 1) return rtree->contains(v / 2);
			}
			return isContainer;
		}

		void release() {
			if (ltree != nullptr) { ltree->release(); delete ltree; }
			if (rtree != nullptr) { rtree->release(); delete rtree; }
		}

		~TreeFilter() {
			if (ltree != nullptr) delete ltree;
			if (rtree != nullptr) delete rtree;
		}

};

int main() {
	TreeFilter* filter = new TreeFilter;
	for (int i = 0; i < 10; ++i) filter->insert(i);
	for (int i = 0; i < 10 * 2; ++i) {
		std::cout << "filter contains " << i << "? " << filter->contains(i) << std::endl;
	}

	delete filter;
}



