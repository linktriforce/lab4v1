#include <sstream>
#include <stdexcept>
#include <string>

#include "date.h"
#include "string_cast_template.h"

int main()
{
    try
    {
        int i = string_cast<int>("123");
        double d = string_cast<double>("12.34");
        Date date = string_cast<Date>("2015-01-10");
        std::cout << i << ", " << d << ", " << date;
    }
    catch (std::invalid_argument &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}