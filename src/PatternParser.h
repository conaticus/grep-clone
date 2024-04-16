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

    size_t currentIdx = 0;

    char Next();
    char Current();

    void ConsumeEscaped(char escapedChar, Pattern& pattern) const;
};