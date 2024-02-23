#include "traversal.hpp"
#include "SymbolTable.hpp"
#include "Variable.hpp"
#include "Method.hpp"
#include "Class.hpp"
#include "Node.h"

void astTraversal(SymbolTable &symbolTable, Node* node)
{
    if (!node)
    {
        return;
    }
    std::cout << "Entering astTraversal for node with type: " << node->type << std::endl;

    if (node->type == "VarDeclaration") {
        // Assuming the first child is the type and the second is the identifier
        if (node->children.size() >= 2) {
            Node* typeNode = node->children[0];
            Node* identifierNode = node->children[1];
            
            // Extracting type and identifier values
            std::string varType = typeNode->value; // Assuming type information is stored in the value
            std::string varIdentifier = identifierNode->value; // Assuming identifier is stored in the value
            
            std::cout << "VarDeclaration encountered: Identifier=" << varIdentifier << ", Type=" << varType << std::endl;
            
            // Creating a Variable object and adding it to the symbol table
            Variable var(varIdentifier, varType);
            symbolTable.put(varIdentifier, Variable(var)); // Assuming symbolTable.put expects a pointer
        }
    } else if (node->type == "MethodDeclaration") {
    std::cout << "MethodDeclaration encountered: " << node->type << std::endl;

    if (node->children.size() >= 3) {
        // Extracting type and identifier from the children
        Node* typeNode = node->children[0];
        Node* identifierNode = node->children[1];
        
        std::string methodType = typeNode->value; // Type of the method
        std::string methodIdentifier = identifierNode->value; // Method name

        std::cout << "Method details: Name=" << methodIdentifier << ", Type=" << methodType << std::endl;

        symbolTable.enterScope();
        // Create a Method object with the extracted details.
        // Adjust the constructor of Method as needed to match these parameters or handle them appropriately.
        Method method(methodIdentifier, methodType);

        // Adjust this to match how your SymbolTable expects to receive a Method object.
        // If SymbolTable.put expects pointers, you need to dynamically allocate and manage the memory.
        symbolTable.put(methodIdentifier, Method(method));
        symbolTable.exitScope();
    }
    
    } else if (node->type == "ClassDeclaration") {
        std::cout << "ClassDeclaration encountered: " << node->value << ", " << node->type << std::endl;

        symbolTable.enterScope();
        Class cls(node->value, node->type);
        symbolTable.put(node->value, Class(cls));
        symbolTable.exitScope();
    }


    for (auto child : node->children)
    {
        astTraversal(symbolTable, child);
    }
}