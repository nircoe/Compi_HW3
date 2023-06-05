
#ifndef COMPI_SYMBOL_TABLE_H
#define COMPI_SYMBOL_TABLE_H

#include "Types.hpp"
#include "hw3_output.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
extern int yylineno;
using std::vector;
using std::string;

class tableEntry {
public:
    const string entry_name;
    TypesEnum type;
    int offset;
    bool isOverride;
    bool function;
    vector<string> args;
    tableEntry(const string &entry_name, int offset, TypesEnum type, bool function = false, bool isOverride = false): entry_name(entry_name), offset(offset), type(type), function(
            function), isOverride(isOverride) {};
};

class Table {
public:
    Table* table_parent;
    vector<tableEntry*> entries;
    bool inWhile = false;
    Table(Table* parent) : table_parent(parent){};
    bool exists(string symb_name, bool* is_func = nullptr);
};

class SymbolTable {
    SymbolTable() = default;
public:
    stack<Table*> table_stack;
    stack<int> offset_stack;
    TypesEnum curr_func_type = NULL_TYPE;
    static SymbolTable& getSymbolTable() {
        static SymbolTable instance;
        return instance;
    }
    /**
     * initiated instance
     */
    void init();

    /**
     * checks if symbol was declared
     */
    bool symbDeclared(const string& name, bool is_func = false);

    /**
     * declares new variable
     */
    void declVar(const string& name, TypesEnum type);

    /**
     * declares new function
     */
    void declFunc(const string& name, TypesEnum type, formals_t* formals, bool isOverride, int yylineno);

    /**
     * gets the id type by its name
     */
    TypesEnum getIDType(const string& name);

    /**
     * gets the func-id type by its name and function parameters
     */
    TypesEnum getFuncType(const std::string &name, vector<expr_t*>& exprs);

    /**
     * checks if the parameters entered to function are valid
     */
    void checkFuncParams(const std::string& func_name, vector<expr_t*>& exprs, int yylineno);

    /**
     *
     * checks if the parameters entered to function are valid
     */
    void checkFuncParams(const std::string& name, int yylineno);

    /**
     * checks if a befitting main function exists
     */
    bool mainExists();

    /**
     * check if ID exists in current scope by name
     */
    bool isInCurrScope(const string& name);

    /**
     * checks if current scope is within a while statement
     */
    bool isCurrScopeInWhile();

    /**
     * checks if global scope is a while statement
     */
    bool isGlobalScopeInWhile();

    /**
     * opens a global scope
     */
    void openGlobalScope();

    /**
     * opens a new scope
     */
    void openScope(bool inWhile = false);

    /**
     * closes scope
     */
    void closeScope();

};


#endif //COMPI_SYMBOL_TABLE_H
