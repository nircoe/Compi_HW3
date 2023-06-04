#include "symbol_table.hpp"

int TableValue::insertValue(string _type, int _offset, vector<string> _params_types) {
    if(this->isFunc) { // function
        int functions_types_size = this->functions_params_types.size(), param_type_size = _params_types.size();
        if(functions_types_size > 0 && this->type != _type) return ERROR_DEF;
        if(!this->isOverride && functions_types_size > 1) return ERROR_NO_OVERRIDE; // not supposed to happen
        for(int i = 0; i < functions_types_size; i++) {
            if(this->functions_params_types[i].size() != param_type_size) continue;
            for(int j = 0; j < param_type_size; j++) {
                if(this->functions_params_types[i][j] != _params_types[j]) break;
                if(j == param_type_size - 1) return ERROR_DEF; // we found that this type already exist, errorDef
            }
        }
        if(functions_types_size == 0) {
            this->offset = 0;
            this->type = _type;
        }
        this->functions_params_types.push_back(_params_types);
        return SUCCESS;
    }
    this->type = _type;
    this->offset = _offset;
    return SUCCESS;
}

int TableValue::containsFunc(vector<string> _params_types)
{
    int functions_types_size = this->functions_params_types.size(), params_size = _params_types.size(), cnt = 0;
    for(int i = 0; i < functions_types_size; i++) {
        if(this->functions_params_types[i].size() != params_size) continue;
        if(params_size == 0) cnt++;
        else {
            for(int j = 0; j < params_size; j++) {
                if(this->functions_params_types[i][j] != _params_types[j] && 
                    !(this->functions_params_types[i][j] == "int" && _params_types[j] == "byte")) break;
                if(j == params_size - 1) cnt++; // we found that this type already exist, success
            }
        }
    }
    if(cnt == 0) return ERROR_PROTOTYPE_MISMATCH; // errorPrototypeMismatch
    else if(cnt == 1) return SUCCESS; // success
    else return ERROR_AMBIGUOUS_CALL; // errorAmbiguousCall
}

int SymbolTable::insertSymbol(const string& name, string type, vector<string> params_types, int offset, bool isOverride, bool isFunc) {
    if(name == "main" && isOverride) return ERROR_MAIN_OVERRIDE; // errorMainOverride

    if(this->table.find(name) != this->table.end()) {
        if(!isFunc) {
            return ERROR_DEF; // errorDef
        }
        if(isFunc && isOverride && table[name]->isOverride) {
            return table[name]->insertValue(type, 0, params_types); // return success or errorDef
        }
        else if(!(table[name]->isOverride)) {
            return ERROR_NO_OVERRIDE; // errorFuncNoOverride
        }
        else {
            return ERROR_OVERRIDE_NO_DECL; // errorOverrideWithoutDeclaration
        }
    }
    else {
        SymbolTable* current = parent;
        while(current) {
            if(current->table.find(name) != current->table.end()) {
                if(!isFunc) {
                    return ERROR_DEF; // errorDef
                }
                if(isFunc && isOverride && current->table[name]->isOverride) {
                    break;
                }
                if(!(current->table[name]->isOverride)) {
                    return ERROR_NO_OVERRIDE;
                }
                return ERROR_OVERRIDE_NO_DECL;
            }

            current = current->parent;
        }
        table[name] = new TableValue(isOverride, isFunc);
        return table[name]->insertValue(type, offset, params_types); // return success
    }
    return SUCCESS; // not gonna get here
}

int SymbolTable::containsVariable(string name, string type) {
    if(this->table.find(name) != this->table.end()) {
        if(this->table[name]->isFunc) return ERROR_UNDEF;
        if(this->table[name]->type == type) return SUCCESS;
        return ERROR_MISMATCH;
    }
    return ERROR_UNDEF;
}

