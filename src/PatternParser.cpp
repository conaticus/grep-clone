#include "PatternParser.h"
#include "Pattern.h"
#include <iostream>

Pattern PatternParser::Parse() {
    Pattern pattern;

    char ch = Current();
    while (currentIdx < patternRaw.length()) {
        switch (ch) {
            case '\\':
            {
                char escapedChar = patternRaw[++currentIdx];
                ConsumeEscaped(escapedChar, pattern);
                break;
            }

            default:
                pattern.positiveCharGroup.insert(ch);
                break;
        }

        ch = Next();
    }
    
    return pattern;
}

void PatternParser::ConsumeEscaped(char escapedChar, Pattern& pattern) const {
    switch (escapedChar) {
        case 'd':
            pattern.matchDigits = true;
            break;
        case 'w':
            pattern.matchAlphaNumeric = true;
            break;
        default: 
            // If not a valid escape character, just append the slash and character into the positive char group.
            pattern.positiveCharGroup.insert('\\');
            pattern.positiveCharGroup.insert(escapedChar);
            break;
    }
}

char PatternParser::Current() {
    return patternRaw[currentIdx];
}

char PatternParser::Next() {
    return patternRaw[++currentIdx];
}