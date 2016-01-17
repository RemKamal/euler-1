// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 4
// Largest prime factor

#include "common.hpp"

namespace problem_04 {

int solve() {
	int largest = 0;
	for (int i = 100; i < 1000; ++i) {
		for (int j = 100; j < 1000; ++j) {
			int prod = i * j;
			if (common::is_palindrome(prod) && prod > largest) {
				largest = prod;
			}
		}
	}
	return largest;
}

} // namespace problem_04
