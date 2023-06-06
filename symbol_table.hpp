
#ifndef COMPI_SYMBOL_TABLE_H
#define COMPI_SYMBOL_TABLE_H

#include "types.hpp"
#include "hw3_output.hpp"
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#define NA 0

extern int yylineno;
using namespace output;
using std::vector;
using std::string;

class Symbol {
    public:
        const string symbol_name;
        TypesEnum type;
        int offset;
        bool isOverride;
        bool function;
        vector<string> args;
        Symbol(const string &symbol_name, int offset, TypesEnum type, bool function = false, bool isOverride = false) : 
                symbol_name(symbol_name), offset(offset), type(type), function(function), isOverride(isOverride) {};
        ~Symbol() = default;
};

class SymbolTable {
    public:
        SymbolTable* parent;
        vector<Symbol*> symbols;
        bool inWhile;
        SymbolTable(SymbolTable* parent = nullptr) : parent(parent) {
            this->inWhile = (parent) ? parent->inWhile : false;
        };
        ~SymbolTable() {
            for(int i = 0; i < symbols.size(); i++) {
                delete symbols[i];
            }
        };
        bool exists(string symb_name, bool* is_func = nullptr);
};

class TablesStack {
    TablesStack() = default;
public:
    stack<SymbolTable*> table_stack;
    stack<int> offset_stack;
    TypesEnum curr_func_type = NULL_TYPE;
    static TablesStack& getTablesStack() {
        static TablesStack instance;
        return instance;
    }
    // initiated instance
    void Init(); 
    // checks if symbol was declared
    bool symbDeclared(const string& name, bool is_func = false);
    // declares new variable
    void declVar(const string& name, TypesEnum type);
    // declares new function
    int declFunc(const string& name, TypesEnum type, FormalsNode* formals, bool isOverride, int yylineno);
    // gets the id type by its name
    TypesEnum getIDType(const string& name);
    // gets the func-id type by its name and function parameters
    TypesEnum getFuncType(const std::string &name, vector<ExpNode*>& exprs);
    // checks if the parameters entered to function are valid
    int checkFuncParams(const std::string& func_name, vector<ExpNode*> exprs, int yylineno);
    // checks if the parameters entered to function are valid
    int checkFuncParams(const std::string& name, int yylineno);
    // checks if a befitting main function exists
    bool mainExists();
    // check if ID exists in current scope by name
    bool isInCurrScope(const string& name);
    // checks if current scope is within a while statement
    bool isCurrScopeInWhile();
    // opens a global scope
    void openGlobalScope();
    // opens a new scope
    void openScope(bool inWhile = false);
    // closes scope
    void closeScope();
};


#endif //COMPI_SYMBOL_TABLE_H
