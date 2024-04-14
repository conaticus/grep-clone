#include <string>
#include <iostream>
#include "PatternMatcher.h"

bool PatternMatcher::Match() {
    if (input.length() == 0) return false;

    bool doesMatch = input.find(pattern) != std::string::npos;
    std::cout << (doesMatch ? "Match!" : "No match.") << std::endl;

    return doesMatch;
}