#ifndef NODE_H
#define NODE_H

#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include "SymbolTable.hpp" // Include the SymbolTable definition
#include "Class.hpp"

using namespace std;

class Node
{
public:
    int id, lineno;
    string type, value;
    std::vector<Node *> children;
    std::string lhsType;
    std::string rhsType;

    Node(string t, string v, int l) : type(t), value(v), lineno(l) {}
    Node() : type("uninitialised"), value("uninitialised"), lineno(0) {} // Bison needs this.

    void print_tree(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            cout << "  ";
        cout << type << ":" << value << endl;
        for (auto i = children.begin(); i != children.end(); i++)
            (*i)->print_tree(depth + 1);
    }

    // void print_tree(int depth = 0) {
    //     for (int i = 0; i < depth; i++)
    //         cout << "  ";
    //     cout << type << ":" << value << endl;
    //     for (auto child : children)
    //         if (child != nullptr) child->print_tree(depth + 1);
    // }


    void generate_tree()
    {
        ofstream outStream;
        char *filename = "tree.dot";
        outStream.open(filename);

        int count = 0;
        outStream << "digraph {" << endl;
        generate_tree_content(count, &outStream);
        outStream << "}" << endl;
        outStream.close();

        printf("\nBuilt a parse-tree at %s. Use 'make tree' to generate the pdf version.\n\n", filename);
    }

    void generate_tree_content(int &count, ofstream *outStream)
    {
        id = count++;
        *outStream << "n" << id << " [label=\"" << type << ":" << value << "\"];" << endl;

        for (auto i = children.begin(); i != children.end(); i++)
        {
            (*i)->generate_tree_content(count, outStream);
            *outStream << "n" << id << " -> n" << (*i)->id << endl;
        }
    }

    virtual string execute(SymbolTable &symbolTable)
    {
        std::string result = "";

        if (!children.empty())
        {
            for (unsigned int i = 0; i < children.size(); i++)
            {
                cout << "Executing " << children[i]->type << " " << children[i]->value << endl;
                if (children[i] != nullptr)
                {
                    children[i]->execute(symbolTable);
                }
            }
        }
        return result;
    }

    virtual std::string performSemanticAnalysis(SymbolTable &symbolTable)
    {
        std::string result = "";

        if (!children.empty())
        {
            for (unsigned int i = 0; i < children.size(); i++)
            {
                children[i]->performSemanticAnalysis(symbolTable);
            }
        }
        return result;
    }

    virtual std::string performSemanticAnalysisFromRoot(SymbolTable &SymbolTable){
        return "";
    
    }
    
    virtual std::vector<std::string> getArgument(SymbolTable& symbolTable){
        }
};

class VarDeclaration : public Node
{

private:
    std::string returnType;
    std::string name;
public:
    using Node::Node;
    VarDeclaration(string t, string v, int l) : Node(t, v, l) {}
    string execute(SymbolTable &symbolTable) override
    {
        std::string result = "";
        if (children.size() >= 2)
        {
            std::string varType = children[0]->value;
            std::string varIdentifier = children[1]->value;

            std::cout << "VarDeclaration encountered: Identifier=" << varIdentifier << ", Type=" << varType << std::endl;
            Variable var(varIdentifier, varType);
            symbolTable.put(varIdentifier, var);
        }
        return result;
    }
		string performSemanticAnalysis(SymbolTable& symbolTable) override {

			returnType = children[0]->performSemanticAnalysis(symbolTable); //type
            std::cout << returnType << " is the return type" << std::endl;
			name = children[1]->performSemanticAnalysis(symbolTable); //identiier

			if(returnType == "int" || returnType == "boolean" || returnType == "int[]" || returnType == "String[]"){
			} else {
                try {
                    symbolTable.lookup(returnType);
                    // If lookup is successful, no action needed.
                } catch (const std::runtime_error& e) {
                    // If an exception is caught, the record was not found.
                    std::cout << "Error: Type " << returnType << " not found" << std::endl;
                }
            }
            return "";
        }
};

class MethodDeclaration : public Node
{
public:
    using Node::Node;
    MethodDeclaration(string t, string v, int l) : Node(t, v, l) {}
    string execute(SymbolTable &symbolTable) override
    {
        std::string result = "";
        if (children.size() >= 3)
        {
            
            std::string methodType = children[0]->value;
            std::string methodIdentifier = children[1]->value;
            symbolTable.enterScope(methodIdentifier, methodType);
            std::cout << "MethodDeclaration encountered: Identifier=" << methodIdentifier << ", Type=" << methodType << std::endl;
            Method method(methodIdentifier, methodType);
            symbolTable.put(methodIdentifier, method);

            Method* newMethod = new Method(methodIdentifier, methodType);
            // Assuming your symbol table or scope can manage Method* lifetime properly:
            symbolTable.getCurrentScope()->setCurrentMethod(newMethod);

            children[2]->execute(symbolTable);
            if (children.size() == 4)
            {
                children[3]->execute(symbolTable);
            }
            symbolTable.exitScope();
            
        }
        return result;
    }
    string performSemanticAnalysis(SymbolTable& symbolTable) override {
        symbolTable.enterScope(children[1]->value, children[0]->value);
        children[2]->performSemanticAnalysis(symbolTable);
        if (children.size() == 4)
        {
            children[3]->performSemanticAnalysis(symbolTable);
        }
        symbolTable.exitScope();
        return "";
        }
};

