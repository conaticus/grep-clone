#include <string>
#include <iostream>
#include "PatternMatcher.h"

bool PatternMatcher::Match() {
    if (input.length() == 0) return false;

    bool result = input.find(pattern) != std::string::npos;
    std::cout << (result ? "Match!" : "No match.") << std::endl;
    return result;
}