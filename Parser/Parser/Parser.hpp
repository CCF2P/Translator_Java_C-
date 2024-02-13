#pragma once
#include "..\\ParserTree\\Node.hpp"
#include "..\\..\\Lexer\\Lexer.hpp"
#include "..\\..\\Lexer\\Token\\Token.hpp"
#include "..\\..\\Utils\\Error.hpp"

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
    Help help;                            // Вспомогательная переменная для обращения к словарям

    Lexer *lexer;                         // Указатель на используемый лексер
    Token token;                          // Текущий токен
    std::vector<SymbolTable> sbm_tables;  // Стек таблиц символов

    Parser(Lexer);

    void next_token();
    Node parse();
    std::string find_expected_word(std::string word);
};