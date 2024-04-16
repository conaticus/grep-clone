#pragma once
#include <unordered_set>

struct Pattern {
    bool matchDigits = false;
    bool matchAlphaNumeric = false;
    std::string matchString;
    std::unordered_set<char> positiveCharGroup;
};

bool MatchPattern(const std::string& input, const std::string& patternRaw);