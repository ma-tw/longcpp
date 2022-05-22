#include <iostream>
#include <string>

constexpr int cHeight = 6;
constexpr int plusHeight = 4;
constexpr int plusUpperSpace = 1;
const std::string cSymbol[] = {
    "  _____ ",
    " /  ___|",
    "|  |    ",
    "|  |    ",
    "|  |___ ",
    " \\_____|"
};
const std::string plusSymbol[] = {
    "   _   ",
    " _| |_ ",
    "|_   _|",
    "  |_|  "
};

void printAsciiArt(int plusNum) {
    for (int i = 0; i < cHeight; i++) {
        std::cout << cSymbol[i];
        if (plusUpperSpace <= i && i <= plusHeight) {
            for (int j = 0; j < plusNum; j++) {
                std::cout << plusSymbol[i - 1];
            }
        }
        std::cout << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Error: Expected the number of +" << std::endl;
        return EXIT_FAILURE;
    }
    int inputNum = std::atoi(argv[1]);
    printAsciiArt(inputNum);
    return EXIT_SUCCESS;
}