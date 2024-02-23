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

class Node {
public:
    int id, lineno;
    string type, value;
    std::vector<Node*> children;
    
    Node(string t, string v, int l) : type(t), value(v), lineno(l) {}
    Node() : type("uninitialised"), value("uninitialised"), lineno(0) {} // Bison needs this.
  
    void print_tree(int depth = 0) {
        for(int i = 0; i < depth; i++)
            cout << "  ";
        cout << type << ":" << value << endl;
        for(auto i = children.begin(); i != children.end(); i++)
            (*i)->print_tree(depth + 1);
    }
  
    void generate_tree() {
        ofstream outStream;
        char* filename = "tree.dot";
        outStream.open(filename);

        int count = 0;
        outStream << "digraph {" << endl;
        generate_tree_content(count, &outStream);
        outStream << "}" << endl;
        outStream.close();

        printf("\nBuilt a parse-tree at %s. Use 'make tree' to generate the pdf version.\n\n", filename);
    }

    void generate_tree_content(int &count, ofstream *outStream) {
        id = count++;
        *outStream << "n" << id << " [label=\"" << type << ":" << value << "\"];" << endl;

        for (auto i = children.begin(); i != children.end(); i++) {
            (*i)->generate_tree_content(count, outStream);
            *outStream << "n" << id << " -> n" << (*i)->id << endl;
        }
    }

};



#endif // NODE_H