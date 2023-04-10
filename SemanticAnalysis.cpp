/* You are supposed to do the following:
• Write a tree traversal algorithm, which will visit all the nodes of the AST. Note that we already
have a tree traversal algorithm implemented for the print-tree function, which basically visits each
node of the tree and prints their name and type.
• Design a data-structure for the symbol table, which is able to store all the necessary information
for all identifiers.
• Perform a single left-to-right tree traversal and populate the symbol table.
• For debugging and demonstration purposes, write a method that prints the symbol table (the name
and the type for each record in the symbol table). You may as well generate a graphviz (.dot) file
if you want to visualize the symbol table, similarly to what we do for the AST. In that case, a
command ”make st” to generate the pdf version of the symbol table is expected in the Makefile

For each type of the identifiers (e.g., classes, methods, and variables) use a different type of records
in the symbol table. A record represents an identifier in the symbol table. I therefore suggest a
hierarchy of record types.
• The symbol table should be able to deal with the scopes of the identifiers. For instance, the
variables defined inside a class could be accessed from anywhere in the class, whereas identifiers
defined inside a method could only be accessed from that method. Note that in MiniJava, we can
not define variables inside of a block-statement scope, hence we do not consider the cases where we
define new variables inside the body of the if-else and while statements (in such cases we would
need a nested level of scopes).

Note that the construction of the ST is concerned only with the declarations of identifiers (including
variables, methods, and classes) in our program. The way those identifiers will be used is considered
in the semantic analysis phase.
• Write a method for printing the symbol table and use it to verify the correctness of your solution.
An example of the symbol table for one of the programs in the set of valid Java classes is provided
in slide 14 of the Semantic Analysis lecture.


Pre order tree traversal algorithm to cosntruct symbol  table


Variable names, function names, classes, methods IDENTIFIERS 

pre order
insert
lookup
delete
enter_scope
exit scope

*/

#include <iostream>
#include <string>
#include <list>
#include <unordered_map>
#include <memory>

class Record {
public:
  std::string id;
  std::string type;
  
  Record(std::string n, std::string t) : id(n), type(t) {}
};


class ClassRecord : public Record {
public:
  list<Record*> fields;
  list<Record*> methods;
  ClassRecord(std::string n, std::string t) : Record(n, t) {}
};

class MethodRecord : public Record {
public:
  list<Record*> parameters;
  list<Record*> locals;
  MethodRecord(std::string n, std::string t) : Record(n, t) {}
};

class VariableRecord : public Record {
public:
  VariableRecord(std::string n, std::string t) : Record(n, t) {}
};

class Scope {
public:
  std::unordered_map<std::string, std::unique_ptr<Record>> records;
  Scope() {}
};

class SymbolTable {
public:
  list<Scope*> scopes;
  SymbolTable() {}
  void insert(std::unique_ptr<Record> r) {
    scopes.back()->records[r->id] = std::move(r);
  }

    Record* lookup(const std::string &id) {
        for (auto i = scopes.rbegin(); i != scopes.rend(); ++i) {
            auto it = i->records.find(id);
            if (it != i->records.end()) {
                return it->second.get();
            }
        }
        return nullptr;
  }
  void enter_scope() {
    scopes.emplace_back();
  }
  void exit_scope() {
    scopes.pop_back();
  }
 void print() {
        for (const auto &scope : scopes) {
            for (const auto &record : scope.records) {
                std::cout << record.second->id << " " << record.second->type << std::endl;
            }
        }
    }
};

