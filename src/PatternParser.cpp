#include "PatternParser.h"
#include "PatternMatcher.h"
#include <iostream>

std::vector<PatternToken> PatternParser::Parse() {
    char ch = Current();
    while (!IsAtEnd()) {
        switch (ch) {
            case '\\':
            {
                char escapedChar = Next();
                if (escapedChar == '\0') break; // Already at last character in the input string

                ConsumeEscaped(escapedChar);
                break;
            }

            default:
                PushToken(ch);
                break;
        }

        ch = Next();
    }
    
    return patternTokens;
}

char PatternParser::Current() const {
    return pattern[currentIdx];
}

char PatternParser::Next() {
    return pattern[++currentIdx];
}

bool PatternParser::IsAtEnd() const {
    return currentIdx >= pattern.length();
}

void PatternParser::PushToken(TokenType type) {
    patternTokens.push_back(PatternToken(type));
}

void PatternParser::PushToken(char character) {
    patternTokens.push_back(PatternToken(character));
}

void PatternParser::ConsumeEscaped(char escapedChar) {
    switch (escapedChar) {
        case 'd':
            PushToken(Digit);
            break;
        case 'w':
            PushToken(Alphanumeric);
            break;
        default:
            // If not a valid escape character, just append the slash and character into the pattern tokens
            PushToken('\\');
            PushToken(escapedChar);
    }
}