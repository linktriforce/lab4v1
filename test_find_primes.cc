#include "find_primes.h"

#include <cassert>

bool test_find_primes()
{
    std::string toBeInitialized{"PPPPP"};
    initializeString(toBeInitialized);
    assert(toBeInitialized == "CCPPP");

    std::string toBeSetToTwos{"CCPPPPPPPPP"};
    std::string multiplesOfTwo("CCPPCPCPCPC");
    setMultiples(toBeSetToTwos, 2);
    assert(toBeSetToTwos == multiplesOfTwo);

#if 1
    const size_t noPrimes{35};
    std::string inputString(noPrimes, 'P');
    std::string outputString{"CCPPCPCPCCCPCPCCCPCPCCCPCCCCCPCPCCC"};
    findPrimes(inputString);
    assert(inputString == outputString);
#endif

    std::string printerPrimes = printPrimes(inputString, 34);
    assert(printerPrimes == "2 3 5 7 11 13 17 19 23 29 31 ");
    std::string largetsPrime = printLargestPrime(inputString);
    assert(largetsPrime == "31");
    

    return true;
}

int main()
{
    std::cout << std::boolalpha; 
    std::cout << test_find_primes() << std::endl;
    return 1;
}

