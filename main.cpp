#include <iostream>
#include <string>
#include <cctype>

bool isSingleWord(const std::string& input) {
    for (std::string::size_type i = 0; i < input.length(); ++i) {
        if (!std::isspace(input[i])) {
            return false;  // If a non-space character is encountered, return false
        }
    }
    return true;  // If only space characters are encountered, return true
}

int main() {
    std::string input;
    std::cout << "Enter input: ";
    std::getline(std::cin, input);

    if (isSingleWord(input)) {
        std::cout << "There is only one word in the input." << std::endl;
    } else {
        std::cout << "There are multiple words in the input." << std::endl;
    }

    return 0;
}
