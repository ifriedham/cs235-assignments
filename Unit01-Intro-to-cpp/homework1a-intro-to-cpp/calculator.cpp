#include <iostream>
#include <string>

std::string input(std::string prompt)
{
    std::cout << prompt;
    std::cout.flush();
    std::string response;
    std::getline(std::cin, response);
    return response;
}

int main(int argc, char const *argv[])
{
    // std::string operation;
    int left, right;

    while (true)
    {
        std::string operation = input("operation: ");

        if (operation.empty())
        {
            return 0;
            //break;
        }

        else if (operation == "add" || operation == "subtract" || operation == "multiply" || operation == "divide" || operation == "mod")
        {
            std::cout << "left operand: ";
            std::string leftStr = input("");
            std::cout << "right operand: ";
            std::string rightStr = input("");

            // Convert input strings to integers
            left = std::stoi(leftStr);
            right = std::stoi(rightStr);

            if (operation == "add")
            {
                std::cout << left + right << std::endl;
            }

            else if (operation == "subtract")
            {
                std::cout << left - right << std::endl;
            }

            else if (operation == "multiply")
            {
                std::cout << left * right << std::endl;
            }

            else if (operation == "divide")
            {
                std::cout << left / right << std::endl;
            }

            else if (operation == "mod")
            {
                std::cout << left % right << std::endl;
            }
        }

        else
        {
            std::cout << operation << " isn't a valid operation" << std::endl;
        }
    }
}
