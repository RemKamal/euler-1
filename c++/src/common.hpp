// Copyright 2016 Mitchell Kember. Subject to the MIT License.

#pragma once

#include <gmpxx.h>

#include <fstream>
#include <string>
#include <vector>

namespace common {

constexpr long n_powers_of_ten = 10;
constexpr long powers_of_ten[n_powers_of_ten] = {
	1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000
};


long min(long a, long b);
long max(long a, long b);
long gcd(long a, long b);
void reduce_fraction(long& num, long& den);
long n_digits(long n);
bool is_triangular(long n);
bool is_palindrome(long n);
bool is_palindrome_binary(long n);
bool is_prime(long n);
bool is_prime_fast(long n);
long nth_prime(long n);
long sum_primes_below(long n);
long n_divisors(long n);
long largest_prime_divisor(long n);
long sum_proper_divisors(long n);
long combinations(long n, long k);

long sum_of_digits(const mpz_class& n);

long word_value(const std::string& word);

class word_file final {
public:
	word_file(const std::string& filename);

	std::vector<std::string> read();

	class iterator;
	iterator begin();
	iterator end();

	class iterator :
			public std::iterator<std::output_iterator_tag, std::string> {
	public:
		iterator(std::ifstream& fs, bool finished);

		std::string operator*() const;
		iterator& operator++();
		bool operator==(const iterator& rhs) const;
		bool operator!=(const iterator& rhs) const;

	private:
		std::ifstream& _fs;
		bool _finished;
	};

private:
	std::ifstream _fs;
};

} // namespace common
