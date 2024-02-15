#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <memory>

class Record {
private:
    std::string id;
    std::string type;
    int lineno;

public:
    // Constructors
    Record(const std::string& i, const std::string& t, int l = 0) : id(i), type(t), lineno(l) {}
    Record() : id(""), type(""), lineno(0) {}

    // Setters
    void setId(const std::string& value) { id = value; }
    void setType(const std::string& value) { type = value; }
    void setLineno(int value) { lineno = value; }

    // Getters
    std::string getId() const { return id; }
    std::string getType() const { return type; }
    int getLineno() const { return lineno; }

    // Utility method
    void printRecord() const {
        std::cout << "id: " << id << " type: " << type << " line: " << lineno << std::endl;
    }

    // Virtual destructor for polymorphism support
    virtual ~Record() {}
};

class Variable: public Record {
public:
    using Record::Record; // Inherits constructors from Record
};

class Method: public Record {
private:
    std::vector<std::shared_ptr<Variable>> parameters;
    std::map<std::string, std::shared_ptr<Variable>> variables;

public:
    using Record::Record; // Inherits constructors from Record

    void addParameter(std::shared_ptr<Variable> var) {
        parameters.push_back(var);
    }

    void addVariable(const std::string& str, std::shared_ptr<Variable> var) {
        variables.insert({str, var});
    }

    std::vector<std::shared_ptr<Variable>> getParameters() const {
        return parameters;
    }
    
    std::shared_ptr<Variable> lookup(const std::string& name) const {
        // First, search in the parameters list
        auto paramIt = std::find_if(parameters.begin(), parameters.end(),
                                    [&name](const std::shared_ptr<Variable>& var) { return var->getId() == name; });
        if (paramIt != parameters.end()) {
            return *paramIt;
        }

        // If not found, search in the variables map
        auto varIt = variables.find(name);
        if (varIt != variables.end()) {
            return varIt->second;
        }

        // If the variable is not found in either collection
        return nullptr;
    }
};

class Class: public Record {
private:
    std::map<std::string, std::shared_ptr<Variable>> variables;
    std::map<std::string, std::shared_ptr<Method>> methods;

public:
    using Record::Record; // Inherits constructors from Record

    void addVariable(const std::string& str, std::shared_ptr<Variable> var) {
        variables[str] = var;
    }

    void addMethod(const std::string& str, std::shared_ptr<Method> method) {
        methods[str] = method;
    }

    bool lookupVariable(const std::string& key) const {
        return variables.find(key) != variables.end();
    }

    std::shared_ptr<Method> lookupMethod(const std::string& key) const {
        auto it = methods.find(key);
        if(it != methods.end()){
            return it->second;
        }
        return nullptr;
    }
};

class SymbolTable {
private:
    std::shared_ptr<Scope> root;
    std::shared_ptr<Scope> current;
    std::string semanticErrors;

public:
    SymbolTable() : root(std::make_shared<Scope>(nullptr, "", "Program")), current(root) {}

    void enterScope(const std::string& n = "", const std::string& t = "") {
        current = current->nextChild(n, t);
    }

    void exitScope() {
        if (auto parent = current->getParent()) {
            current = parent;
        }
    }

    void put(const std::string& key, std::shared_ptr<Record> item) {
        current->addRecord(key, item);
    }

    std::shared_ptr<Record> lookup(const std::string& key) {
        return current->lookup(key);
    }

    std::shared_ptr<Record> lookupParent(const std::string& key) {
        if (auto parent = current->getParent()) {
            return parent->lookup(key);
        }
        return nullptr;
    }

    std::shared_ptr<Record> lookupCurrentScope(const std::string& key) {
        return current->lookupCurrentScope(key);
    }

    std::shared_ptr<Record> lookupRoot(const std::string& key) {
        return root->lookupCurrentScope(key);
    }

    void resetTable() {
        root->resetScope(); // Preparation for new traversal
    }

