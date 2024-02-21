#ifndef VARIABLE_H
#define VARIABLE_H

#include <iostream>
#include <string>
#include <map>
#include "Record.hpp"
#include "Method.hpp"
#include "Scope.hpp"

class SymbolTable{
private:
    Scope root;
    Scope current;

public:
    SymbolTable(){
        root =  Scope();
        current = root;

    }
    void enterScope(){
        current = *current.nextChild();
    }
    
    void exitScope(){
        current = *current.getParentScope();
    }

    void put(std::string key, Record value){
        current.put(key, value);

    }

    Record lookup(std::string key){
        return current.lookup(key);
    }

    void printTable(){
        root.printScope();
    }
    
    void resetTable(){
        root.resetScope();
        current = root;
    }

};
#endif