#include ".\\Lexer\\Lexer.h"


int main(int argc, char *argv[])
{
    Lexer lexer("C:\\Compiler-Theory-and-Algorithms_C++\\input.txt");
    Token t;
    t = lexer.parse();
    t.print_token();
    t = lexer.parse();
    t.print_token();
    t = lexer.parse();
    t.print_token();
    t = lexer.parse();
    t.print_token();
    t = lexer.parse();
    t.print_token();

    return 0;
}