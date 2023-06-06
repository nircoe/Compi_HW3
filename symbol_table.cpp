#include "symbol_table.hpp"

bool SymbolTable::exists(string symb_name, bool* is_func) {
    for (int i = 0; i < this->symbols.size(); i++) {
        if (this->symbols[i]->symbol_name == symb_name) {
            if (is_func)
                *is_func = this->symbols[i]->function;
            return true;
        }
    }
    return false;
}


void TablesStack::Init() {
    this->openGlobalScope();

    //for none integer print
    SymbolTable* curr_table = this->table_stack.top();
    Symbol* print_func = new Symbol("print", NA, TYPE_VOID, true);
    print_func->args = {"STRING"};
    curr_table->symbols.push_back(print_func);

    //for integers print
    Symbol* printi_func = new Symbol("printi", NA, TYPE_VOID, true);
    printi_func->args = {"INT"};
    curr_table->symbols.push_back(printi_func);
}

bool TablesStack::symbDeclared(const string& name, bool is_func) {
    SymbolTable* table_iter = this->table_stack.top();
    bool check_func = false;
    while (table_iter != nullptr) {
        if (table_iter->exists(name, &check_func)) {
            return (is_func) ? check_func : true;
        }
        table_iter = table_iter->parent;
    }
    return false;
}


void TablesStack::declVar(const string& var_name, TypesEnum var_type) {
    Symbol* new_var = new Symbol(var_name, this->offset_stack.top(), var_type);
    SymbolTable* curr_table = this->table_stack.top();
    curr_table->symbols.push_back(new_var);
    int top = this->offset_stack.top() + 1;
    this->offset_stack.pop();
    this->offset_stack.push(top);
}


int TablesStack::declFunc(const string& name, TypesEnum type, FormalsNode* formals, bool isOverride, int yylineno) {
    Symbol* new_func = new Symbol(name, NA, type, true, isOverride);

    if (isOverride) {
        if (name.compare("main") == 0) {
            if(this->mainExists())  errorFuncNoOverride(yylineno, name);
            else                    errorMainOverride(yylineno);
            return -1;
        }
    }

    SymbolTable* table_iter = this->table_stack.top();
    while (table_iter != nullptr) {
        for (int i=0; i < table_iter->symbols.size(); ++i){
            if (table_iter->symbols[i]->symbol_name == name && table_iter->symbols[i]->function) {
                if(!(table_iter->symbols[i]->isOverride) && !isOverride) {
                    errorDef(yylineno, name);
                    return -1;
                }
                else if(!(table_iter->symbols[i]->isOverride) && isOverride) {
                    errorFuncNoOverride(yylineno, name);
                    return -1;
                }
                else if(table_iter->symbols[i]->isOverride && !isOverride) {
                    errorOverrideWithoutDeclaration(yylineno, name);
                    return -1;
                }
                else {
                    if(table_iter->symbols[i]->args.size() != formals->declarations.size()) continue;
                    int diff = 0;
                    for(int j = 0; j < formals->declarations.size(); j++) {
                        if(StringToType(table_iter->symbols[i]->args[j]) != formals->declarations[j]->type) diff++;
                    }
                    if(diff == 0) {
                        errorDef(yylineno, name);
                        return -1;
                    }
                }
            }
        }
        table_iter = table_iter->parent;
    }

    SymbolTable* curr_table = this->table_stack.top();
    this->curr_func_type = type;
    vector<string> func_params = vector<string>();
    for (int i = 0; i < formals->declarations.size(); ++i)
        func_params.push_back(TypeToString(formals->declarations[i]->type));

    new_func->args = func_params;
    curr_table->symbols.push_back(new_func);
    this->openScope();
    curr_table = this->table_stack.top();
    int offset = -1;
    for (int i = 0; i < formals->declarations.size(); ++i) {
        Symbol* curr_param = new Symbol(formals->declarations[i]->name, offset--, formals->declarations[i]->type);
        if(this->symbDeclared(formals->declarations[i]->name)){
            errorDef(yylineno,formals->declarations[i]->name);
            return -1;
        }
        curr_table->symbols.push_back(curr_param);
    }
    return 0;
}


