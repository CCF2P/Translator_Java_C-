#pragma once
#include <string>


// Абстрактный класс
// От которого наследуются другие виды ошибок
class BaseError
{
public:
    std::string text;
    int line;
    int position;

    BaseError(std::string text="", int line=0, int position=0)
    {
        this->text = text;
        this->line = line;
        this->position = position;
    }

    virtual std::string what() const = 0;
};


class SyntaxError : BaseError 
{
public:
    SyntaxError(std::string text,
                int line,
                int position) : BaseError(text, line, position) {};
    
    std::string what() const override
    {
        return "Syntax error: " + this->text +
               "in line " + std::to_string(this->line) +
               " position " + std::to_string(this->position);
    }
};


class SemanticError : BaseError 
{
public:
    SemanticError(std::string text,
                  int line,
                  int position) : BaseError(text, line, position) {};
    
    std::string what() const override
    {
        return "Semantic error: " + this->text +
               " in line " + std::to_string(this->line) +
               " position " + std::to_string(this->position);
    }
};


class OtherError : BaseError
{
public:
    OtherError(std::string text,
               int line,
               int position) : BaseError(text, line, position) {};

    std::string what() const override
    {
        return "Some error: " + this->text +
               " in line " + std::to_string(this->line) +
               " position " + std::to_string(this->position);
    }
};