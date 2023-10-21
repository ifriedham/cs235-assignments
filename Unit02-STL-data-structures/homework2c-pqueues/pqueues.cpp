#include <iostream>
#include <string>
#include <queue>

#include "input.h"

using std::cout, std::cin, std::endl;

struct person {
public:
    std::string name;
    int pNum = 0;

    bool operator<(const person &next) const {
        return pNum < next.pNum;
    }
};

int main(int argc, char const *argv[]) {
    // Write your code here
    std::priority_queue<person> line;
    std::string response;
    std::string priority;

    while (true) {
        input("What do you want to do? ", response);

        if (response == "add") {
            person newPerson;
            input("Name: ", newPerson.name);
            input("Priority: ", priority);
            newPerson.pNum = stoi(priority);

            line.push(newPerson);
        } else if (response == "take") {
            if (line.empty()) {
                cout << "There are no more people in line" << endl;
            } else {
                person nextPerson = line.top();
                if (nextPerson.pNum < 10 && nextPerson.pNum >= 0) {
                    cout << "0" << nextPerson.pNum << " - " << nextPerson.name << endl;
                } else {
                    cout << nextPerson.pNum << " - " << nextPerson.name << endl;
                }
                line.pop();
            }
        } else if (response.empty()) {
            return 0;
        } else {
            cout << response << " isn't a valid operation";
        }

    }
}
