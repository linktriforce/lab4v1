#include "find_primes.h"

const size_t noPrimes = 100000;


int main() {
    std::string primeString(noPrimes, 'P');
    findPrimes(primeString);

    std::cout << printPrimes(primeString, 200) << std::endl;
    std::cout << printLargestPrime(primeString) << std::endl;
}