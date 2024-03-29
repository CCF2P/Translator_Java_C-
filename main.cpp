#include ".\\Lexer\\Lexer.h"


int main(int argc, char *argv[])
{
    try
    {
        Lexer lexer("C:\\Translator_Java_C-\\input.txt");
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