#include <iostream>
#include <string>

constexpr int C_HEIGHT = 6;
constexpr int PLUS_HEIGHT = 4;
constexpr int SPACE_ABOVE_PLUS = 1;
const std::string C_SYMBOL[] = {
    "  _____ ",
    " /  ___|",
    "|  |    ",
    "|  |    ",
    "|  |___ ",
    " \\_____|"
};
const std::string PLUS_SYMBOL[] = {
    "   _   ",
    " _| |_ ",
    "|_   _|",
    "  |_|  "
};

void printAsciiArt(int plusNum) {
    for (int i = 0; i < C_HEIGHT; i++) {
        std::cout << C_SYMBOL[i];
        if (SPACE_ABOVE_PLUS <= i && i <= PLUS_HEIGHT) {
            for (int j = 0; j < plusNum; j++) {
                std::cout << PLUS_SYMBOL[i - 1];
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