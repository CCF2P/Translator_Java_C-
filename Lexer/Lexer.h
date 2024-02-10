#pragma once
#include "..\\Utils\\Help.h"
#include ".\\Token\\Token.h"
#include "..\\Utils\\Error.h"


class Lexer
{
private:
    enum class STATES
    {
        NONE,
        START,
        COMMENT,
        END_OF_FILE,
        STRING,
        CHAR,
        OPERATOR,
        ID,
        INT,
        DOUBLE,
        BOOLEAN
    };

    int pos_text;  // Позиция в строке programm_text
    int position;  // Позиция в строке файла
    int lineno;    // Номер строки в файле
    
    STATES state;  // Текущее состояние лексера

    /*
    * Возвращает символ из текста программы и, если наш указатель
    * превысил длину строки то значит мы дошли до конца файла
    * и ставим наш статус равный "EOF" (end of file)
    */
    std::string get_char();

public:
    std::vector<std::string> programm_text;  // Строки программы, считанные из файла
    std::vector<Token> flow_lexem;           // Список токенов

    Lexer(std::string file_path);
    ~Lexer();

    /*
    * Возвращает следующий разобранный токен из текста программы
    */
    Token get_next_token();
    
    /*
    * Начало начало - метод parse.
    * Он открывает файл с исходным кодом на Java
    * считывает оттуда все строки и начинает разбор токенов
    */
    Token parse();
};