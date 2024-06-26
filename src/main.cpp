#include <iostream>
#include <string>
#include "PatternMatcher.h"

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

    PatternMatcher matcher(inputLine, patternRaw);

    bool doesMatch = matcher.Match();
    std::cout << (doesMatch ? "Match!" : "No match.") << std::endl;

    return !doesMatch;
}