class ClassDeclaration : public Node
{
public:
    using Node::Node;
    ClassDeclaration(string t, string v, int l) : Node(t, v, l) {}
    string execute(SymbolTable &symbolTable) override
    {
        std::string result = "";
        if (children.size() == 2)
        {
            std::string classIdentifier = children[0]->value;
            symbolTable.enterScope(classIdentifier, "Class");
            std::cout << "ClassDeclaration encountered: Identifier=" << classIdentifier << std::endl;
            Class classObj(classIdentifier);
            symbolTable.put(classIdentifier, classObj);

            children[1]->execute(symbolTable);
            symbolTable.exitScope();
        }
        else if (children.size() == 3)
        {
            std::string classIdentifier = children[0]->value;
            std::string classExtends = children[1]->value;
            symbolTable.enterScope(classIdentifier, "Class");
            std::cout << "ClassDeclaration encountered: Identifier=" << classIdentifier << std::endl;
            Class classObj(classIdentifier, classExtends);
            symbolTable.put(classIdentifier, classObj);
            children[1]->execute(symbolTable);
            children[2]->execute(symbolTable);
            symbolTable.exitScope();

        }
        return result;
    }
        string performSemanticAnalysis(SymbolTable& symbolTable) override {
        symbolTable.enterScope(children[0]->value, "Class");
        children[1]->performSemanticAnalysis(symbolTable);
        symbolTable.exitScope();
        return "";
		}
};

class Parameter : public Node
{
public:
    using Node::Node;
    Parameter(string t, string v, int l) : Node(t, v, l) {}
    string execute(SymbolTable &symbolTable) override
    {
        std::string result = "";
        if (children.size() >= 2)
        {
            children[0]->execute(symbolTable);
            children[1]->execute(symbolTable);
            std::string varType = children[0]->value;
            std::string varIdentifier = children[1]->value;

            std::cout << "Parameter encountered: Identifier=" << varIdentifier << ", Type=" << varType << std::endl;
            Variable var(varIdentifier, varType);
            symbolTable.put(varIdentifier, var);

            
            Scope* classScope = symbolTable.getCurrentScope()->findNearestClassScope();
                if (classScope != nullptr) {
                    std::cout << "Current class scope: " << classScope->getName() << std::endl;
                    


                } else {
                    std::cout << "Parameter not within a class scope." << std::endl;
                }

        // Find the current method scope
                Scope* methodScope = symbolTable.getCurrentScope()->findNearestMethodScope();
                if (methodScope != nullptr) {
                    Method* currentMethod = methodScope->getCurrentMethod();
                    if (currentMethod != nullptr) {
                        // Add the parameter to the method
                        currentMethod->addParameter(varIdentifier, varType);
                        std::cout << "executed" << std::endl;
                    } else {
                        std::cout << "No current method in scope." << std::endl;
                    }
                } else {
                    std::cout << "Parameter not within a method scope." << std::endl;
                }
            }
            return result;
    }
};



class IntExpression : public Node{

	public:
		using Node::Node;
		string performSemanticAnalysis(SymbolTable& symbolTable) override {
			lhsType = children[0]->performSemanticAnalysis(symbolTable);
			rhsType = children[1]->performSemanticAnalysis(symbolTable);
			if((lhsType != "int") || (rhsType != "int")){
                std::cout << "Types are not the same" << std::endl;
			}
			return "int";
		}
};


class BooleanExpression : public Node{

	public:
		using Node::Node;
		string performSemanticAnalysis(SymbolTable& symbolTable) override {
			lhsType = children[0]->performSemanticAnalysis(symbolTable);
            std::cout << lhsType << " is the left hand side type" << std::endl;
			rhsType = children[1]->performSemanticAnalysis(symbolTable);
            std::cout << rhsType << " is the right hand side type" << std::endl;
			if((lhsType != "boolean") || (rhsType != "boolean")){
                std::cout << lhsType << ":Types are not the same:" << rhsType << std::endl;	
            }
			return "boolean";
		}
};

class EqualExpression : public Node{

