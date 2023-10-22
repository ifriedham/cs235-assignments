#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <fstream>
#include <map>
#include <list>


using namespace std;

int main(int argc, char *argv[]) {
    vector <string> tokens;
    set <string> unique;
    string next_line;  // Each data line
    string fileName = argv[1];
    //string fileName2 = argv[2];
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
    cout << endl;

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


    map<string, string> wordmap_1;
    string last="";
    for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); it++) {
        wordmap_1[last]=*it;
        last = *it;
    }
//part 3
    ofstream mapFile(fileName+"_map.txt");

    for (map<string,string>::iterator it=wordmap_1.begin(); it!=wordmap_1.end(); ++it) {
        mapFile << it -> first << ", " << it -> second << endl;
    }
//part 4
    string state = "";
    for(int i = 0; i < 100; i++){
        cout << wordmap_1[state] << " ";
        state = wordmap_1[state];
    }
    cout << endl;
//part 5
    map<string, vector<string>> wordmap_2;
    state = "";
    for(vector<string>::iterator it=tokens.begin(); it !=tokens.end(); it++) {
        wordmap_2[state].push_back(*it);
        state = *it;
    }

    srand(time(NULL)); // this line initializes the random number generated
    // so you dont get the same thing every time
    state = "";
    for (int i = 0; i < 100; i++) {
        int ind = rand() % wordmap_2[state].size();
        cout << wordmap_2[state][ind] << " ";
        state = wordmap_2[state][ind];
    }
    cout << endl;

    //part 6
    map<list<string>, vector<string>> wordmap_3;
    list<string> states;
    int M = 2; // change the value of this variable to see how your output changes
    for (int i = 0; i < M; i++) {
        states.push_back("");
    }

    for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); it++) {
        wordmap_3[states].push_back(*it);
        states.push_back(*it);
        states.pop_front();
    }

    states.clear();
    for (int i = 0; i < M; i++) {
        states.push_back("");
    }
    for (int i = 0; i < 100; i++) {
        int ind = rand() % wordmap_3[states].size();
        cout << wordmap_3[states][ind]<<" ";
        states.push_back(wordmap_3[states][ind]);
        states.pop_front();
    }



    return 0;
}
