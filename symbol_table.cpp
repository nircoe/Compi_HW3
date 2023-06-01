#include "symbol_table.hpp"

int FunctionValue::insertFunc(vector<string> type) { 
    int types_size = types.size(), type_size = type.size();
    if(!isOverride && types_size >= 1) return -1; // not supposed to happen
    for(int i = 0; i < types_size; i++) {
        if(types[i].size() != type_size) continue;
        for(int j = 0; j < type_size; j++) {
            if(types[i][j] != type[j]) break;
            if(j == type_size - 1) return ERROR_DEF; // we found that this type already exist, errorDef
        }
    }
    types.push_back(type);
    return SUCCESS; // success
}

int FunctionValue::containsType(vector<string> type) {
    int types_size = types.size(), type_size = type.size(), cnt = 0;
    for(int i = 0; i < types_size; i++) {
        if(types[i].size() - 1 != type_size) continue;
        if(type_size == 0) cnt++;
        else {
            for(int j = 0; j < type_size; j++) {
                if(types[i][j + 1] != type[j] && !(types[i][j + 1] == "int" && type[j] == "byte")) break;
                if(j == type_size - 1) cnt++; // we found that this type already exist, success
            }
        }
    }
    if(cnt == 0) return ERROR_PROTOTYPE_MISMATCH; // errorPrototypeMismatch
    else if(cnt == 1) return SUCCESS; // success
    else return ERROR_AMBIGUOUS_CALL; // errorAmbiguousCall
}

int TableValue::insertValue(vector<string> type, int offset) {
    if(this->isFunc) {
        return this->val->functions->insertFunc(type); // return success or errorDef
    }
    else {
        val->variable->setTypeOffset(type[0], offset);
        return SUCCESS; // success
    }
}

int SymbolTable::insertSymbol(const string& name, vector<string> type, int offset, bool isOverride, bool isFunc) {
    if(name == "main" && isOverride) return ERROR_MAIN_OVERRIDE; // errorMainOverride

    if(this->table.find(name) != this->table.end()) {
        if(!isFunc) {
            return ERROR_DEF; // errorDef
        }
        if(isFunc && isOverride && table[name]->val->functions->isOverride) {
            return table[name]->insertValue(type, offset); // return success or errorDef
        }
        else if(!(table[name]->val->functions->isOverride)) {
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
                if(isFunc && isOverride && current->table[name]->val->functions->isOverride) {
                    break;
                }
                if(!(current->table[name]->val->functions->isOverride)) {
                    return ERROR_NO_OVERRIDE;
                }
                return ERROR_OVERRIDE_NO_DECL;
            }

            current = current->parent;
        }
        table[name] = new TableValue(isOverride, isFunc);
        return table[name]->insertValue(type, offset); // return success
    }
    return SUCCESS; // not gonna get here
}

int SymbolTable::containsSymbol(string name, vector<string> type, bool isFunc) {
    if(this->table.find(name) != this->table.end()) {
        if(table[name]->isFunc) {
            if(!isFunc) return ERROR_UNDEF; // errorUndef
            return table[name]->val->functions->containsType(type); 
            // success 0 or errorPrototypeMismatch -1 or errorAmbiguousCall -6
        }
        else {
            if(isFunc) return ERROR_UNDEF_FUNC; // errorUndefFunc
            if(table[name]->val->variable->getType() == type[0]) return SUCCESS; // contains
            else return ERROR_MISMATCH; // errorMismatch
        }
    }
    else {
        return (isFunc) ? ERROR_UNDEF_FUNC : ERROR_UNDEF; // -3 errorUndefFunc, -4 errorUndef
    }
    return SUCCESS; // not gonna get here
}

bool SymbolTable::containsName(const string &name)
{
    return this->table.find(name) != this->table.end();
}

bool TableStack::isInCurrentScope(const string &name) {
    if(this->tables.empty()) return false;
    return this->tables.top()->containsName(name);
}

int TableStack::containsSymbol(const string &name, vector<string> type, bool isFunc)
{
    return this->tables.top()->containsSymbol(name, type, isFunc);
}

string TableStack::getType(const string &name) {
    SymbolTable* current = this->tables.top();
    while(current) {
        if(current->table.find(name) != current->table.end()) {
            TableValue* tv = current->table[name];
            if(tv->isFunc) return tv->val->functions->types[0][0];
            else return tv->val->variable->getType();
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
    if(table->containsSymbol("main", {"void"}, true) == 0) return true;
    return false;
}

bool TableStack::isCurrentScopeWhile() {
    if(this->tables.empty()) return false;
    return this->tables.top()->isWhile;
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
        if(it.second->isFunc) {
            int size = it.second->val->functions->types.size();
            for(int i = 0; i < size; i++) {
                vector<string> current = it.second->val->functions->types[i];
                vector<string> params(std::next(current.begin(), 1), current.end());
                output::printID(it.first, 0, 
                                output::makeFunctionType(current[0], params));
            }
        }
        else {
            output::printID(it.first, it.second->val->variable->getOffset(), it.second->val->variable->getType());
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

int TableStack::Insert(string name, vector<string> type, int offset, bool isOverride, bool isFunc) {
    SymbolTable* topTable = tables.top();
    int res = topTable->insertSymbol(name, type, offset, isOverride, isFunc);
    if(res == 0) {
        if(!isFunc) {
            offsets.top() += 1;
        }
    }
    return res;
}
