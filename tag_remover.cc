#include <string>
#include <iostream>
#include <fstream>

#include "tag_remover.h"

using size_type = std::string::size_type;

void tagRemover(std::string &line)
{
    size_type start_pos;
    size_type end_pos = 0;
    while (!line.empty() && end_pos != std::string::npos)
    {
        start_pos = line.find_first_of('<');
        end_pos = line.find_first_of('>');
        if (end_pos != std::string::npos)
        {
            line.erase(start_pos, end_pos - start_pos + 1);
        }
    }
}

void replaceSign(std::string s, std::string sign, std::string&line)
{
    size_type pos = 0;
    while ((pos = line.find(s, pos)) != std::string::npos)
    {
        line.replace(pos, s.length(), sign);
    }
}

void specialSignRemover(std::string &line)
{
    replaceSign("&lt;", "<", line);
    replaceSign("&gt;", ">", line);
    replaceSign("&nbsp;", " ", line);
    replaceSign("&amp;", "&", line);
}

TagRemover::TagRemover(std::istream &is)
{
    // Read from the input stream (for example, cin)
    std::string line;
    while (std::getline(is, line) && line != "exit")
    {
        tagRemover(line);
        specialSignRemover(line);

        if (!line.empty())
        {
            content += line + "\n"; // Store the input in a member variable (content)
        }
    }
}

void TagRemover::print(std::ostream &os)
{
    // Output the stored content to the output stream (for example, cout)
    os << content;
}

// Write a class that reads a file and removes HTML tags and
//  translates HTML-encoded special characters.
int main()
{
    TagRemover tr(std::cin); // read from cin
    tr.print(std::cout);     // print on cout
    return 0;
}

/* Example input
<html>
<head>
    <title>Test Page</title>
</head>
<body>
    <h1>Welcome to &lt;MySite&gt;</h1>
    <p>This is a test of the TagRemover class.</p>
    <p>Use &amp; for ampersand and &nbsp; for space.</p>
</body>
</html>
*/

/* Output
Welcome to <MySite>
This is a "test" of the TagRemover class.
Use & for ampersand and   for space.
*/