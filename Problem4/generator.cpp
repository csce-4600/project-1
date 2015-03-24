#include <iostream>
#include <chrono>
#include <random>
#include "generator.h"

using namespace std;

long generator::rand_num_between(long lbound, long ubound) {

	// construct a trivial random generator engine from a time-based seed:
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	default_random_engine generator (seed);
	uniform_int_distribution<long> distribution(lbound, ubound);

	return distribution(generator);

}