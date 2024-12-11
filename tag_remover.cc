#include <string>
#include <iostream>
#include <fstream>

#include "tag_remover.h"

TagRemover::TagRemover(std::istream &is) {
    // Read from the input stream (for example, cin)
    std::string line;
    while (std::getline(is, line)) {
        content += line + "\n";  // Store the input in a member variable (content)
    }
}

void TagRemover::print(std::ostream &os) {
    // Output the stored content to the output stream (for example, cout)
    os << content;
}

int main() {
    TagRemover tr(std::cin);   // read from cin
    tr.print(std::cout);       // print on cout
    return 0;
}