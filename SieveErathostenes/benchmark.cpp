#include <chrono>
#include <iostream>

#include "sieve.h"

class Timer
{
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_Start;

public:
	Timer()
	{
		m_Start = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		Stop();
	}

	void Stop()
	{
		auto endTime = std::chrono::high_resolution_clock::now();
		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_Start).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTime).time_since_epoch().count();
		
		auto duration_us = end - start;
		double duration_ms = duration_us / 1000;
		
		std::cout << duration_us << "us (" << duration_ms << "ms)\n";
	}
	
};


int main()
{
	static std::array<bool, MAX_NUM+1> sieve_array;
	static std::bitset<MAX_NUM+1> sieve_bitset;

	std::cout << "Benchmarking Sieve of Erathosthenes (primes < " << MAX_NUM << ")\n";
	{
		std::cout << "Using array<bool>: ";
		Timer t;
		sieve_array = primes_array();
	}
	std::cout << "Used storage [KiB]: " << sizeof(sieve_array) / 1024 << "\n";

	{
		std::cout << "Using bitset<>: ";
		Timer t;
		sieve_bitset = primes_bitset();
	}
	std::cout << "Used storage [KiB]: " << sizeof(sieve_bitset) / 1024 << "\n";
}