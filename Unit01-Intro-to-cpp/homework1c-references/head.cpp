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

    /* if (argc > 2) {  // if n is given, change from 10 to new number
        n = atoi(argv[1]);
    } */

    if (argc == 3) {
        std::ifstream input(argv[2]);  // open file

        if (!input.is_open()) {  // input file doesn't exist
            std::cerr << "ERROR: can't open " << argv[2] << std::endl;
            return 1;

        } else {  // file successfuly opened
            n = atoi(argv[1]);
            printLines(n, input);
            input.close();
        }

    } else if (argc == 2) {
        std::ifstream input(argv[1]);  // open file

        if (!input.is_open()) {       // input file doesn't exist
            if (n = atoi(argv[1])) {  // should see if a line count is given?
                printLines(n, std::cin);  // no file provided, printing from cin
            } else {
                std::cerr << "ERROR: can't open " << argv[2] << std::endl;
                return 1;
            }

        } else {  // file successfuly opened
            printLines(n, input);
            input.close();
        }
    }

    else if (argc == 1) {
        printLines(n, std::cin);  // no file provided, printing from cin

    }

    else {
        std::cout << "ERROR, NO ARGUMENTS GIVEN" << std::endl;
        return 2;
    }

    return 0;
}
