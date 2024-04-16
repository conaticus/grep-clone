#include <string>
#include <iostream>
#include "PatternMatcher.h"

bool PatternMatcher::Match() {
    if (input.length() == 0) return false;

    ParseExpression(pattern);
    
    for (size_t i = 0; i < input.length(); i++) {
        char ch = input[i];

        if (
            (matchDigits && isdigit(ch)) ||
            (matchAlphaNumeric && isalnum(ch)) ||
            ch == matchChar
        )
            return true;
    }

    return false;
}

void PatternMatcher::ParseExpression(const std::string& expression) {
    if (expression[0] == '\\' && expression.length() == 2) {
        switch (expression[1]) {
            case 'd':
                matchDigits = true;
                return;
            case 'w':
                matchAlphaNumeric = true;
                return;
            default: break;
        }
    }

    if (expression.length() == 1)
        matchChar = expression[0];
}