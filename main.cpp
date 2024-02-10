#include ".\\Lexer\\Lexer.h"


int main(int argc, char *argv[])
{
    try
    {
        Lexer lexer("C:\\Compiler-Theory-and-Algorithms_C++\\inpu.txt");
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
    }
    catch(const SyntaxError& e)
    {
        std::cout << e.what() << "\n";
    }
    catch(const SemanticError& e)
    {
        std::cout << e.what() << "\n";
    }
    catch(const OtherError& e)
    {
        std::cout << e.what() << "\n";
    }

    return 0;
}