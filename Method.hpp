#ifndef METHOD_H
#define METHOD_H

#include <iostream>
#include <string>
#include <map>
#include "Variable.hpp"

class Method : public Record
{
private:
    std::map<std::string, Variable> parameters;
    std::map<std::string, Variable> variables;

public:

    Method(std::string id, std::string type)
    {
        this->setId(id);
        this->setType(type);
    }

    void addVariable(std::string name, std::string type)
    {
        Variable v(name, type);
        this->variables.insert(std::pair<std::string, Variable>(name, v));
    }

    void addParameter(std::string name, std::string type)
    {
        Variable v(name, type);
        this->parameters.insert(std::pair<std::string, Variable>(name, v));
    }

    std::map<std::string, Variable> getParameter()
    {
        return this->parameters;
    }


    void printMethod()
    {
        std::cout << "Method: " << this->getId() << " Type: " << this->getType() << std::endl;
        std::cout << "Parameters: " << std::endl;
        for (auto &x : this->parameters)
        {
            std::cout << "ID: " << x.second.getId() << " Type: " << x.second.getType() << std::endl;
        }
        std::cout << "Variables: " << std::endl;
        for (auto &x : this->variables)
        {
            std::cout << "ID: " << x.second.getId() << " Type: " << x.second.getType() << std::endl;
        }
    }
};

#endif