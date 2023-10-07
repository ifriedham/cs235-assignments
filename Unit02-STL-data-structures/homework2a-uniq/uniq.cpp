#include <iostream>
#include <string>
#include <fstream>
#include <list>
using std::list;

int main(int argc, char const *argv[]) {
    // Write your code here
    list<std::string> rawLines;
    std::string line;

    std::ifstream input(argv[1]); //open input file

    if (!input.is_open()) {  //if input is not a file
        while (std::getline(std::cin, line)){
            rawLines.push_back(line);
        }
    } else { //input is a file
        while (std::getline(input, line)) {

        }
    }


    return 0;
}