    public:
        using Node::Node;
        string performSemanticAnalysis(SymbolTable& symbolTable) override {
            lhsType = children[0]->performSemanticAnalysis(symbolTable);
            rhsType = children[1]->performSemanticAnalysis(symbolTable);
            if(lhsType != rhsType){
                std::cout << "Types are not the same" << std::endl;
            }
            return "boolean";
        }
};

class LessThanExpression : public Node{

    public:
        using Node::Node;
        string performSemanticAnalysis(SymbolTable& symbolTable) override {
            lhsType = children[0]->performSemanticAnalysis(symbolTable);
            rhsType = children[1]->performSemanticAnalysis(symbolTable);
            if((lhsType != "int") || (rhsType != "int")){
                std::cout << "Types are not the same" << std::endl;
            }
            return "boolean";
        }
};

class GreaterThanExpression : public Node{

    public:
        using Node::Node;
        string performSemanticAnalysis(SymbolTable& symbolTable) override {
            lhsType = children[0]->performSemanticAnalysis(symbolTable);
            rhsType = children[1]->performSemanticAnalysis(symbolTable);
            if((lhsType != "int") || (rhsType != "int")){
                std::cout << "Types are not the same" << std::endl;
            }
            return "boolean";
        }
};

class NotExpression : public Node{

    public:
        using Node::Node;
        string performSemanticAnalysis(SymbolTable& symbolTable) override {
            lhsType = children[0]->performSemanticAnalysis(symbolTable);
            if(lhsType != "boolean"){
                std::cout << "Types are not the same" << std::endl;
            }
            return "boolean";
        }
};

class New : public Node{
    public:
        using Node::Node;
        string performSemanticAnalysis(SymbolTable& symbolTable) override {
			lhsType = children[0]->performSemanticAnalysisFromRoot(symbolTable);
			return lhsType;
        }
};

class Length : public Node{
    public:
        using Node::Node;
        string performSemanticAnalysis(SymbolTable& symbolTable) override {
            lhsType = children[0]->performSemanticAnalysis(symbolTable);
            if(lhsType != "int[]"){
                std::cout << "Types are not the same" << std::endl;
            }
            return "int";
        }
};


class Type : public Node{
    public:
        using Node::Node;
        string execute(SymbolTable &symbolTable) override {
            return this->value;
        }
        string performSemanticAnalysis(SymbolTable& symbolTable) override {
            std::cout << "This is what im testing type right now: " << this->value << std::endl;
            return this->value;
        }
};

class Identifier : public Node {
public:
    using Node::Node;

    string execute(SymbolTable &symbolTable) override {
        return this->value;
    }

    string performSemanticAnalysis(SymbolTable& symbolTable) override {
        std::cout << "This is Identifier: " << this->value << std::endl;
        try {
            Record symbol = symbolTable.lookup(this->value);

            // If found, you could return its type or just confirm it's valid.
            if (!symbol.isValid()) {
                cout << "Semantic Error: Identifier '" << this->value << "' is undeclared." << endl;
                return "error";
            }
            return symbol.getType();
        } catch (const std::runtime_error& e) {
            // Handle the exception as an undeclared identifier error.
            cout << "Semantic Error: Identifier '" << this->value << "' is undeclared." << endl;
            return "error";
        }
    }

    string performSemanticAnalysisFromRoot(SymbolTable& symbolTable) override {
        std::cout << "This is Identifier: " << this->value << std::endl;
        try {
            Record symbol = symbolTable.lookup(this->value);

            // If found, you could return its type or just confirm it's valid.
            if (!symbol.isValid()) {
                cout << "Semantic Error: Identifier '" << this->value << "' is undeclared." << endl;
                return "error";
            }
            return symbol.getType();
        } catch (const std::runtime_error& e) {
            // Handle the exception as an undeclared identifier error.
            cout << "Semantic Error: Identifier '" << this->value << "' is undeclared." << endl;
            return "error";
        }
    }
};

class Index : public Node{
    public:
        using Node::Node;
        string performSemanticAnalysis(SymbolTable& symbolTable) override {
            lhsType = children[0]->performSemanticAnalysis(symbolTable);
            rhsType = children[1]->performSemanticAnalysis(symbolTable);
            if(lhsType != "int[]"){
                std::cout << "Types are not the same" << std::endl;
            }
            if(rhsType != "int"){
                std::cout << "Types are not the same" << std::endl;
            }
            return "int";
        }
};

class IntArray : public Node{
    public:
        using Node::Node;
        string performSemanticAnalysis(SymbolTable& symbolTable) override {
            lhsType = children[0]->performSemanticAnalysis(symbolTable);
            if(lhsType != "int"){
                std::cout << "Types are not the same" << std::endl;
            }
            return "int[]";
        }

};

