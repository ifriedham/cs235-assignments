#include <iostream>
#include <string>

void sort(std::string& a, std::string& b, std::string& c) {
    // implement sort here
    std::string temp;

    if (a > b){
        temp = a;
        a = b;
        b = temp;
    }
    
    if (b > c){
        temp = b;
        b = c;
        c = temp;
    }

   if (a > b){
        temp = a;
        a = b;
        b = temp;
    }

}

int main(int argc, char const* argv[]) {
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " a b c" << std::endl;
        return 1;
    }

    std::string a = argv[1];
    std::string b = argv[2];
    std::string c = argv[3];

    sort(a, b, c);

    std::cout << a << ' ' << b << ' ' << c << std::endl;

    return 0;
}
