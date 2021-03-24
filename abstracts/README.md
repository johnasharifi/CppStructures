Common errors:

- referred to wrong namespace. always use std::t
- compared to null, wanted nullptr
- incremented wrong variable in a for loop
- map is sorted - some ops are O(nlogn). unordered_map is unsorted
- set is sorted - some ops are O(nlogn). hashset is unsorted

Common strategies:

- break problem down into smaller sub-problems
- save results of one small atomic search, take max/min of results of n searches
