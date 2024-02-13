#pragma once
#include <map>
#include <string>


class SymbolTable
{
public:
    std::map<std::string, std::string> table;

    bool is_exist(std::string id)
    {
        if (table.count(id) != 0)
            return true;
        else
            return false;
    }
};