#pragma once
#include "..\\ParserTree\\Node.h"
#include "..\\..\\Lexer\\Lexer.h"
#include "..\\..\\Lexer\\Token\\Token.h"
#include "..\\..\\Utils\\Error.h"

class Parser
{
private:
    bool variable_is_declared(std::string id);

    Node operand(std::string type);
    Node factor(std::string type);
    Node term(std::string type);
    Node expression(std::string type);
    Node declaration(std::string type);
    Node increment();
    Node block();
    Node formal_params();
    Node local_statement();
    Node statement();

public:
    Lexer *lexer;
    Token token;
    std::vector<SymbolTable> sbm_tables;

    Parser(Lexer);

    void next_token();
    Node parse();
    std::string find_expected_word(std::string word);
};