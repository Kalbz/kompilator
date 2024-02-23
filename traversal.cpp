// #include "traversal.hpp"
// #include "SymbolTable.hpp"
// #include "Variable.hpp"
// #include "Method.hpp"
// #include "Class.hpp"
// #include "Node.h"

// void astTraversal(SymbolTable &symbolTable, Node* node)
// {
//     if (!node)
//     {
//         return;
//     }
//     std::cout << "Entering astTraversal for node with type: " << node->type << std::endl;

//     if (node->type == "VarDeclaration") {
//         // Assuming the first child is the type and the second is the identifier
//         if (node->children.size() >= 2) {
//             Node* typeNode = node->children[0];
//             Node* identifierNode = node->children[1];
            
//             // Extracting type and identifier values
//             std::string varType = typeNode->value; // Assuming type information is stored in the value
//             std::string varIdentifier = identifierNode->value; // Assuming identifier is stored in the value
            
//             std::cout << "VarDeclaration encountered: Identifier=" << varIdentifier << ", Type=" << varType << std::endl;
            
//             // Creating a Variable object and adding it to the symbol table
//             Variable var(varIdentifier, varType);
//             symbolTable.put(varIdentifier, Variable(var)); // Assuming symbolTable.put expects a pointer
//         }
//     } else if (node->type == "MethodDeclaration") {
//     std::cout << "MethodDeclaration encountered: " << node->type << std::endl;

//     if (node->children.size() >= 3) {
//         // Extracting type and identifier from the children
//         Node* typeNode = node->children[0];
//         Node* identifierNode = node->children[1];
        
//         std::string methodType = typeNode->value; // Type of the method
//         std::string methodIdentifier = identifierNode->value; // Method name

//         std::cout << "Method details: Name=" << methodIdentifier << ", Type=" << methodType << std::endl;

//         symbolTable.enterScope();
//         // Create a Method object with the extracted details.
//         // Adjust the constructor of Method as needed to match these parameters or handle them appropriately.
//         Method method(methodIdentifier, methodType);

//         // Adjust this to match how your SymbolTable expects to receive a Method object.
//         // If SymbolTable.put expects pointers, you need to dynamically allocate and manage the memory.
//         symbolTable.put(methodIdentifier, Method(method));
//         symbolTable.exitScope();
//     }

//     } else if (node->type == "ClassDeclaration") {
//     // Assuming the first child of a ClassDeclaration node is always the class identifier
//     Node* identifierNode = node->children[0];
//     std::string className = identifierNode->value;
//     std::cout << "ClassDeclaration encountered: " << className << std::endl;

//     // Enter a new scope for the class
//     symbolTable.enterScope();

//     // Here, create a Class object that will hold information about its members
//     Class cls(className);

//     // Iterate over the remaining children to process variable and method declarations
//     for (size_t i = 1; i < node->children.size(); ++i) {
//         Node* child = node->children[i];
//         if (child->type == "VarDeclaration") {
//             // Process variable declaration
//             Node* typeNode = child->children[0];
//             Node* varNameNode = child->children[1];
//             std::string varType = typeNode->value;
//             std::string varName = varNameNode->value;

//             // Add this variable to the class
//             cls.addVariable(varName, varType);
//         } else if (child->type == "MethodDeclaration") {
//             // Similar to your existing method processing logic
//             // Extract method details and add to the class
//             Node* typeNode = child->children[0];
//             Node* methodNameNode = child->children[1];
//             std::string methodType = typeNode->value;
//             std::string methodName = methodNameNode->value;

//             // Assuming Method is a class that represents method declarations
//             cls.addMethod(methodName, methodType);
//         }
//         // Handle other possible child types if necessary
//     }

//     // After processing all children and adding members to the class,
//     // add the class itself to the symbol table.
//     // Adjust this according to how your SymbolTable is implemented.
//     symbolTable.put(className, cls);

//     // Do not exit the scope here if you want the scope created by a class declaration to encompass its members
//     // Exiting scope might be done after all class processing is complete, depending on your design.
// }



//     for (auto child : node->children)
//     {
//         astTraversal(symbolTable, child);
//     }
// }