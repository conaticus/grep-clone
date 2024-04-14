#pragma once

class PatternMatcher
{
public:
    PatternMatcher(std::string input, std::string pattern) : input(input), pattern(pattern) {}
    bool Match();
private:
    std::string input;
    std::string pattern;
};
