#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using std::string, std::cout, std::cerr, std::endl, std::ifstream, std::stringstream;

int count_words(string line)
{
    stringstream ss(line);
    int count = 0;
    string token;
    while (ss >> token)
    {
        count++;
    }
    return count;
}

int main(int argc, char const *argv[])
{

    if (argc < 2) //checks too few arguments
    {
        cerr << "Not enough arguments" << endl;
        return 1;
    }

    if (argc > 2) //checks for too many arguments
    {
        cerr << "Too many arguments" << endl;
        return 2;
    }


    string input_file(argv[1]);
    ifstream input(argv[1]);

    if (!input.is_open()) //checks successful file opening
    {
        cerr << "Unable to open input file: " + input_file << endl;
        return 3;
    }

    string line;
    string longestLine;
    int wordCount = 0;

    while (getline(input, line))
    {
        int count = count_words(line);

        if (count > wordCount){
            wordCount = count;
            longestLine = line;
        }
    }

    cout << longestLine;

    input.close();

    return 0;
}
