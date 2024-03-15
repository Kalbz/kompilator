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

    // void enterScope(std::string name, std::string type){
    //     std::cout << "Entering new scope." << std::endl;

    //     current = current->nextChild(name, type);
    // }

    // void exitScope(){
    //     std::cout << "Exiting scope." << std::endl;
    //     if (current != &root) { // Ensure we don't go above the root
    //         current = current->getParentScope();
    //     }
    // }

    void enterScope(std::string name, std::string type){
        std::cout << "Entering new scope: " << name << std::endl;
        current = current->createChildScope(name, type);
    }

    void exitScope(){
        std::cout << "Exiting scope: " << current->getName() << std::endl;
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


void generateGraphviz(const std::string &filename) const {
    std::ofstream outStream(filename);
    int nodeCount = 0;
    outStream << "digraph SymbolTable {\n";
    root.generateDotContent(outStream, nodeCount);
    outStream << "}\n";
    outStream.close();
    std::cout << "Generated Graphviz file: " << filename << std::endl;
}


};
#endif