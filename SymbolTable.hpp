#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <iostream>
#include <string>
#include <map>
#include "Record.hpp"
#include "Method.hpp"
#include "Scope.hpp"

class SymbolTable{
private:
    Scope root;
    Scope* current;

public:
    SymbolTable() : root(Scope()), current(&root) {
    }

    void enterScope(){
        std::cout << "Entering new scope." << std::endl;
        current = current->nextChild();
    }

    void exitScope(){
        std::cout << "Exiting scope." << std::endl;
        if (current != &root) { // Ensure we don't go above the root
            current = current->getParentScope();
        }
    }


    void put(std::string key, Record value){
        current->put(key, value);

    }

    Record lookup(std::string key){
        return current->lookup(key);
    }

    void printTable(){
        root.printScope();
    }
    
    void resetTable(){
        root.resetScope();
        current = &root;
    }

};
#endif