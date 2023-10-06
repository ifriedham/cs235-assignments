#include <fstream>
#include <iostream>
#include <sstream>
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

bool isNumber(const std::string& str) {
    std::istringstream iss(str);
    int n;
    return (iss >> n) && iss.eof();
}

int main(int argc, char const* argv[]) {
    // Write your code here

    int n = 10;  // set default n

    if (argc > 2) {
        n = atoi(argv[1]);  // if n is given, change from 10 to new number
        std::ifstream input(argv[2]);  // open file

        if (!input.is_open()) {  // check if input file exists
            std::cerr << "ERROR: can't open " << argv[2] << std::endl;
            return 1;
        }

        printLines(n, input);
        input.close();
    }

    if (argc == 2) {
        const std::string argument = argv[1];
        if (isNumber(
                argument)) {  // checks if argument is # of lines or a filename
            printLines(n, std::cin);  // no file provided, printing from cin
        }

        else {
            std::ifstream input(argv[1]);  // open file

            if (!input.is_open()) {  // check if input file exists
                std::cerr << "ERROR: can't open " << argv[1] << std::endl;
                return 1;
            }

            printLines(n, input);
            input.close();
        }
    }

    if (argc == 1) {
        printLines(n, std::cin);  // no file provided, printing from cin
    }

    return 0;
}
