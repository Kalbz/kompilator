#include "ASTTraversal.h"
#include <iterator>
#include <memory>

void traverseAST(Node* node, SymbolTable& symbolTable) {
    if (!node) return;

    cout << "Entering node: " << node->type << " with value: " << (node->value.empty() ? "N/A" : node->value) << "\n";

    if (node->type == "ClassDeclaration") {
        cout << "Entering Class Scope: " << node->value << "\n";
        symbolTable.enterScope(node->value, "Class");
    } else if (node->type == "MethodDeclaration") {
        string returnType = ""; // Placeholder for extracting return type
        if (!node->children.empty() && node->children.front()->type == "Type") {
            returnType = node->children.front()->value;
        }
        string methodName = node->value;
        string scopeName = methodName + " (Return Type: " + returnType + ")";
        cout << "Entering Method Scope: " << scopeName << "\n";
        symbolTable.enterScope(scopeName, "Method");

        // Assuming the parameter list is the second child of the method declaration node
        auto paramListNode = std::next(node->children.begin()); // Move iterator to the second child
        if (paramListNode != node->children.end() && (*paramListNode)->type == "Parameter") {
            for (auto& param : (*paramListNode)->children) {
                string paramType = param->children.front()->value; // Assuming the first child of parameter node is the type
                string paramName = param->children.back()->value; // Assuming the last child of parameter node is the name
                cout << "Adding Parameter: " << paramName << " of Type: " << paramType << "\n";
                auto record = std::make_shared<Variable>(paramName, paramType, param->lineno);
                symbolTable.put(paramName, record);
            }
        }
    } else if (node->type == "VarDeclaration") {
        string varType = node->children.front()->value; // Assuming the first child is the type
        string varName = node->value;
        cout << "Adding Variable: " << varName << " of Type: " << varType << "\n";
        auto record = std::make_shared<Variable>(varName, varType, node->lineno);
        symbolTable.put(varName, record);
    }

    // Recursively traverse children
    for (auto& child : node->children) {
        traverseAST(child, symbolTable);
    }

    if (node->type == "ClassDeclaration" || node->type == "MethodDeclaration") {
        cout << "Exiting Scope: " << node->value << "\n";
        symbolTable.exitScope();
    }
}



void traverseASTAndPopulateSymbolTable(Node* node, SymbolTable& symbolTable) {
    if (!node) return;

    // Recursively traverse children
    for (auto& child : node->children) {
        std::cout << "Traversing child: " << child->type << " with value: " << (child->value.empty() ? "N/A" : child->value) << "\n";
        traverseASTAndPopulateSymbolTable(child, symbolTable);
    }

}
