#include <iostream>
#include <string>
#include <fstream>

#include "Grid.h"

using std::endl, std::cerr, std::vector, std::string, std::to_string;


bool solveMaze(Grid &maze, int row, int col, int lvl, vector<string> &solution) {
    // checks if spot is the goal
    if (row == maze.height() - 1 && col == maze.width() - 1 && lvl == maze.depth() - 1) {
        solution.push_back(to_string(row) + " " + to_string(col) + " " + to_string(lvl));
        return true;
    }

    // spot is out of bounds or is a wall
    if (row < 0 || col < 0 || lvl < 0 || row >= maze.height() || col >= maze.width() || lvl >= maze.depth() || maze.at(row, col, lvl) == 0) {
        return false;
    }

    // Spot is valid -> leaves breadcrumb (val:0)
    maze.at(row, col, lvl) = 0;

    // explore adjacent spots
    if (solveMaze(maze, row - 1, col, lvl, solution) || // y +
        solveMaze(maze, row + 1, col, lvl, solution) || // y -
        solveMaze(maze, row, col - 1, lvl, solution) || // x -
        solveMaze(maze, row, col + 1, lvl, solution) || // x +
        solveMaze(maze, row, col, lvl - 1, solution) || // z +
        solveMaze(maze, row, col, lvl + 1, solution)) // z -
    {
        solution.push_back(to_string(row) + " " + to_string(col) + " " + to_string(lvl));
        return true;
    }

    // no path from spot
    return false;
}

int main(int argc, char *argv[]) {
    // Write your code here
    if (argc != 3){  // incorrect usage
        cerr << "ERROR: must provide input and output file!" << endl;
        return 1;
    }

    std::ifstream inFile(argv[1]);  // open input file

    if (!inFile) { // failed to open file
        cerr << "ERROR: Unable to open input file!" << endl;
        return 1;
    }

    // write maze from input file to newMaze
    Grid newMaze;
    inFile >> newMaze;
    inFile.close();

    // open output file for writing
    std::ofstream outputFile(argv[2]);
    if (!outputFile) {
        cerr << "ERROR: Unable to open output file!" << endl;
        return 1;
    }

    vector<string> mazeSolution;

    if (solveMaze(newMaze, 0, 0, 0, mazeSolution)) { // maze solved
        outputFile << "SOLUTION";
        for (int i = mazeSolution.size(); i != -1; i--) {
            outputFile << mazeSolution[i] << endl;
        }


    } else outputFile << "NO SOLUTION" << endl;  // failed to solve maze

    return 0;
}
