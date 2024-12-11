#include <string>
#include <iostream>

class TagRemover {
private:
    std::string content; // This will store the HTML/content read from the stream
public:
    TagRemover(std::istream &is);  // Constructor that takes an input stream
    void print(std::ostream &os);   // Method to print to an output stream
};