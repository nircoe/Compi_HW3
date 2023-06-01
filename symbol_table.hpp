#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP

#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
#include <iterator>
#include <string>
#include "hw3_output.hpp"

#define SUCCESS 0
#define ERROR_DEF -1
#define ERROR_NO_OVERRIDE -2
#define ERROR_OVERRIDE_NO_DECL -3
#define ERROR_MISMATCH -4
#define ERROR_UNDEF -5
#define ERROR_UNDEF_FUNC -6
#define ERROR_PROTOTYPE_MISMATCH -7
#define ERROR_MAIN_OVERRIDE -8
#define ERROR_AMBIGUOUS_CALL -9

using std::unordered_map;
using std::stack;
using std::vector;
using std::string;

class FunctionValue {

    public:
        bool isOverride;
        vector<vector<string>> types;

        FunctionValue(bool _isOverride) : isOverride(_isOverride) {};
        int insertFunc(vector<string> type);
        int containsType(vector<string> type);
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

    public:
        FunctionValue* functions;
        VariableValue* variable;

        UnionValue() : functions(nullptr) , variable(nullptr) {};
        ~UnionValue() {
            if(functions != nullptr) delete functions;
            if(variable != nullptr) delete variable;
        };
};

class TableValue {

    public:
        bool isFunc;
        UnionValue* val;

        TableValue(bool _isOverride, bool _isFunc) : isFunc(_isFunc) {
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

    public:
        unordered_map<string, TableValue*> table; // key - name, value - TableValue*
        SymbolTable* parent;
        bool isWhile;

        SymbolTable(SymbolTable* _parent = nullptr, bool _isWhile = false) : parent(_parent) , isWhile(_isWhile) {};
        ~SymbolTable() { 
            for(auto& it : table) {
                delete it.second;
            }
        };
        int insertSymbol(const string& name, vector<string> type, int offset, bool isOverride, bool isFunc);
        int containsSymbol(string name, vector<string> type, bool isFunc = false);
        bool containsName(const string& name);
};

class TableStack {

    public:
        stack<int> offsets;
        stack<SymbolTable*> tables;
        string funcType;

        TableStack() : funcType("") {
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
        void newScope(bool isWhileScope = false);
        void closeScope();
        void MakeTable(SymbolTable* parent, bool isWhile);
        int Insert(string name, vector<string> type, int offset, bool isOverride = false, bool isFunc = false);
};


#endif