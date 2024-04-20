#include "PatternParser.h"
#include "PatternMatcher.h"
#include <iostream>
#include <unordered_set>

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

            case '[':
            {
                bool isPositive = Peek() != '^';
                if (!isPositive)
                    Next();
                
                std::unordered_set<char> charGroup = ConsumeCharGroup();
                PushToken(isPositive ? PositiveGroup : NegativeGroup, charGroup);
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

char PatternParser::Next() {
    return pattern[++currentIdx];
}

char PatternParser::Peek() const {
    return pattern[currentIdx + 1];
}

char PatternParser::Current() const {
    return pattern[currentIdx];
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

void PatternParser::PushToken(TokenType type, const std::unordered_set<char>& groupSet) {
    PatternToken token(type);
    if (type == PositiveGroup)
        token.positiveCharGroup = groupSet;
    else
        token.negativeCharGroup = groupSet;
    
    patternTokens.push_back(token);
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

std::unordered_set<char> PatternParser::ConsumeCharGroup() {
    char current = Next();
    std::unordered_set<char> charGroupSet;

    // TODO: Handle when closing ']' bracket is not provided.
    while (current != ']' && !IsAtEnd()) {
        charGroupSet.insert(current);
        current = Next();
    }

    return charGroupSet;
}