#include <iostream>
#include <string>
#include <vector>
#include <fstream>


void sort(std::vector<std::string>& item) {
    int n = item.size();

    for (int i = 1; i < n; ++i) {
        int next_pos = i;
        std::string next_val = item[i];
        while (next_pos > 0 && next_val < item[next_pos - 1]){
            item[next_pos] = item[next_pos - 1];
            next_pos = next_pos - 1;
        }
        item[next_pos] = next_val;
    }
}

void print(const std::vector<std::string>& inputs) {
    for (const auto & line : inputs) {
        std::cout << line << std::endl;
    }
}


int main(int argc, char const *argv[]) {
    // Write your code here
    if (argc > 1) {  // read from file
        std::ifstream inputFile(argv[1]);
        if (!inputFile) {  // can't open file
            std::cerr << "ERROR: Unable to open input file!" << std::endl;
            return 1;
        }

        std::vector<std::string> inputs;
        std::string newInput;

        while (std::getline(inputFile, newInput)) {
            inputs.push_back(newInput);
        }

        sort(inputs);
        print(inputs);


    } else {  // read from cin
        std::vector<std::string> inputs;
        std::string newInput;

        while (std::getline(std::cin, newInput)) {
            inputs.push_back(newInput);
        }

        sort(inputs);
        print(inputs);
    }


    return 0;
}
