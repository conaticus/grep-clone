#pragma once

class PatternMatcher
{
public:
    PatternMatcher(const std::string& input, const std::string& pattern) : input(input), pattern(pattern) {}
    bool Match();
    void ParseExpression(const std::string& expression);
private:
    const std::string input;
    const std::string pattern;

    bool matchDigits = false;
    char matchChar = '\0';
};
