#include <iostream>
#include <string>
#include "Pattern.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Expected two arguments: grep [operation] [pattern]" << std::endl;
        return 1;
    }

    std::string flag = argv[1];
    std::string patternRaw = argv[2];

    if (flag != "-E") {
        std::cerr << "Expected first argument to be '-E'" << std::endl;
        return 1;
    }

    std::string inputLine;
    std::getline(std::cin, inputLine);

    bool doesMatch = MatchPattern(inputLine, patternRaw);
    std::cout << (doesMatch ? "Match!" : "No match.") << std::endl;

    return !doesMatch;
}
