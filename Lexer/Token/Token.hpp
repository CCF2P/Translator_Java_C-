#pragma once
#include <string>
#include <iostream>


class Token
{
public:
    std::string name;
    std::string type;

    Token(std::string name="None", std::string type="None")
    {
        this->name = name;
        this->type = type;
    }

    void print_token()
    {
        std::cout << this->name << " : " << this->type << "\n";
    }
};