#include <iostream>
#include <string>
#include "PatternMatcher.h"
#include "PatternParser.h"

bool PatternMatcher::Match() {
    if (input.length() == 0) return false;

    PatternParser parser(input, pattern);
    std::vector<PatternToken> patternTokens = parser.Parse();

    size_t currentTokenIndex = 0;

    for (char ch : input) {
        PatternToken currentToken = patternTokens[currentTokenIndex];
        if (MatchToken(ch, currentToken)) {
            // All pattern tokens match a section in the string so we return true
            if (++currentTokenIndex == patternTokens.size()) return true;
            continue;
        }

        currentTokenIndex = 0;
    }

    return false;
}

bool PatternMatcher::MatchToken(char ch, const PatternToken& token) const {
    switch (token.type) {
        case Digit:
            return isdigit(ch);
            break;
        case Alphanumeric:
            return isalpha(ch);
            break;
        case Character:
            return ch == token.character;
            break;
        case PositiveGroup:
            return token.positiveCharGroup.find(ch) != token.positiveCharGroup.end();
            break;
        case NegativeGroup:
            return token.negativeCharGroup.find(ch) == token.positiveCharGroup.end();
            break;
        default: break;
    }

    return false;
}