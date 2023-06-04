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

class TableValue {

    public:
        bool isFunc;
        bool isOverride;
        vector<vector<string>> functions_params_types;
        string type; // or rettype
        int offset;

        TableValue(bool _isFunc, bool _isOverride) : isFunc(_isFunc), isOverride(_isOverride) { };
        int insertValue(string _type, int _offset = 0, vector<string> _params_types = {});
        int containsFunc(vector<string> _params_types);

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
        int insertSymbol(const string& name, string type, vector<string> params_types, int offset, bool isOverride, bool isFunc);
        int containsVariable(string name, string type);
        int containsFunction(const string& name, vector<string> params_types = {});
        bool containsName(const string& name);
};

class TableStack {
    TableStack() = default;
    public:
        stack<int> offsets;
        stack<SymbolTable*> tables;
        string funcType;

        static TableStack& Instance() {
            static TableStack ins;
            return ins;
        }

        /* TableStack() : funcType("") {
            SymbolTable* base = new SymbolTable();
            tables.push(base);
            offsets.push(0);

            base->insertSymbol("print", {"void", "string"}, 0, false, true);
            base->insertSymbol("printi", {"void", "int"}, 0, false, true);
        }; */
        void Init();
        void openGlobalScope();
        //~TableStack() = default;
        bool isInCurrentScope(const string& name);
        bool containsName(const string& name);
        int containsFunction(const string& name, vector<string> params_types = {});
        int containsVariable(const string& name, string type);
        string getType(const string& name);
        bool containsMain();
        bool isCurrentScopeWhile();
        // is while loop in the global scope ?
        void newScope(bool isWhileScope = false);
        void closeScope();
        void MakeTable(SymbolTable* parent, bool isWhile);
        int Insert(string name, string type, int offset, vector<string> params_types = {}, bool isOverride = false, bool isFunc = false);
        bool IsEmpty();
};


#endif