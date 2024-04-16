#include <iostream>
#include <string>
#include "Pattern.h"
#include "PatternParser.h"

bool MatchPattern(const std::string& input, const std::string& patternRaw) {
    if (input.length() == 0) return false;

    PatternParser parser(input, patternRaw);
    Pattern pattern = parser.Parse();
    for (char ch : input) {
        if (
            (pattern.matchDigits && isdigit(ch)) ||
            (pattern.matchAlphaNumeric && isalnum(ch)) ||
            (pattern.positiveCharGroup.find(ch) != pattern.positiveCharGroup.end())
        )
            return true;
    }

    return false;
}