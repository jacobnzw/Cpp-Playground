#include <array>
#include <bitset>

#define MAX_NUM 10000

// 
// Sieve of Erathosthenes for prime number search
// 

std::array<bool, MAX_NUM + 1> primes_array();

std::bitset<MAX_NUM + 1> primes_bitset();


std::array<bool, MAX_NUM+1> primes_array()
{
	// set all elements of the sieve array to 1
	std::array<bool, MAX_NUM+1> sieve;
	for (auto& el : sieve)
		el = true;
	
	// for (auto el : sieve)
	// 	cout << el << "\n";

	for (size_t i = 2; i < MAX_NUM+1; ++i)
	{
		for (size_t j = i+1; j < MAX_NUM+1; ++j)
		{
			if (j % i == 0)
			{
				sieve[j] = false;
			}

		}
	}

	return sieve;
}

std::bitset<MAX_NUM+1> primes_bitset()
{
	std::bitset<MAX_NUM+1> sieve;
	sieve.set();  // set all bits to 1

	for (size_t i = 2; i < MAX_NUM+1; ++i)
	{
		for (size_t j = i+1; j < MAX_NUM+1; ++j)
		{
			if (j % i == 0)
			{
				sieve.reset(j); // set j-th bit to 0
			}

		}
	}

	return sieve;
}