class BooleanFactor : public Node{
    public:
        using Node::Node;
        string performSemanticAnalysis(SymbolTable& symbolTable) override {
            return "boolean";
            // lhsType = children[0]->performSemanticAnalysis(symbolTable);
            // if(lhsType != "boolean"){
            //     std::cout << "Types are not the same" << std::endl;
            // }
            // return "boolean";
        }
};

class IntFactor : public Node{
    public:
        using Node::Node;
        string performSemanticAnalysis(SymbolTable& symbolTable) override {
            return "int";
            // lhsType = children[0]->performSemanticAnalysis(symbolTable);
            // if(lhsType != "int"){
            //     std::cout << "Types are not the same" << std::endl;
            // }
            // return "int";
        }
};

class ClassFactor : public Node{
    public:
        using Node::Node;
        string performSemanticAnalysis(SymbolTable& symbolTable) override {
            // lhsType = children[0]->performSemanticAnalysis(symbolTable);
            // if(lhsType != "Class"){
            //     std::cout << "Types are not the same" << std::endl;
            // }
            // return "Class";
            auto temp = symbolTable.lookup("this");
            return temp.getType();
        }
};

class Return : public Node{
    // I want the return type to be the same as the method type
    public:
        using Node::Node;
        string performSemanticAnalysis(SymbolTable& symbolTable) override {
            std::string returnType = children[0]->performSemanticAnalysis(symbolTable);
            std::string methodType = symbolTable.getCurrentScope()->getType();

            std::cout << returnType << " is the return type" << std::endl;
            std::cout << methodType << " is the method type" << std::endl;
            if(returnType != methodType){
                std::cout << "Types are not the same" << std::endl;
            }
            return "";
        }
};

// class MethodCall : public Node{
//     public:
//         using Node::Node;
//         string performSemanticAnalysis(SymbolTable& symbolTable) override {
//             std::string returnType = children[0]->performSemanticAnalysis(symbolTable);
//             std::string methodType = symbolTable.lookup(returnType).getType();
//             std::vector<std::string> arguments = children[1]->getArgument(symbolTable);
//             std::vector<std::string> parameters = symbolTable.lookup(returnType).getParameters(symbolTable);
//             if(arguments.size() != parameters.size()){
//                 std::cout << "Number of arguments does not match number of parameters" << std::endl;
//             }
//             for(unsigned int i = 0; i < arguments.size(); i++){
//                 if(arguments[i] != parameters[i]){
//                     std::cout << "Types are not the same" << std::endl;
//                 }
//             }
//             return methodType;
//         }
// };

class Arguments : public Node{
    private:
        std::vector<std::string> argumentTypes;
    public:
        using Node::Node;
        std::vector<std::string> getArguments(SymbolTable& symbolTable){
			for(unsigned int i = 0; i < children.size(); i++){
				lhsType = children[i]->performSemanticAnalysis(symbolTable);
				argumentTypes.push_back(lhsType);
			}

			return argumentTypes;
		}
};

class IfElseWhile : public Node{
    public:
        using Node::Node;
        string performSemanticAnalysis(SymbolTable& symbolTable) override {
            std::string returnType = children[0]->performSemanticAnalysis(symbolTable);
            if(returnType != "boolean"){
                std::cout << "Type must be Bool " << std::endl;
            }
			for(unsigned int i = 1; i < children.size(); i++){
				children[i]->performSemanticAnalysis(symbolTable);
			}
            return "";
        }
};

class Assignment : public Node {
public:
    using Node::Node;
    string performSemanticAnalysis(SymbolTable& symbolTable) override {
        // First, ensure the LHS identifier exists in the symbol table.
        std::string lhsIdentifier = children[0]->value; // Assuming the LHS child is an Identifier node.
        Record lhsRecord;

        try {
            lhsRecord = symbolTable.lookup(lhsIdentifier);
        } catch (const std::runtime_error& e) {
            std::cout << "Semantic Error: Variable '" << lhsIdentifier << "' is undeclared." << std::endl;
            return "error";
        }

        // If the LHS record is invalid, it means the identifier was not declared.
        if (!lhsRecord.isValid()) {
            std::cout << "Semantic Error: Variable '" << lhsIdentifier << "' is undeclared." << std::endl;
            return "error";
        }

        // Perform semantic analysis on both LHS and RHS to determine their types.
        lhsType = children[0]->performSemanticAnalysis(symbolTable);
        rhsType = children[1]->performSemanticAnalysis(symbolTable);

        // Ensure the types match.
        if (lhsType != rhsType) {
            std::cout << "Type Error: Cannot assign " << rhsType << " to " << lhsType << "." << std::endl;
            return "error";
        }

        // If everything checks out, return a successful result (empty string or specific success code).
        return "";
    }
};




#endif // NODE_H

