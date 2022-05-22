#include <iostream>
#include <string>

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

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Expected the number of +" << std::endl;
        return EXIT_FAILURE;
    }
    int plusNumber = std::atoi(argv[1]);
    for (int i = 0; i < 6; i++) {
        std::cout << cSymbol[i];
        if (1 <= i && i <= 4) {
            for (int j = 0; j < plusNumber; j++) {
                std::cout << plusSymbol[i - 1];
            }
        }
        std::cout << std::endl;
    }
    return EXIT_SUCCESS;
}