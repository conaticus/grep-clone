#pragma once
#include "PatternParser.h"

class PatternMatcher
{
public:
    PatternMatcher(const std::string& input, const std::string& pattern) : input(input), pattern(pattern) {}
    bool Match();
private:
    const std::string input;
    const std::string pattern;

    bool MatchToken(char ch, const PatternToken& token) const;
};