int SymbolTable::containsFunction(const string &name, vector<string> params_types)
{
    if(this->table.find(name) != this->table.end() && this->table[name]->isFunc) {
        int res = this->table[name]->containsFunc(params_types);
        if(res == SUCCESS || ERROR_AMBIGUOUS_CALL) return res;
        SymbolTable* current = this;
        while(current) {
            if(current->table.find(name) != current->table.end() && current->table[name]->isFunc) {
                int res = current->table[name]->containsFunc(params_types);
                if(res == SUCCESS || ERROR_AMBIGUOUS_CALL) return res;
            }
            current = current->parent;
        }
        return ERROR_PROTOTYPE_MISMATCH;
    }
    return ERROR_UNDEF_FUNC;
}

bool SymbolTable::containsName(const string &name)
{
    return this->table.find(name) != this->table.end();
}

bool TableStack::isInCurrentScope(const string &name) {
    if(this->tables.empty()) return false;
    return this->tables.top()->containsName(name);
}

bool TableStack::containsName(const string &name)
{
    SymbolTable* current = this->tables.top();
    while(current) {
        if(current->containsName(name)) {
            return true;
        }
        current = current->parent;
    }
    return false;
}

int TableStack::containsFunction(const string &name, vector<string> params_types)
{
    return this->tables.top()->containsFunction(name, params_types);
}

int TableStack::containsVariable(const string &name, string type) {
    return this->tables.top()->containsVariable(name, type);
}

string TableStack::getType(const string &name) {
    SymbolTable* current = this->tables.top();
    while(current) {
        if(current->table.find(name) != current->table.end()) {
            return current->table[name]->type;
        }
        current = current->parent;
    }
    return ""; // don't exist
}

bool TableStack::containsMain() {
    SymbolTable* table = this->tables.top();
    while(table) {
        if(table->parent == nullptr) break;
        else table = table->parent;
    }
    // table is Global scope
    if(table->containsFunction("main") == SUCCESS) return true;
    return false;
}

bool TableStack::isCurrentScopeWhile() {
    if(this->tables.empty()) return false;
    return this->tables.top()->isWhile;
}

void TableStack::Init() {
    this->openGlobalScope();

    if(this->tables.empty()) {
        std::cout << "error init" << std::endl;
    }

    SymbolTable* base = this->tables.top();

    base->insertSymbol("print", "void", {"string"}, 0, false, true);
    base->insertSymbol("printi", "void", {"int"} , 0, false, true);
}

void TableStack::openGlobalScope() {
    this->offsets.push(0);
    SymbolTable* base = new SymbolTable();
    this->tables.push(base);
}

void TableStack::newScope(bool isWhileScope) {
    int offset = this->offsets.empty() ? 0 : this->offsets.top();
    this->offsets.push(offset);
    SymbolTable* parent = this->tables.empty() ? nullptr : this->tables.top();
    if(isWhileScope == false) isWhileScope = parent->isWhile;
    SymbolTable* table = new SymbolTable(parent, isWhileScope);
    this->tables.push(table);
}

void TableStack::closeScope() {
    if(this->tables.empty()) return;
    output::endScope();
    SymbolTable* topScope = this->tables.top();
    for(auto& it : topScope->table) {
        string name = it.first;
        TableValue* val = it.second;
        if(val->isFunc) {
            int size = val->functions_params_types.size();
            for(int i = 0; i < size; i++) {
                vector<string> params = val->functions_params_types[i];
                output::printID(name, 0, output::makeFunctionType(val->type, params));
            }
        }
        else {
            output::printID(name, val->offset, val->type);
        }
    }
    this->offsets.pop();
    this->tables.pop();
}

void TableStack::MakeTable(SymbolTable* parent, bool isWhile) { 
    SymbolTable* table = new SymbolTable(parent, isWhile); 
    tables.push(table);
    offsets.push(offsets.top());
}

int TableStack::Insert(string name, string type, int offset, vector<string> params_types, bool isOverride, bool isFunc)
{
    for(int i = 0; i < params_types.size(); i++) {
        if(params_types[i] != "int" && params_types[i] != "byte" && params_types[i] != "bool") return ERROR_DEF;
    }
    SymbolTable* topTable = tables.top();
    int res = topTable->insertSymbol(name, type, params_types, offset, isOverride, isFunc);
    if(res == 0) {
        if(!isFunc) {
            offsets.top() += 1;
        }
    }
    return res;
}

bool TableStack::IsEmpty() {
    return this->tables.empty() || this->offsets.empty();
}
