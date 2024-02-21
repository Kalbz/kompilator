#ifndef SCOPE_H
#define SCOPE_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Record.hpp"

class Scope
{
private:
    Scope *parentScope = nullptr;
    std::vector<Scope *> childScopes;
    std::map<std::string, Record*> records;
    int next = 0;

public:
    // Constructor for root scope
    Scope() {}

    // Constructor for child scope
    explicit Scope(Scope *parent) : parentScope(parent) {}

    // // Prevent copying
    // Scope(const Scope &) = delete;
    // Scope &operator=(const Scope &) = delete;

    // Destructor to clean up dynamically allocated child scopes
    ~Scope() {
        for (auto child : childScopes) {
            delete child;
        }
        for (auto& pair : records) {
            delete pair.second; // Delete dynamically allocated Record objects
        }
    }


    // Function to create or return the next child scope
    Scope *nextChild()
    {
        Scope *nextChild;
        if (next >= childScopes.size())
        {
            nextChild = new Scope(this);
            childScopes.push_back(nextChild);
        }
        else
        {
            nextChild = childScopes[next];
        }
        next++;
        return nextChild;
    }

    Record lookup(std::string key){
        auto it = records.find(key);
        if (it != records.end())
        {
            return *it->second;
        }
        else
        {
            if (parentScope != nullptr)
            {
                return parentScope->lookup(key);
            }
            else
            {
                throw std::runtime_error("Record not found");
            }
        }
    }

    Scope* getParentScope(){
        return parentScope;
    }

    void resetScope(){
        next = 0;
        for (int i = 0; i < childScopes.size(); i++)
        {
            childScopes[i]->resetScope();
        }
    }

    
    void put(std::string key, Record value) {
        records[key] = new Record(value);
    }

    void printScope(){
        for (auto& pair : records)
        {
            std::cout << "ID: " << pair.second->getId() << " Type: " << pair.second->getType() << std::endl;
        }
        for (int i = 0; i < childScopes.size(); i++)
        {
            childScopes[i]->printScope();
        }
    }

};

#endif
