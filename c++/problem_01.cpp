// Copyright 2016 Mitchell Kember. Subject to the MIT License.
// Project Euler: Problem 1
// Multiples of 3 and 5

namespace problem_01 {

int arith_sum(int d) {
	int n = 999 / d;
	return d * n * (n + 1) / 2;
}

int solve() {
	return arith_sum(3) + arith_sum(5) - arith_sum(15);
}

} // namespace problem_01
