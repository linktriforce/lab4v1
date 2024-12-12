#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using std::string;

template <typename T>
string toString(const T& t) {
    std::ostringstream out;
    out << t;
    return out.str();
}

template <typename T>
string toString(const std::vector<T>& v) {
    std::ostringstream out;
    for(const auto& t : v) {
        out << t << " ";
    }
    return out.str();
}
