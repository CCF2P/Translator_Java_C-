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


class NodeDeclaration : public Node
{
public:
    std::string type;
    std::string id;

    NodeDeclaration(std::string type, std::string id)
    {
        this->type = type;
        this->id = id;
    }

    std::string get_generated_text()
    {
        return this->type + " " + this->id;
    }
};


class NodeAssigning : public Node
{
public:
    Node *left_side;
    Node *right_side;

    NodeAssigning(Node left_side, Node right_side)
    {
        this->left_side = &left_side;
        this->right_side = &right_side;
    }

    std::string get_generated_text()
    {
        return this->left_side->get_generated_text() + " = " + this->right_side->get_generated_text() + ";";
    }
};


class NodeMethod : public Node
{
public:
    std::string access_mod;
    std::string ret_type;
    std::string id;
    Node *formal_params;
    Node *block;

    NodeMethod(std::string access_mod,
               std::string ret_type,
               std::string id,
               Node formal_params,
               Node block)
    {
        this->access_mod = access_mod;
        this->ret_type = ret_type;
        this->id = id;
        this->formal_params = &formal_params;
        this->block = &block;
    }

    std::string get_generated_text()
    {
        return this->access_mod + " " +
               this->ret_type + " " +
               this->id + "(" + this->formal_params->get_generated_text() + ")" +
               "\n{\n" + this->block->get_generated_text() + "}";
    }
};


class NodeParams : public Node
{
public:
    std::vector<Node> params;

    NodeParams(std::vector<Node> params)
    {
        this->params = params;
    }

    virtual std::string get_generated_text()
    {
        std::string s;
        int l = this->params.size();
        for (int i = 0; i < l - 1; ++i)
            s += this->params[i].get_generated_text() + ", ";
        s += this->params[l].get_generated_text();
        return s;
    }
};
class NodeFormalParams : public NodeParams {};
class NodeActualParams : public NodeParams {};


class NodeElseBlock : public NodeBlock
{

};


class NodeIfConstruction : public Node
{
public:
    Node *condition;
    NodeBlock *block;
    NodeElseBlock *else_block;

    NodeIfConstruction(Node condition,
                       NodeBlock block,
                       NodeElseBlock else_block)
    {
        this->condition = &condition;
        this->block = &block;
        this->else_block = &else_block;
    }


};


class NodeLiteral : public Node
{
public:
    std::string type;
    std::string value;

    NodeLiteral(std::string value, std::string type="")
    {
        this->type = type;
        this->value = value;
    }

    std::string get_generated_text()
    {
        if (this->type == "")
            return "";
        return this->value;
    }
};


class NodeStringLiteral : public NodeLiteral 
{
public:
    std::string get_generated_text()
    {
        return "\"" + this->value + "\"";
    }
};


class NodeIntLiteral : public NodeLiteral
{
public:
    NodeIntLiteral(std::string value, std::string type) : NodeLiteral(value, type) {}
};


class NodeFloatLiteral : public NodeLiteral {};
class NodeBooleanLiteral : public NodeLiteral {};


class NodeVariable : public Node
{
public:
    std::string id;
    std::string type;

    NodeVariable(std::string id, std::string type)
    {
        this->id = id;
        this->type = type;
    }

    std::string get_generated_text()
    {
        return this->id + " " + this->type;
    }
};


class NodeAtomType : public Node
{
public:
    std::string id;

    NodeAtomType(std::string id)
    {
        this->id = id;
    }

    std::string get_generated_text()
    {
        return this->id;
    }
};