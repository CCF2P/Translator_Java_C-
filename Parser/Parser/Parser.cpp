#include ".\\Parser.hpp"


// =============================== Public ===============================
Parser::Parser(Lexer lexer)
{
    this->lexer = &lexer;
    this->token = this->lexer->get_next_token();
    this->sbm_tables.insert(sbm_tables.begin(), SymbolTable());
}


void Parser::next_token()
{
    this->token = this->lexer->get_next_token();
}


Node Parser::parse()
{
    if (this->lexer->state == Lexer::STATES::END_OF_FILE)
        throw OtherError("file is empty");
    else
    {
        std::vector<Node> statements;
        std::string header;
        /*
            Сначала разбираем строку вида: public class <ID> {,
            потому что наш парсер поддерживает только один класс.
            В итоге наш разбор заканчивается на токене следующим за {.
        */
        if (help.ACCESS_MODIFIERS.count(this->token.name) == 0)
            throw SemanticError("Missing access modifiers: public",
                                this->lexer->lineno,
                                this->lexer->position);
        this->next_token();

        if (help.KEY_WORDS.count(this->token.name) == 0)
            throw SemanticError("Missing keyword: class",
                                this->lexer->lineno,
                                this->lexer->position);
        header += "class ";
        this->next_token();

        if (this->token.type != "ID")
            throw SemanticError("Missing ID",
                                this->lexer->lineno,
                                this->lexer->position);
        header += this->token.name + " ";
        this->next_token();

        if (help.SPECIAL_SYMBOLS.count(this->token.name) == 0)
            throw SyntaxError("Expected '{'",
                              this->lexer->lineno,
                              this->lexer->position);
        this->next_token();

        while (this->lexer->state != Lexer::STATES::END_OF_FILE)
        {
            statements.insert(statements.end(), this->statement());
            if (this->token.name == "}")
                this->next_token();
        }

        return NodeProgram(statements);
    }
}
    

std::string Parser::find_expected_word(std::string word) {}


// =============================== Private ===============================
bool Parser::variable_is_declared(std::string id)
{

}


Node Parser::operand(std::string type)
{
    Token first_token = this->token;

    // Определение типа операнда
    if (this->token.type == "INT")
    {
        // Проверка на совпадение типов
        if (0) {}
        this->next_token();
        return NodeIntLiteral(first_token.name, first_token.type);
    }
    else if (this->token.type == "DOUBLE")
    {

    }
    else if (this->token.type == "STRING")
    {

    }
    // Если в качестве операнда IDБ то это может быть:
    // переменная, функция или массив
    else if (this->token.type == "ID")
    {
        // Проверяем объявлена ли переменная
        // ...

        this->next_token();
        // Если встретили (, то операнд - функция
        if (this->token.name == "(")
        {

        }
        // Если встретили [, то операнд - массив
        else if (this->token.name == "[")
        {

        }
        // Если не встретили ( и [, то операнд - переменная
        else
        {
            if (first_token.name == "ID")
                return NodeAtomType(first_token.name);
            else
                return NodeVariable(first_token.name, first_token.type);
        }
    }
    // Если операндом является (, то значит мы встретили скобку в выражении
    // и должны продолжить разбор выражения, но уже в скобках
    else if (this->token.name == "(")
    {
        this->next_token();
        Node expression = this->expression(type);
        this->next_token();
        return expression;
    }
}


Node Parser::factor(std::string type) {}


Node Parser::term(std::string type) {}


Node Parser::expression(std::string type) {}


Node Parser::declaration(std::string type) {}


Node Parser::increment() {}


Node Parser::block() {}


Node Parser::formal_params() {}


Node Parser::local_statement() {}


Node Parser::statement() {}