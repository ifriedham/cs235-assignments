#include <fstream>
#include <iostream>
#include <string>

void printLines(const int& number, std::istream& ins) {
    std::string line;
    int count = 0;

    while (getline(ins, line)) {
        if (count < number) {
            std::cout << line << std::endl;
            count++;
        }
    }
}

int main(int argc, char const* argv[]) {
    // Write your code here
    int n = 10;  // set default n

    if (argc > 1) {  // if n is given, change from 10 to new number
        n = atoi(argv[1]);
    }

    if (argc > 2) {
        std::ifstream input(argv[2]);  // open file

        if (!input.is_open()) {  // input file doesn't exist
            std::cerr << "ERROR: can't open " << argv[2] << std::endl;
            return 1;

        } else {  // file successfuly opened
            printLines(n, input);
            input.close();
        }

    } else {  // no file provided, printing from cin
        printLines(n, std::cin);
    }

    return 0;
}
