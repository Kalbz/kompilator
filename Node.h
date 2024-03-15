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
};

class VarDeclaration : public Node
{
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

            children[2]->execute(symbolTable);
            if (children.size() == 4)
            {
                children[3]->execute(symbolTable);
            }
            symbolTable.exitScope();
            
        }
        return result;
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
        }
        return result;
    }
};
// class Body : public Node
// {

// public:
//     using Node::Node;
//     Body(string t, string v, int l) : Node(t, v, l) {}
//     string execute(SymbolTable &symbolTable) override
//     {
//         Node::execute(symbolTable);
//     }
// };



#endif // NODE_H

