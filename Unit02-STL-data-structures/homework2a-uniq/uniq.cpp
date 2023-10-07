#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_set>


int main(int argc, char const *argv[]) {
    std::vector<std::string> rawLines;
    std::vector<std::string> finalLines;
    std::unordered_set<std::string> uniqLines;
    std::string line;

    std::ifstream input(argv[1]); //open input file

    if (!input.is_open()) {  //if input is not a file
        while (std::getline(std::cin, line)) {  //read cin
            if (line.empty()) { break; } // blank line ends input
            else { rawLines.push_back(line); }
        }
    } else { //input is a file
        while (std::getline(input, line)) {
            rawLines.push_back(line);
        }
    }

    for (const std::string &nextLine: rawLines) {  //looking for duplicates
        if (uniqLines.insert(nextLine).second) {
            finalLines.push_back(nextLine);  //writing unique items to new vector
        }
    }

    for (const std::string &nextLine: finalLines) {  // print out list
        std::cout << nextLine << std::endl;
    }


    return 0;
}
