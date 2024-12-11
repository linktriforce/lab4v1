#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

/**
 * Takes the input std::string and sets all non-primes to 'C'.
 */
void findPrimes(std::string& s);

/**
 * If the string is 2 characters or longer, sets the first two characters to 'C'
 */
void initializeString(std::string& s);

void setMultiples(std::string& s, size_t n);

std::string printPrimes(const std::string& s, size_t n);

std::string printLargestPrime(const std::string& s);