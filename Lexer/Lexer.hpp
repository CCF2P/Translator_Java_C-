#pragma once
#include "..\\Utils\\Help.hpp"
#include ".\\Token\\Token.hpp"
#include "..\\Utils\\Error.hpp"


class Lexer
{
public:
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
    Help help;     // Вспомогательная переменная для обращения к словарям

    std::vector<std::string> programm_text;  // Строки программы, считанные из файла
    std::vector<Token> flow_lexem;           // Список токенов

    Lexer(std::string file_path);
    ~Lexer();

    /*
    * Возвращает символ из текста программы и, если наш указатель
    * превысил длину строки то значит мы дошли до конца файла
    * и ставим наш статус равный "EOF" (end of file)
    */
    std::string get_char();
    
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