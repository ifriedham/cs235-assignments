#include <iostream>
#include <string>
#include <fstream>

#include "Grid.h"

using std::endl, std::cerr;

int main(int argc, char* argv[]) {
    // Write your code here
    std::ifstream inFile(argv[1]);  // open input file
    if(!inFile){ // failed to open file
        cerr << "ERROR: Unable to open input file!" << endl;
        return 1;
    }

    // write maze from input file to newMaze
    Grid newMaze;
    inFile >> newMaze;
    inFile.close();






    //success!

    //failed


    return 0;
}