    void printTable() {
        if (root) {
            root->printScopeTree(); // Call the correctly named method to print the scope tree
        }
    }

    void printRoot() {
        root->printScope();
    }

    void printCurrentScope() {
        current->printScope();
    }

    void generateST() {
        resetTable();
        std::ofstream outStream("st.dot");

        outStream << "digraph ScopeTree {\n";
        int nodeId = 0;
        root->generateDotGraph(outStream, nodeId);
        outStream << "}\n";

        outStream.close();
        std::cout << "\nBuilt a symbol-table-tree at st.dot. Use 'make st' to generate the pdf version.\n\n";
    }

    void addLog(int lineno, const std::string& errorMsg) {
        semanticErrors.append("\t@error at line " + std::to_string(lineno) + ". " + errorMsg + ".\n");
    }

    std::string getLog() const {
        return semanticErrors;
    }
};

class Scope : public std::enable_shared_from_this<Scope> {
private:
    int id = 0;
    std::string name;
    std::string type;
    std::weak_ptr<Scope> parentScope;
    std::vector<std::shared_ptr<Scope>> childrenScopes;
    std::map<std::string, std::shared_ptr<Record>> records;

public:
    Scope(std::shared_ptr<Scope> parent, const std::string& n, const std::string& t) : name(n), type(t), parentScope(parent) {}

    std::shared_ptr<Scope> nextChild(const std::string& n, const std::string& t) {
        auto child = std::make_shared<Scope>(shared_from_this(), n, t);
        childrenScopes.push_back(child);
        return child;
    }

    std::shared_ptr<Record> lookup(const std::string& key) {
        auto it = records.find(key);
        if (it != records.end()) {
            return it->second;
        }
        if (auto parent = parentScope.lock()) {
            return parent->lookup(key);
        }
        return nullptr;
    }

    std::shared_ptr<Record> lookupCurrentScope(const std::string& key) const {
        auto it = records.find(key);
        if (it != records.end()) {
            return it->second;
        }
        return nullptr;
    }

    void addRecord(const std::string& key, std::shared_ptr<Record> item) {
        records[key] = item;
    }

    std::shared_ptr<Scope> getParent() const {
        return parentScope.lock();
    }

    void printScope(const std::string& tab = "") const {
        for (const auto& record : records) {
            std::cout << tab << "Name: " << record.first << "; Record: " << record.second->getType() << "; Type: " << record.second->getId() << std::endl;
        }
        for (const auto& child : childrenScopes) {
            child->printScope(tab + "  ");
        }
    }

   // Resets the scope for a new analysis or compilation pass
    void resetScope() {
        for (auto& child : childrenScopes) {
            child->resetScope();
        }
        // Optionally clear records and other stateful data if necessary
    }

    // Prints the current scope and its children recursively with indentation for readability
    void printScopeTree(const std::string& indent = "") const {
        std::cout << indent << "Scope: " << name << " (" << type << ")" << std::endl;
        for (const auto& record : records) {
            std::cout << indent << "  Record: " << record.first << ", Type: " << record.second->getType() << std::endl;
        }
        for (const auto& child : childrenScopes) {
            child->printScopeTree(indent + "  ");
        }
    }

    // Generates a DOT graph representation of the scope tree for visualization
    void generateDotGraph(std::ostream& out, int& nodeId, int parentId = -1) const {
        int myNodeId = nodeId++;
        out << "  node" << myNodeId << " [label=\"" << name << "\\n(" << type << ")\"];\n";
        if (parentId != -1) {
            out << "  node" << parentId << " -> node" << myNodeId << ";\n";
        }
        for (const auto& child : childrenScopes) {
            child->generateDotGraph(out, nodeId, myNodeId);
        }
    }

    // Public method to start the DOT graph generation
    void generateDotGraph(std::ostream& out) const {
        out << "digraph ScopeTree {\n";
        int nodeId = 0;
        generateDotGraph(out, nodeId);
        out << "}\n";
    }
};