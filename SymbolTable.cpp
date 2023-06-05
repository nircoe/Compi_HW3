#include "SymbolTable.hpp"
#include "Types.hpp"
#include "hw3_output.hpp"
#include <algorithm>
#include <string.h>
#define NONAVAIL 0


bool Table::exists(std::string symb_name, bool* is_func) {
    for (int i = 0; i < this->entries.size(); ++i){
        if (this->entries[i]->entry_name == symb_name) {
            if (is_func)  //removed !=nullptr
                *is_func = this->entries[i]->function;
            return true;
        }
    }
    return false;
}


void SymbolTable::init() {
    this->openGlobalScope();
    if (this->table_stack.empty())
        cout << "initiate tables is empty!" << endl;
    //for none integer print
    Table* curr_table = this->table_stack.top();
    vector<string> print_string;
    print_string.push_back("STRING");
    tableEntry* print_func = new tableEntry("print", NONAVAIL, VOID, true);
    print_func->args = print_string;
    curr_table->entries.push_back(print_func);

    //for integers print
    vector<string> iprint_string;
    iprint_string.push_back("INT");
    tableEntry* printi_func = new tableEntry("printi", NONAVAIL, VOID, true);
    printi_func->args = iprint_string;
    curr_table->entries.push_back(printi_func);
}

bool SymbolTable::symbDeclared(const string& name, bool is_func) {
    if (this->table_stack.empty()) {
        cout << "symbDeclared tables is empty!" << endl;
        cout << name << endl;
    }

    //initiate table iterator to top
    Table* table_iter = this->table_stack.top();
    bool check_func = false;
    while (table_iter != nullptr) {
        if (table_iter->exists(name, &check_func)) {
            if (is_func)
                return check_func;
            return true;
        }
        table_iter = table_iter->table_parent;
    }
    return false;
}


void SymbolTable::declVar(const string& var_name, TypesEnum var_type) {
    if (this->offset_stack.empty()) //todel
        cout << "declVar offset is empty!" << endl;

    if (this->table_stack.empty()) //todel
        cout << "declVar tables is empty!" << endl;

    tableEntry* new_var = new tableEntry(var_name, this->offset_stack.top(), var_type);
    Table* curr_table = this->table_stack.top();
    curr_table->entries.push_back(new_var);
    int top = this->offset_stack.top() + 1;
    this->offset_stack.pop();
    this->offset_stack.push(top);
}


void SymbolTable::declFunc(const string& name, TypesEnum type, formals_t* formals, bool isOverride, int yylineno) {
    tableEntry* new_func = new tableEntry(name, NONAVAIL, type, true, isOverride);
    //todel
    if (this->table_stack.empty()) {
        cout << "isDeclared tables is empty!" << endl;
        cout << name << endl;
    }

    if (isOverride){
        if (name.compare("main") == 0){
            output::errorMainOverride(yylineno);
            exit(1);
        }
    }

    Table* table_iter = this->table_stack.top();
    while (table_iter != nullptr) {
        for (int i=0; i < table_iter->entries.size(); ++i){
            if (table_iter->entries[i]->entry_name == name && table_iter->entries[i]->function) {
                if (!(table_iter->entries[i]->isOverride)){
                    output::errorFuncNoOverride(yylineno,name);
                    exit(1);
                }
                else if (!isOverride){
                    output::errorOverrideWithoutDeclaration(yylineno,name);
                    exit(1);
                }
            }
        }
        table_iter = table_iter->table_parent;
    }

    if (this->table_stack.empty()) //todel
        cout << "declareFunc tables is empty!" << endl;

    Table* curr_table = this->table_stack.top();
    this->curr_func_type = type;
    vector<string> func_params = vector<string>();
    for (int i = 0; i < formals->declarations.size(); ++i)
        func_params.push_back(TypeToString(formals->declarations[i]->type));

    new_func->args = func_params;
    curr_table->entries.push_back(new_func);
    this->openScope(false);
    curr_table = this->table_stack.top();
    int offset = -1;
    for (int i = 0; i < formals->declarations.size(); ++i) {
        tableEntry* curr_param = new tableEntry(formals->declarations[i]->name, offset, formals->declarations[i]->type, false);
        if(this->symbDeclared(formals->declarations[i]->name)){
            output::errorDef(yylineno,formals->declarations[i]->name);
            exit(1);
        }

        curr_table->entries.push_back(curr_param);
        offset -= 1;
    }
}


TypesEnum SymbolTable::getIDType(const std::string &id_name) {
    Table* table_iter = this->table_stack.top();
    while (table_iter) { //remove !=nullptr
        for (int i = 0; i < table_iter->entries.size(); ++i) {
            if (table_iter->entries[i]->entry_name == id_name)
                return table_iter->entries[i]->type;
        }
        table_iter = table_iter->table_parent;
    }
    return NULL_TYPE;
}



