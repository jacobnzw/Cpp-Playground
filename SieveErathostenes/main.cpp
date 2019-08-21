#include <iostream>

#include "sieve.h"

int main()
{
	std::cout << "\nPrimes using bool array:\n";
	auto sieve_array = primes_array();
	for (size_t i = 1; i < sieve_array.size(); ++i)
		if (sieve_array[i] == true)
			std::cout << i << ", ";
	std::cout << "\n"; 

	std::cout << "\nPrimes using bitset:\n";
	auto sieve_bitset = primes_bitset();
	for (size_t i = 1; i < sieve_bitset.size(); ++i)
		if (sieve_bitset[i] == true)
			std::cout << i << ", ";
	std::cout << "\n";

	// std::cout << "size_of(array<bool, 100>): " << sizeof(array<bool, MAX_NUM>) << " bytes\n";
	// std::cout << "size_of(array<bool, 100>): " << sizeof(bitset<MAX_NUM>) << " bytes";
}