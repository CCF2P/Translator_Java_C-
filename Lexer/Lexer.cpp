#include ".\\Lexer.h"

#include <vector>
#include <iostream>
#include <fstream>


Lexer::Lexer(std::string file_path)
{
    this->state = STATES::NONE;

    this->pos_text = -1;
    this->position = 0;
    this->lineno = 1;

    std::ifstream file;
    file.open(file_path, std::ios::in);
    if (!file.is_open())
        throw "Cannot open file";

    std::string str;
    std::getline(file, str);
    str += "\n";
    this->programm_text.insert(this->programm_text.begin(), str);
    while (!file.eof())
    {
        std::getline(file, str);
        str += "\n";
        this->programm_text[this->programm_text.size() - 1] += str;
    }
}


Lexer::~Lexer() {}


std::string Lexer::get_char()
{
    this->position += 1;
    this->pos_text += 1;
    if (this->pos_text < this->programm_text[0].size())
    {
        std::string c(1, this->programm_text[0][this->pos_text]);
        if (c == "\n")
        {
            this->position = 1;
            this->lineno += 1;
        }
        return c;
    }
    else
    {
        this->state = STATES::START;
        return "";    
    }
}


Token Lexer::get_next_token()
{
    Help help;

    std::string accum;            // Накапливает символы из текста программы
    this->state = STATES::START;  // Начальное состояние лексера

    std::string ch = this->get_char();
    while (this->state != STATES::NONE and this->state != STATES::END_OF_FILE)
    {
        while (help.IGNORE.count(ch) != 0)
            ch = this->get_char();

        // Для определения string
        if (ch == "\"")
        {
            this->state = STATES::STRING;
            ch = this->get_char();
            
            while (this->state == STATES::STRING)
            {
                accum += ch;
                ch = this->get_char();
                if (ch == "\"")
                    this->state = STATES::NONE;
            }

            return Token(accum, help.DATA_TYPES["string"]);
        }

        // Для определения char
        if (ch == "'")
        {
            this->state = STATES::CHAR;
            ch = this->get_char();
            accum += ch;
            ch = this->get_char();
            if (ch != "'")
                throw "Char type error";
            else
                return Token(accum, help.DATA_TYPES["char"]);
        }

        // Для определения спец символов
        if (help.SPECIAL_SYMBOLS.count(ch) != 0)
        {
            accum += ch;
            return Token(accum, help.SPECIAL_SYMBOLS[ch]);
        }

        // Для определения операторов
        if (help.OPERATORS.count(ch) != 0)
        {
            this->state = STATES::OPERATOR;
            while (this->state != STATES::NONE)
            {
                accum += ch;
                ch = this->get_char();

                if (accum == "//")
                    while (ch != "\n")
                        ch = this->get_char();
                
                if (ch == ";" || help.OPERATORS.count(ch) == 0)
                    this->state = STATES::NONE;
            }

            this->pos_text -= 1;
            if (accum == "//")
            {
                accum = "";
                this->state = STATES::COMMENT;
            }
            else if (help.OPERATORS.count(accum) != 0)
                return Token(accum, help.OPERATORS[accum]);
            else
                throw "Operator error";
        }

        // Для ID, ACCESS_MODIFIERS, KEY_WORDS, DATA_TYPES
        if (0)
        {

        }
    }

    return Token("If you get this token", "it's means that method get_next_token has error");
}


Token Lexer::parse()
{
    if (this->programm_text.size() == 0)
        throw "input text is empty";

    if (this->state == STATES::END_OF_FILE)
        return Token("EOF", "EOF");

    return this->get_next_token();
}