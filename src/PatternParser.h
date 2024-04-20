#pragma once
#include <string>
#include <vector>
#include <unordered_set>

enum TokenType
{
    Digit,
    Alphanumeric,
    Character,
    PositiveGroup,
    NegativeGroup,
};

struct PatternToken
{
    const TokenType type;
    const char character = '\0';
    std::unordered_set<char> positiveCharGroup;
    std::unordered_set<char> negativeCharGroup;

    PatternToken(const TokenType type) : type(type) {}
    PatternToken(char character) : type(Character), character(character) {}
};

class PatternParser
{
public:
    PatternParser(const std::string& input, const std::string& pattern) : input(input), pattern(pattern) {}
    std::vector<PatternToken> Parse();
private:
    const std::string input;
    const std::string pattern;
    std::vector<PatternToken> patternTokens;

    size_t currentIdx = 0;

    char Next();
    char Peek() const;
    char Current() const;
    bool IsAtEnd() const;

    void PushToken(TokenType type);
    void PushToken(char character);
    void PushToken(TokenType type, const std::unordered_set<char>& groupSet);
    
    void ConsumeEscaped(char escapedChar);
    std::unordered_set<char> ConsumeCharGroup();
};