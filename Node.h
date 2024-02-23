#ifndef NODE_H
#define NODE_H

#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include "SymbolTable.hpp" // Include the SymbolTable definition

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
        return "";
    }
};

class VarDeclaration : public Node
{
public:
    using Node::Node;
    VarDeclaration(string t, string v, int l) : Node(t, v, l) {}
    string execute(SymbolTable &symbolTable) override
    {
        if (children.size() >= 2)
        {
            std::string varType = children[0]->value;
            std::string varIdentifier = children[1]->value;
            std::cout << "VarDeclaration encountered: Identifier=" << varIdentifier << ", Type=" << varType << std::endl;
            Variable var(varIdentifier, varType);
            symbolTable.put(varIdentifier, var);
        }
    }
};

class MethodDeclaration : public Node
{
public:
    using Node::Node;
    MethodDeclaration(string t, string v, int l) : Node(t, v, l) {}
    string execute(SymbolTable &symbolTable) override
    {
        if (children.size() >= 3)
        {
            symbolTable.enterScope();
            std::string methodType = children[0]->value;
            std::string methodIdentifier = children[1]->value;
            std::cout << "MethodDeclaration encountered: Identifier=" << methodIdentifier << ", Type=" << methodType << std::endl;
            Method method(methodIdentifier, methodType);
            symbolTable.put(methodIdentifier, method);
            children[2]->execute(symbolTable);
            symbolTable.exitScope();
            
        }
    }
};

class Body : public Node
{

public:
    using Node::Node;
    Body(string t, string v, int l) : Node(t, v, l) {}
    string execute(SymbolTable &symbolTable) override
    {
        Node::execute(symbolTable);
    }
};


#endif // NODE_H