TypesEnum SymbolTable::getFuncType(const std::string &fun_name, vector<expr_t*>& exprs) {
    std::vector<expr_t*> expressions_reverse(exprs);
    Table* table_iter = this->table_stack.top();
    reverse((&expressions_reverse)->begin(),(&expressions_reverse)->end());
    while (table_iter) { // removed !=
        for (int i = 0; i < table_iter->entries.size(); ++i) {
            if ((expressions_reverse.size() == table_iter->entries[i]->args.size()) &&
                (table_iter->entries[i]->entry_name == fun_name)) {
                bool exact = true;
                for (int j = 0; j < exprs.size(); ++j) {
                    if (expressions_reverse[j]->type != StringToType(table_iter->entries[i]->args[j]))
                        exact = false;
                }
                if (exact)
                    return table_iter->entries[i]->type;
            }
        }
        table_iter = table_iter->table_parent;
    }
    return this->getIDType(fun_name);
}


bool checkFunctionParams(tableEntry* entry, const std::string& entry_name, vector<expr_t*>& exprs) {
    if((entry->args.size() != exprs.size()) || entry == nullptr)
        return false;

    std::vector<expr_t*> expressions_reverse(exprs);
    reverse((&expressions_reverse)->begin(),(&expressions_reverse)->end());
    for (int i = 0; i < entry->args.size(); ++i) {
        if(!AssignLegality(StringToType(entry->args[i]), expressions_reverse[i]->type))
            return false;
    }
    return true;
}


void SymbolTable::checkFuncParams(const string& func_name, vector<expr_t*>& exprs, int yylineno) {
    Table* table_iter = this->table_stack.top();
    int num_funcs = 0;
    while (table_iter) { //removed  != nullptr
        for (int i = 0; i < table_iter->entries.size(); ++i) {///
            if (strcmp(table_iter->entries[i]->entry_name.c_str(),func_name.c_str()) == 0) {
                if (checkFunctionParams(table_iter->entries[i], func_name, exprs))
                    num_funcs += 1;
            }
        }
        table_iter = table_iter->table_parent;
    }

    if (num_funcs == NONAVAIL) {
        output::errorPrototypeMismatch(yylineno, func_name);
        exit(1);
    }

    if (num_funcs > 1) {
        output::errorAmbiguousCall(yylineno, func_name);
        exit(1);
    }
}


void SymbolTable::checkFuncParams(const std::string& func_name, int yylineno) {
    vector<expr_t*> empty;
    return this->checkFuncParams(func_name, empty, yylineno);
}



bool SymbolTable::mainExists() {
    Table* table_iter = this->table_stack.top();
    tableEntry* entry = nullptr;
    while (table_iter) { // removed !=
        for (int i = 0; i < table_iter->entries.size(); ++i) {
            if (table_iter->entries[i]->entry_name == "main") {
                entry = table_iter->entries[i];
                break;
            }
        }
        table_iter = table_iter->table_parent;
    }
    return entry && entry->type == VOID && entry->function && entry->args.size() == 0; //removed !=
}



bool SymbolTable::isInCurrScope(const string& name) {
    if (this->table_stack.empty()) {
        cout << "isInCurrScope tables is empty!" << endl;
        cout << name << endl;
    }

    Table* table = this->table_stack.top();
    return table->exists(name);
}


bool SymbolTable::isCurrScopeInWhile() {
    if (this->table_stack.empty())
        cout << "isCurrentWhileScope tables is empty!" << endl; //todel

    Table* curr_table = this->table_stack.top();
    return curr_table->inWhile;
}


bool SymbolTable::isGlobalScopeInWhile() {
    if (this->table_stack.empty()) //todel
        cout << "isGlobalScopeInWhile tables is empty!" << endl;

    Table* curr_table = this->table_stack.top();
    while (curr_table) { //removed !=
        if (curr_table->inWhile)
            return true;
        curr_table = curr_table->table_parent;
    }
    return false;
}


void SymbolTable::openGlobalScope() {
    this->offset_stack.push(NONAVAIL);
    Table* parent = nullptr;
    Table *new_table = new Table(parent);
    this->table_stack.push(new_table);
}


void SymbolTable::openScope(bool isWhileLoop) {
    int offset = 0;
    if (!(this->offset_stack.empty()))
        offset = this->offset_stack.top();

    this->offset_stack.push(offset);
    if (this->table_stack.empty())
        cout << "this isn't global scope why the hell the parent is emtpy" << endl;

    Table *new_table = new Table(this->table_stack.top());
    if (isWhileLoop)
        new_table->inWhile = true;

    this->table_stack.push(new_table);

}


void SymbolTable::closeScope() {
    output::endScope();
    if (this->table_stack.empty())
        cout << "closeScope tables is empty!" << endl;

    Table* to_del = this->table_stack.top();
    for (int i = 0; i< to_del->entries.size(); i++){
        tableEntry* curr_entry = to_del->entries[i];
        if (curr_entry->function){
            string type = TypeToString(curr_entry->type);
            string res = output::makeFunctionType(type, curr_entry->args);
            output::printID(curr_entry->entry_name, 0, res);
        }
        else
            output::printID(curr_entry->entry_name,curr_entry->offset, TypeToString(curr_entry->type));
    }
    this->offset_stack.pop();
    this->table_stack.pop();
}