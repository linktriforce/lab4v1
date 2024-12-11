#include "find_primes.h"

void findPrimes(std::string& s) {
    initializeString(s);

    auto start = s.find_first_of('P');
    do {
        if(s[start] == 'P') {
            setMultiples(s, start);
        }
        ++start;
    } while (start < s.length());
}

void initializeString(std::string& s) {
    if(s.length() > 2) {
        std::transform(s.begin(), s.begin() + 2, s.begin(), [](char){return 'C';});
    }
}

void setMultiples(std::string& s, size_t n) {
    for(size_t i = 2*n ; i < s.length() ; i += n) {
        s[i] = 'C';
    }
}

std::string printPrimes(const std::string& s, size_t n) {
    std::string toPrint;
    for(size_t i = 0; i < (n < s.length() ? n : s.length()); ++i) {
        if(s[i] == 'P') {
            toPrint.append(std::to_string(i));
            toPrint.append(" ");
        }
    }

    return toPrint;
}

std::string printLargestPrime(const std::string& s) {
    auto index = s.find_last_of('P');
    return std::to_string(index);
}