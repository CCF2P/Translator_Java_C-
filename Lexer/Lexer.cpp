#include ".\\Lexer.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <cctype>


Lexer::Lexer(std::string file_path)
{
    this->state = STATES::NONE;

    this->pos_text = -1;
    this->position = 0;
    this->lineno = 1;

    std::ifstream file;
    file.open(file_path, std::ios::in);
    if (!file.is_open())
        throw OtherError("Cannot open file", 0, 0);

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
                throw SyntaxError("Char type error", this->lineno, this->position);
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
                
                if (ch == ";" || help.OPERATORS.count(ch) == 0)
                    this->state = STATES::NONE;
            }

            this->pos_text -= 1;
            if (accum == "//")
            {
                accum = "";
                this->state = STATES::COMMENT;

                while (ch != "\n")
                        ch = this->get_char();
                ch = this->get_char();
            }
            else if (help.OPERATORS.count(accum) != 0)
                return Token(accum, help.OPERATORS[accum]);
            else
                throw SyntaxError("Operator error", this->lineno, this->position);
        }

        // Для ID, ACCESS_MODIFIERS, KEY_WORDS, DATA_TYPES
        if (std::isalpha(ch[0]))
        {
            this->state = STATES::ID;
            while (std::isalnum(ch[0]))
            {
                accum += ch;
                if (accum == "System.out.print")
                {
                    ch = this->get_char();

                    if (ch == "l")
                    {
                        accum += ch;
                        ch = this->get_char();
                        accum += ch;
                        return Token(accum, help.KEY_WORDS[accum]);
                    }
                    else
                    {
                        this->pos_text -= 1;
                        return Token(accum, help.KEY_WORDS[accum]);
                    }
                }

                if (help.ACCESS_MODIFIERS.count(accum) != 0)
                    return Token(accum, help.ACCESS_MODIFIERS[accum]);
                else if (help.KEY_WORDS.count(accum) != 0)
                    return Token(accum, help.KEY_WORDS[accum]);
                else if (help.DATA_TYPES.count(accum) != 0)
                    return Token(accum, help.DATA_TYPES[accum]);
                
                ch = this->get_char();
                if ((accum == "System" || accum == "System.out") && ch == ".")
                {
                    accum += ch;
                    ch = this->get_char();
                }
            }

            this->pos_text -= 1;
            if (accum == "false" || accum == "true")
                return Token(accum, help.DATA_TYPES["boolean"]);
            else
                return Token(accum, "ID");
        }

        // Для определения INT, DOUBLE
        if (std::isdigit(ch[0]))
        {
            this->state = STATES::INT;
            while (this->state != STATES::NONE)
            {
                accum += ch;
                ch = this->get_char();
                if (ch == ".")
                {
                    if (this->state == STATES::DOUBLE)
                        throw SyntaxError("Invalid double type", this->lineno, this->position);
                    
                    this->state = STATES::DOUBLE;
                    accum += ch;
                    ch = this->get_char();
                }

                if (ch == ";" || help.IGNORE.count(ch) != 0)
                    this->state = STATES::NONE;
                else if (help.SPECIAL_SYMBOLS.count(ch) != 0)
                    this->state = STATES::NONE;
                else if (help.OPERATORS.count(ch) != 0)
                    this->state = STATES::NONE;
                else if (!std::isdigit(ch[0]))
                {
                    if (this->state == STATES::DOUBLE)
                        throw SyntaxError("Invalid double type", this->lineno, this->position);
                    else
                        throw SyntaxError("Invalid integer type", this->lineno, this->position);
                }
            }

            if (accum[accum.size() - 1] == '.')
                throw SyntaxError("Real number type error", this->lineno, this->position);

            this->pos_text -= 1;
            if (accum.find('.') != std::string::npos)
                return Token(accum, help.DATA_TYPES["double"]);
            else
                return Token(accum, help.DATA_TYPES["int"]);
        }

        if (this->state == STATES::START)
        {
            this->state == STATES::END_OF_FILE;
            return Token("EOF", "EOF");
        }
    }

    return Token("If you get this token", "it's means that method get_next_token() has error");
}


Token Lexer::parse()
{
    if (this->programm_text.size() == 0)
        throw OtherError("input text is empty", this->lineno, this->position);

    if (this->state == STATES::END_OF_FILE)
        return Token("EOF", "EOF");

    return this->get_next_token();
}