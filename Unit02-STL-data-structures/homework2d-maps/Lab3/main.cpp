#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <fstream>


using namespace std;

int main(int argc, char *argv[]) {
    vector <string> tokens;
    set <string> unique;
    string next_line;  // Each data line
    string fileName = argv[1];
    ifstream in(fileName); //opens file
    while (getline(in, next_line)) {
        istringstream iss(next_line);
        string token;
        while (iss >> token) {
            string nopunct = "";
            for (auto &c: token) { // Remove Punctuation
                if (isalpha(c)) {
                    nopunct += c;
                }
            }
            tokens.push_back(nopunct);
            unique.insert(nopunct);
            // cout << token<<endl;
        }
    }

    cout << "Number of words " << tokens.size() << endl;
    cout << "Number of unique words " << unique.size() << endl;

    ofstream vectorFile(fileName+"_vector.txt");
    ofstream setFile(fileName+"_set.txt");

    for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); ++it) {
        vectorFile << ' ' << *it << std::endl;
    }

    for (set<string>::iterator it = unique.begin(); it != unique.end(); ++it) {
        cout << ' ' << *it;
        setFile << ' ' << *it << std::endl;
    }
    cout << endl;
}
