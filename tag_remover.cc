#include <string>
#include <iostream>
#include <fstream>

#include "tag_remover.h"

using size_type = std::string::size_type;

void tagRemover(std::string &line, bool &in_tag)
{
    size_type start_pos = 0;
    size_type end_pos = 0;
    while (!line.empty() && end_pos != std::string::npos)
    {
        start_pos = line.find_first_of('<');
        end_pos = line.find_first_of('>');
        if (start_pos != std::string::npos || in_tag)
        {
            //När tagen fortsätter på nästa rad
            if (start_pos != std::string::npos && start_pos > end_pos)
            {
                line.erase(0, end_pos + 1);
                in_tag = false;
            }
            //När en hel tag finns i en rad
            else if (end_pos != std::string::npos && end_pos != std::string::npos)
            {
                line.erase(start_pos, end_pos - start_pos + 1);
                in_tag = false;
            }
            else
            {
                //Första fallet, '<', ta bort allt efter.
                //Andra fallet om inte taggen stängts, ta bort hela raden.
                line.erase(start_pos != std::string::npos ? start_pos : 0);
                in_tag = true;
            }
        }
    }
}

void replaceSign(std::string s, std::string sign, std::string &line)
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
    bool in_tag;
    while (std::getline(is, line) && line != "exit")
    {
        tagRemover(line, in_tag);
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