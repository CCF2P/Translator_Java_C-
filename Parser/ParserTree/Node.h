#pragma once
#include "..\\..\\Lexer\\Lexer.h"
#include "..\\..\\Lexer\\Token\\Token.h"
#include "..\\..\\Utils\\Help.h"
#include "..\\SymbolTable\\SymbolTable.h"


class Node
{
public:
    std::vector<Node> children;

    Node() {}
    Node(std::vector<Node> children)
    {
        this->children = children;
    }

    virtual std::string get_generated_text();
};


class NodeProgram : public Node
{
public:
    std::string header_programm;

    NodeProgram(std::vector<Node> children) : Node(children) {};

    void set_header(std::string hdr)
    {
        this->header_programm = hdr;
    }

    std::string get_generated_text()
    {
        std::string s = "";
        for (auto &item : this->children)
            s += item.get_generated_text() + "\n";
        return s;
    }
};


class NodeBlock : public Node
{
public:
    NodeBlock(std::vector<Node> children) : Node(children) {};
};


class NodeSystemOutPrint : public Node
{
public:
    std::string header;
    Node expression;

    NodeSystemOutPrint(std::string header, Node expression)
    {
        this->header = header;
        this->expression = expression;
    }

    std::string get_generated_text()
    {
        return this->header + "(" + this->expression.get_generated_text() + ");\n";
    }
};