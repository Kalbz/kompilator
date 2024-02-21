#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include <algorithm>

using namespace std;

class Node
{
public:
    int id, lineno;
    string type, value;
    string lhsType, rhsType;
    vector<Node *> children;
    Node(string t, string v, int l) : type(t), value(v), lineno(l) {}
    Node()
    {
        type = "uninitialised";
        value = "uninitialised";
    } // Bison needs this.

    void print_tree(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            cout << "  ";
        cout << type << ":" << value << endl; //<< " @line: "<< lineno << endl;
        for (unsigned int i = 0; i < children.size(); i++)
        {
            children[i]->print_tree(depth + 1);
        }
    }

    void generate_tree()
    {
        std::ofstream outStream;
        char *filename = "tree.dot";
        outStream.open(filename);

        int count = 0;
        outStream << "digraph {" << std::endl;
        generate_tree_content(count, &outStream);
        outStream << "}" << std::endl;
        outStream.close();

        printf("\nBuilt a parse-tree at %s. Use 'make tree' to generate the pdf version.\n", filename);
    }

    void generate_tree_content(int &count, ofstream *outStream)
    {
        id = count++;
        *outStream << "n" << id << " [label=\"" << type << ":" << value << "\"];" << endl;
        for (unsigned int i = 0; i < children.size(); i++)
        {
            children[i]->generate_tree_content(count, outStream);
            *outStream << "n" << id << " -> n" << children[i]->id << endl;
        }
    }
};

#endif /* NODE_H */