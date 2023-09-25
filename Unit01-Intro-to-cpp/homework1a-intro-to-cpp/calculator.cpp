#include <iostream>
#include <string>
using namespace std;

std::string input(std::string prompt) {
    std::cout << prompt;
    std::cout.flush();
    std::string response;
    std::getline(std::cin, response);
    return response;
}

int main(int argc, char const* argv[]) {

    string op;
    cout << "operation: ";
    cin >> op;

    // add
    if (op == "add") {
        cout << "YAY ADD";
    }

    
    //subtract
    else if (op == "subtract"){
        cout << "YAY SUBTRACT";
    }


    //multiply
    else if (op == "subtract"){
        cout << "YAY SUBTRACT";
    }


    //divide
    else if (op == "subtract"){
        cout << "YAY SUBTRACT";
    }

    
    //mod (modulus)
    else if (op == "subtract"){
        cout << "YAY SUBTRACT";
    }


    return 0;
}
