#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <string>
#include <map>
#include "Record.hpp"
#include "Variable.hpp"
#include "Method.hpp"

class Class : public Record
{
    private:
    std::map<std::string, Variable> variables;
    std::map<std::string, Method> methods;

    public:
    Class(std::string name)
    {
        this->setId(name);
        this->setType("Class");
    }

    Class(std::string name, std::string type)
    {
        this->setId(name);
        this->setType(type);
    }

    void addVariable(std::string name, std::string type)
    {
        Variable v(name, type);
        this->variables.insert(std::pair<std::string, Variable>(name, v));
    }

    void addMethod(std::string name, std::string type)
    {
        Method m(name, type);
        this->methods.insert(std::pair<std::string, Method>(name, m));
    }

    Variable* lookupVariable(std::string name)
    {
        auto it = this->variables.find(name);
        if (it != this->variables.end())
        {
            return &(it->second);
        }
        else
        {
            return nullptr;
        }
    }

    Method* lookupMethod(std::string name)
    {
        auto it = this->methods.find(name);
        if (it != this->methods.end())
        {
            return &(it->second);
        }
        else
        {
            return nullptr;
        }
    }

    void printClass()
    {
        std::cout << "Class: " << this->getId() << " Type: " << this->getType() << std::endl;
        std::cout << "Variables: " << std::endl;
        for (auto &x : this->variables)
        {
            std::cout << "ID: " << x.second.getId() << " Type: " << x.second.getType() << std::endl;
        }
        std::cout << "Methods: " << std::endl;
        for (auto &x : this->methods)
        {
            std::cout << "ID: " << x.second.getId() << " Type: " << x.second.getType() << std::endl;
        }
    }

};

#endif