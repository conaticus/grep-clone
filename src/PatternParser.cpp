#include "PatternParser.h"
#include "Pattern.h"
#include <iostream>

Pattern PatternParser::Parse() {
    char ch = Current();
    while (!IsAtEnd()) {
        switch (ch) {
            case '\\':
            {
                char escapedChar = Peek();
                if (escapedChar == '\0') break; // Already at last character in the input string

                ConsumeEscaped(escapedChar);
                break;
            }

            default:
                ConsumeString();
                break;
        }

        ch = Next();
    }
    
    return pattern;
}

char PatternParser::Current() const {
    return patternRaw[currentIdx];
}

char PatternParser::Next() {
    return patternRaw[++currentIdx];
}

char PatternParser::Peek() const {
    if (IsAtEnd())
        return '\0';

    return patternRaw[currentIdx + 1];
}

bool PatternParser::IsAtEnd() const {
    return currentIdx >= patternRaw.length();
}

void PatternParser::ConsumeEscaped(char escapedChar) {
    switch (escapedChar) {
        case 'd':
            pattern.matchDigits = true;
            break;
        case 'w':
            pattern.matchAlphaNumeric = true;
            break;
        default:
            // If not a valid escape character, just append the slash and character into the string match.
            ConsumeString();
            return;
    }

    // Only move forward if it was a valid escape character, otherwise this will be done anyway inside ConsumeString function
    Next();
}

void PatternParser::ConsumeString() {
    int startIdx = currentIdx;
    int stringLength = 0;

    char ch = Current();
    while (isalnum(ch) && IsAtEnd()) {
        stringLength++;
        Next();
    }

    pattern.matchString = patternRaw.substr(startIdx, stringLength); 
}