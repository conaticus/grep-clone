#pragma once
#include <string>
#include <vector>

enum TokenType
{
    Digit,
    Alphanumeric,
    Character,
};

struct PatternToken
{
    const TokenType type;
    const char character = '\0';

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
    char Current() const;
    char Peek() const;
    bool IsAtEnd() const;

    void PushToken(TokenType type);
    void PushToken(char character);
    
    void ConsumeEscaped(char escapedChar);
};