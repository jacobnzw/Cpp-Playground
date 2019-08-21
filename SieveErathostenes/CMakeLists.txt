cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

project(sieve)

add_executable(
	main
	main.cpp
	sieve.h
)


project(benchmarks)
add_executable(
	benchmark
	benchmark.cpp
	sieve.h
)
