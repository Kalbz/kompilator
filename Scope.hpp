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
    std::string name;
    std::string type;
    Scope *parentScope = nullptr;
    std::vector<Scope *> childScopes;
    std::map<std::string, Record*> records;
    int next = 0;

public:
    // Constructor for root scope
    Scope() {
        name = "root";
        std::cout << "Creating root scope." << std::endl;
    }



    // Constructor for child scope
    explicit Scope(Scope *parent, std::string name, std::string type) : parentScope(parent), name(name), type(type) {
        std::cout << "Creating child scope. Parent: " << parent << std::endl;
    }
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


    // // Function to create or return the next child scope
    // Scope *nextChild(std::string name, std::string type)
    // {
    //     Scope *nextChild;
    //     if (next >= childScopes.size())
    //     {
    //         nextChild = new Scope(this, name, type);
    //         childScopes.push_back(nextChild);
    //     }
    //     else
    //     {
    //         nextChild = childScopes[next];
    //     }
    //     next++;
    //     return nextChild;
    // }
    Scope* createChildScope(std::string name, std::string type) {
        Scope* newScope = new Scope(this, name, type);
        childScopes.push_back(newScope);
        return newScope;
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

    std::string getName() const {
        return name;
    }

    std::string getType() const {
        return type;
    }
    
    void put(std::string key, Record value) {
        std::cout << "Adding symbol to scope: " << key << std::endl;
        records[key] = new Record(value);
    }


    void printScope(){
        std::cout << "Printing scope. Records count: " << records.size() << std::endl;
        for (auto& pair : records)
        {
            std::cout << "ID: " << pair.second->getId() << " Type: " << pair.second->getType() << std::endl;
        }
        for (int i = 0; i < childScopes.size(); i++)
        {
            childScopes[i]->printScope();
        }
    }



void generateDotContent(std::ostream &out, int &nodeCount) const {
    int currentNode = nodeCount++;
    // Print the current node with its label
    out << "n" << currentNode << " [label=\"Scope: " << this->getName() << "(of type: " << this->getType() << ") Records count: " << records.size() << "\"];\n";
    
    // Print records for the current scope (if you want to include record details in the graph)
    for (const auto& pair : records) {
        out << "n" << currentNode << " -> " << "r" << nodeCount << " [label=\"" << pair.first << "\"];\n";
        out << "r" << nodeCount << " [shape=record, label=\"{" << pair.first << "|ID: " << pair.second->getId() << "|Type: " << pair.second->getType() << "}\"];\n";
        nodeCount++;
    }

    // Recursively print child scopes
    for (const auto child : childScopes) {
        int childNode = nodeCount;
        child->generateDotContent(out, nodeCount);
        // Draw edge to child node
        out << "n" << currentNode << " -> n" << childNode << ";\n";
    }
}

};




#endif
