#include "ASTTraversal.h"


 void traverseAST(Node* node, SymbolTable& symbolTable) {
    if (!node) return; // Base case: node is null

    // Debugging: Print entering node
    cout << "Entering node: " << node->type << " with value: " << node->value << "\n";

    if (node->type == "ClassDeclaration") {
        cout << "Entering Class Scope: " << node->value << "\n";
        symbolTable.enterScope(node->value, "Class");
    } else if (node->type == "MethodDeclaration") {
        string scopeName = node->value + " (Return Type: " + node->children.front()->value + ")";
        cout << "Entering Method Scope: " << scopeName << "\n";
        symbolTable.enterScope(scopeName, "Method");
        // Add logic to handle method parameters here
    } else if (node->type == "VarDeclaration") {
        string varType = node->children.front()->value; // Assuming the type is the first child
        string varName = node->value;
        cout << "Adding Variable: " << varName << " of Type: " << varType << "\n";
        auto record = std::make_shared<Variable>(varName, varType, node->lineno);
        symbolTable.put(varName, record);
		
    }

    // Recursively traverse children
    for (auto child : node->children) {
        traverseAST(child, symbolTable);
    }

    if (node->type == "ClassDeclaration" || node->type == "MethodDeclaration") {
        cout << "Exiting Scope: " << node->value << "\n";
        symbolTable.exitScope();
    }
}
