#include "to_string_template.h"
// #include "date.h"

bool testToString() {
    double d{1.234};
    

    std::string ds = toString(d);
    
    std::cout << "toString used on a double: " << "\n";
    std::cout << ds << "\n";

    std::vector<int> vint{1,2,3,3,4,6,7,8};
    std::cout << "toString used on a vector<int>:" << "\n";
    std::cout << toString(vint) << std::endl;
    
#if 0
    //TODO: To be done when A3 has been done. Make sure to include date.h
    Date today;
    std::string dateString = toString(today);
    std::cout << "toString used on a Date" << "\n";
    std::cout << dateString << std::endl;
#endif
    return true;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << testToString();
}