#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP

#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
#include <iterator>
using std::unordered_map;
using std::stack;
using std::vector;
using std::string;

class FunctionValue {
    bool isOverride;
    vector<vector<string>> types;

    public:
        FunctionValue(bool _isOverride) isOverride(_isOverride) {};
        int insertFunc(vector<string> type);
        int containsType(vector<string> type);
        bool isOverride() { return isOverride; }
};

class VariableValue {
    string type;
    int offset;

    public:
        VariableValue() {};
        void setTypeOffset(string _type, int _offset) { this->type = _type; this->offset = _offset; }
        string getType() { return type; }
        int getOffset() { return offset; }
};

class UnionValue {
    FunctionValue* functions;
    VariableValue* variable;

    public:
        UnionValue() functions(nullptr) : variable(nullptr) {};
        ~UnionValue() {
            if(functions != nullptr) delete functions;
            if(variable != nullptr) delete variable;
        };
};

class TableValue {
    //bool isOverride;
    bool isFunc;
    UnionValue* val;

    public:
        TableValue(bool _isOverride, bool _isFunc) isFunc(_isFunc) {
            val = new UnionValue();
            if(_isFunc) {
                val->functions = new FunctionValue(_isOverride);
            }
            else {
                val->variable = new VariableValue();
            }
        }
        ~TableValue() {
            delete val;
        };
        int insertValue(vector<string> type, int offset);

};

class SymbolTable {
    unordered_map<string, TableValue*> table; // key - name, value - TableValue*
    SymbolTable* parent;
    bool isWhile;
    string funcType = string.empty();

    public:
        SymbolTable(SymbolTable* _parent = nullptr, bool _isWhile = false) parent(_parent) : isWhile(_isWhile) {};
        ~SymbolTable() { 
            for(auto& it : table) {
                delete it.second;
            }
        };
        int insertSymbol(const string& name, vector<string> type, int offset, bool isOverride, bool isFunc);
        int containsSymbol(const string& name, const vector<const string&>& type, bool isFunc = false);
        bool containsName(const string& name);
};

class OffsetStack {
    stack<int> offsets;

    public:
        OffsetStack() = default;
        void newScope() { offsets.push(offsets.top()); }
        void increaseOffset() { offsets.top() += 1; }
};

class TableStack {
    stack<int> offsets;
    stack<SymbolTable*> tables;

    public:
        TableStack() {
            SymbolTable* base = new SymbolTable();
            tables.push(base);
            offsets.push(0);

            base->insertSymbol("print", {"void", "string"}, 0, false, true);
            base->insertSymbol("printi", {"void", "int"}, 0, false, true);
        };
        ~TableStack() = default;
        bool isInCurrentScope(const string& name);
        int containsSymbol(const string& name, vector<string> type, bool isFunc = false);
        string getType(const string& name);
        bool containsMain();
        bool isCurrentScopeWhile();
        // is while loop in the global scope ?
        void openGlobalScope();
        void newScope(bool isWhileScope = false);
        void closeScope();
        void MakeTable(SymbolTable* parent, bool isWhile);
        int Insert(string name, vector<string> type, int offset, bool isOverride, bool isFunc);
}


#endif