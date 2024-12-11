#include <string>
#include <iostream>
#include <fstream>

#include "tag_remover.h"

TagRemover::TagRemover(std::istream &is) {
    // Read from the input stream (for example, cin)
    std::string line;
    while (std::getline(is, line) && line != "exit") { 
        auto start_pos = line.find_first_of('<');
        auto end_pos = line.find_last_of('>');
        if (end_pos != std::string::npos) {
            line = line.substr(start_pos + 1, end_pos - 1);
        }
        //Find special characters 

        content += line + "\n";  // Store the input in a member variable (content)
    }
}

void TagRemover::print(std::ostream &os) {
    // Output the stored content to the output stream (for example, cout)
    os << content;
}


//Write a class that reads a file and removes HTML tags and 
// translates HTML-encoded special characters.
int main() {
    TagRemover tr(std::cin);   // read from cin
    tr.print(std::cout);       // print on cout
    return 0;
}

/* Example input
<html>
<head>
    <title>Test Page</title>
</head>
<body>
    <h1>Welcome to &lt;MySite&gt;</h1>
    <p>This is a &quot;test&quot; of the TagRemover class.</p>
    <p>Use &amp; for ampersand and &nbsp; for space.</p>
</body>
</html>
*/

/* Output
Welcome to <MySite>
This is a "test" of the TagRemover class.
Use & for ampersand and   for space.
*/