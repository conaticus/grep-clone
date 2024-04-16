#pragma once
#include <string>
#include <unordered_set>
#include "Pattern.h"

class PatternParser
{
public:
    PatternParser(const std::string& input, const std::string& pattern) : input(input), patternRaw(pattern) {}
    Pattern Parse();
private:
    const std::string input;
    const std::string patternRaw;
    Pattern pattern;

    size_t currentIdx = 0;

    char Next();
    char Current() const;
    char Peek() const;

    void ConsumeEscaped(char escapedChar);
    void ConsumeString();
};