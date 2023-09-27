#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
    int div = atoi(argv[3]);
    
    if (start <= end) {
        for (int i = start; i <= end; i++){
            if (i % div == 0){
                std::cout << i << std::endl;
            }
        }
    } 

    else{
        for (int i = start; i >= end; i--){
            if (i % div == 0){
                std::cout << i << std::endl;
            }
        }
    }

    return 0;
}
