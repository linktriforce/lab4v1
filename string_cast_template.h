#include <string>

template <typename T>
T string_cast(const std::string& str) {
    std::istringstream iss(str);
    T obj;
    iss >> obj;
    return obj;
}