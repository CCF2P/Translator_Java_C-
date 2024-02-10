#pragma once
#include "..\\ParserTree\\Node.h"
#include "..\\..\\Lexer\\Lexer.h"
#include "..\\..\\Lexer\\Token\\Token.h"

class Parser
{
public:
    Lexer *lexer;
    Token token;
    std::vector<SymbolTable> sbm_tables;

    Parser(Lexer lexer)
    {
        this->lexer = &lexer;
        this->token = this->lexer->get_next_token();
        this->sbm_tables.insert(sbm_tables.begin(), SymbolTable());
    }

    void next_token()
    {
        this->token = this->lexer->get_next_token();
    }
};