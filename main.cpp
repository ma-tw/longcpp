#include <iostream>
#include <string>
#include <unistd.h>
#include <getopt.h>
#include "cppascii.hpp"

void showUsage(char* exeString) {
    std::cout << "Usage: " << exeString << " [OPTION] LENGTH" << std::endl;
    std::cout << std::endl;
    std::cout << "  -v   Print the ascii art vertically" << std::endl;
}

/**
 * @brief Print an ascii art of C++ horizontally
 * 
 * @param plusNum The number of + in the ascii art
 */
void printHorizontalAsciiArt(int plusNum) {
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

/**
 * @brief Print an ascii art of C++ vertically
 * 
 * @param plusNum The number of + in the ascii art
 */
void printVerticalAsciiArt(int plusNum) {
    for (int i = 0; i < C_HEIGHT; i++) {
        std::cout << C_SYMBOL[i] << std::endl;
    }
    for (int i = 0; i < plusNum; i++) {
        for (int j = 0; j < PLUS_HEIGHT; j++) {
            std::cout << " " << PLUS_SYMBOL[j] << std::endl;
        }
    }
}

int main(int argc, char* argv[]) {
    bool vertical = false;
    int option;
    while ((option = getopt(argc, argv, "v")) != -1) {
        if (option == 'v') {
            vertical = true;
        }
        else {
            showUsage(argv[0]);
            return EXIT_FAILURE;
        }
    }
    if (optind == argc) {
        showUsage(argv[0]);
        return EXIT_FAILURE;
    }
    int inputNum = std::atoi(argv[argc - 1]);
    if (vertical) printVerticalAsciiArt(inputNum);
    else printHorizontalAsciiArt(inputNum);
    return EXIT_SUCCESS;
}