TypesEnum TablesStack::getIDType(const string &id_name) {
    SymbolTable* table_iter = this->table_stack.top();
    while (table_iter) {
        for (int i = 0; i < table_iter->symbols.size(); i++) {
            if (table_iter->symbols[i]->symbol_name == id_name)
                return table_iter->symbols[i]->type;
        }
        table_iter = table_iter->parent;
    }
    return NULL_TYPE;
}



TypesEnum TablesStack::getFuncType(const string &func_name, vector<ExpNode*>& exprs) {
    SymbolTable* table_iter = this->table_stack.top();
    while (table_iter) {
        for (int i = 0; i < table_iter->symbols.size(); ++i) {
            if ((exprs.size() == table_iter->symbols[i]->args.size()) &&
                (table_iter->symbols[i]->symbol_name == func_name)) {
                bool same_params = true;
                for (int j = 0; j < exprs.size(); j++) {
                    if (exprs[j]->type != StringToType(table_iter->symbols[i]->args[j]))
                        same_params = false;
                }
                if (same_params)
                    return table_iter->symbols[i]->type;
            }
        }
        table_iter = table_iter->parent;
    }
    return this->getIDType(func_name);
}


bool checkFunctionParams(Symbol* symbol, const string& symbol_name, vector<ExpNode*> exprs) {
    if(symbol == nullptr || (symbol->args.size() != exprs.size()))
        return false;

    for (int i = 0; i < symbol->args.size(); i++) {
        if(!AssignLegality(StringToType(symbol->args[i]), exprs[i]->type))
            return false;
    }
    return true;
}


int TablesStack::checkFuncParams(const string& func_name, vector<ExpNode*> exprs, int yylineno) {
    SymbolTable* table_iter = this->table_stack.top();
    int cnt_funcs = 0;
    while (table_iter) {
        for (int i = 0; i < table_iter->symbols.size(); ++i) {
            if (table_iter->symbols[i]->symbol_name.compare(func_name) == 0) {
                if (checkFunctionParams(table_iter->symbols[i], func_name, exprs))
                    cnt_funcs++;
            }
        }
        table_iter = table_iter->parent;
    }

    if(cnt_funcs != 1) {
        (cnt_funcs > 1) ? errorAmbiguousCall(yylineno, func_name) : errorPrototypeMismatch(yylineno, func_name);
        return -1;
    }
    return 0;
}


int TablesStack::checkFuncParams(const string& func_name, int yylineno) {
    return this->checkFuncParams(func_name, {}, yylineno);
}



bool TablesStack::mainExists() {
    SymbolTable* table_iter = this->table_stack.top();
    Symbol* symbol = nullptr;
    while (table_iter) {
        for (int i = 0; i < table_iter->symbols.size(); i++) {
            if (table_iter->symbols[i]->symbol_name == "main") {
                symbol = table_iter->symbols[i];
                break;
            }
        }
        table_iter = table_iter->parent;
    }
    return symbol && symbol->type == TYPE_VOID && symbol->function && !(symbol->isOverride) && symbol->args.size() == 0;
}



bool TablesStack::isInCurrScope(const string& name) {
    return this->table_stack.top()->exists(name);
}


bool TablesStack::isCurrScopeInWhile() {
    return this->table_stack.top()->inWhile;
}


void TablesStack::openGlobalScope() {
    this->offset_stack.push(NA);
    SymbolTable *new_table = new SymbolTable();
    this->table_stack.push(new_table);
}


void TablesStack::openScope(bool isWhileLoop) {
    int offset = 0;
    if (!(this->offset_stack.empty()))
        offset = this->offset_stack.top();

    this->offset_stack.push(offset);

    SymbolTable *new_table = new SymbolTable(this->table_stack.top());
    if (isWhileLoop)
        new_table->inWhile = true;

    this->table_stack.push(new_table);

}


void TablesStack::closeScope() {
    endScope();

    SymbolTable* to_del = this->table_stack.top();
    for (int i = 0; i< to_del->symbols.size(); i++){
        Symbol* curr_entry = to_del->symbols[i];
        if (curr_entry->function){
            string type = TypeToString(curr_entry->type);
            string res = makeFunctionType(type, curr_entry->args);
            printID(curr_entry->symbol_name, 0, res);
        }
        else
            printID(curr_entry->symbol_name,curr_entry->offset, TypeToString(curr_entry->type));
    }
    this->offset_stack.pop();
    this->table_stack.pop();
}