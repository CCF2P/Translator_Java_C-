#pragma once
#include <map>
#include <string>
#include <vector>


class Help
{
public:
    std::map<std::string, std::string> ACCESS_MODIFIERS
    {
        std::pair<std::string, std::string> {"public",    "PUBLIC"},
        std::pair<std::string, std::string> {"privae",    "PRIVATE"},
        std::pair<std::string, std::string> {"protected", "PROTECTED"}
    };

    std::map<std::string, std::string> KEY_WORDS
    {
        std::pair<std::string, std::string> {"class",              "CLASS"},
        std::pair<std::string, std::string> {"else",               "ELSE"},
        std::pair<std::string, std::string> {"for",                "FOR"},
        std::pair<std::string, std::string> {"if",                 "IF"},
        std::pair<std::string, std::string> {"new",                "NEW"},
        std::pair<std::string, std::string> {"package",            "PACKAGE"},
        std::pair<std::string, std::string> {"return",             "RETURN"},
        std::pair<std::string, std::string> {"static",             "STATIC"},
        std::pair<std::string, std::string> {"this",               "THIS"},
        std::pair<std::string, std::string> {"while",              "WHILE"},
        std::pair<std::string, std::string> {"System.out.print",   "SYSTEM.OUT.PRINT"},
        std::pair<std::string, std::string> {"System.out.println", "SYSTEM.OUT.PRINTLN"},
        std::pair<std::string, std::string> {"switch",             "SWITCH"},
        std::pair<std::string, std::string> {"case",               "CASE"},
        std::pair<std::string, std::string> {"default",            "DEAFAULT"}
    };

    std::map<std::string, std::string> DATA_TYPES
    {
        std::pair<std::string, std::string> {"byte",    "BYTE"},
        std::pair<std::string, std::string> {"short",   "SHORT"},
        std::pair<std::string, std::string> {"int",     "INT"},
        std::pair<std::string, std::string> {"long",    "LONG"},
        std::pair<std::string, std::string> {"float",   "FLOAT"},
        std::pair<std::string, std::string> {"double",  "DOUBLE"},
        std::pair<std::string, std::string> {"boolean", "BOOLEAN"},
        std::pair<std::string, std::string> {"char",    "CHAR"},
        std::pair<std::string, std::string> {"string",  "STRING"},
        std::pair<std::string, std::string> {"void",    "VOID"}
    };

    std::map<std::string, std::string> SPECIAL_SYMBOLS
    {
        std::pair<std::string, std::string> {"(",  "LEFT_BRACKET"},
        std::pair<std::string, std::string> {")",  "RIGHT_BRACKET"},
        std::pair<std::string, std::string> {"[",  "LEFT_SQUARE_BRACKET"},
        std::pair<std::string, std::string> {"]",  "RIGHT_SQUARE_BRACKET"},
        std::pair<std::string, std::string> {"{",  "LEFT_CURLY_BRACKET"},
        std::pair<std::string, std::string> {"}",  "RIGHT_CURLY_BRACKET"},
        std::pair<std::string, std::string> {".",  "DOT"},
        std::pair<std::string, std::string> {";",  "SEMICOLON"},
        std::pair<std::string, std::string> {",",  "COMMA"}
    };

    std::map<std::string, std::string> COMMENT_SYMBOLS
    {
        std::pair<std::string, std::string> {"//", "DOUBLE_SLASH"},
        std::pair<std::string, std::string> {"/*", "SLASH_STAR"}
    };

    std::map<std::string, std::string> OPERATORS
    {
        std::pair<std::string, std::string> {"=",  "ASSIGN"},
        std::pair<std::string, std::string> {"==", "IS_EQUAL"},
        std::pair<std::string, std::string> {"!=", "INEQUALITY"},
        std::pair<std::string, std::string> {"<",  "LESS"},
        std::pair<std::string, std::string> {">",  "MORE"},
        std::pair<std::string, std::string> {">=", "GREATE_THAN_OR_EQUAL"},
        std::pair<std::string, std::string> {"<=", "LESS_THAN_OR_EQUAL"},
        std::pair<std::string, std::string> {"+",  "PLUS"},
        std::pair<std::string, std::string> {"-",  "MINUS"},
        std::pair<std::string, std::string> {"*",  "MULTIPLY"},
        std::pair<std::string, std::string> {"/",  "DIVIDE"},
        std::pair<std::string, std::string> {"%",  "MOD"},
        std::pair<std::string, std::string> {"++", "INCREMENT"},
        std::pair<std::string, std::string> {"--", "DECREMENT"},
        std::pair<std::string, std::string> {"+=", "EDITION"},
        std::pair<std::string, std::string> {"-=", "SUBSTRACTION"},
        std::pair<std::string, std::string> {"*=", "MULTIPLACATION"},
        std::pair<std::string, std::string> {"/=", "DIVISION"},
        std::pair<std::string, std::string> {"%=", "MODULUS"},
        std::pair<std::string, std::string> {"&&", "AND"},
        std::pair<std::string, std::string> {"&",  "SHORT_AND"},
        std::pair<std::string, std::string> {"||", "OR"},
        std::pair<std::string, std::string> {"|",  "SHORT_OR"},
        std::pair<std::string, std::string> {"!",  "NOT"},
        std::pair<std::string, std::string> {":",  "DOUBLE_DOT"}
    };

    std::map<std::string, char> IGNORE
    {
        std::pair<std::string, char> {"\n", '\0'},
        std::pair<std::string, char> {" ",  '\0'},
        std::pair<std::string, char> {"\t", '\0'}
    };
};
