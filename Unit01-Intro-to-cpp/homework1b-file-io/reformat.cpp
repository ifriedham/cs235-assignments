#include <iostream>
#include <string>
using std::endl, std::cerr, std::string;
#include <fstream>
using std::ifstream, std::ofstream;

int main(int argc, char const *argv[])
{

    if (argc < 4) // checks for proper arguments in command line
    {
        cerr << "This program needs an input file, output file, points, and factor" << endl;
        exit(1);
    }

    ifstream infile(argv[1]); // open input.txt
    if (!infile.is_open())
    {
        cerr << "Unable to open file for reading: " << argv[1] << endl;
        exit(2);
    }

    ofstream outfile(argv[2]); // open output.txt
    if (!outfile.is_open())
    {
        cerr << "Unable to open file for writing: " << argv[2] << endl;
        exit(3);
    }

    string firstName;
    string lastName;
    int points;
    double factor;

    while (infile >> firstName >> lastName >> points >> factor)
    {

        outfile << lastName << ", " << firstName << ": " << factor * points << endl;
    }

    infile.close();
    outfile.close();

    return 0;
}
