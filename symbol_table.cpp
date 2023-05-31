#include "symbol_table.hpp"

int FunctionValue::insertFunc(vector<string> type) { 
    int types_size = types.size(), type_size = type.size();
    if(!isOverride && types_size >= 1) return -1; // not supposed to happen
    for(int i = 0; i < types_size; i++) {
        if(types[i].size() != type_size) continue;
        for(int j = 0; j < type_size; j++) {
            if(types[i][j] != type[j]) break;
            if(j == type_size - 1) return -1; // we found that this type already exist, errorDef
        }
    }
    types.push_back(type);
    return 0; // success
}

int FunctionValue::containsType(vector<string> type) {
    int types_size = types.size(), type_size = type.size(), cnt = 0;
    for(int i = 0; i < types_size; i++) {
        if(types[i].size() != type_size) continue;
        for(int j = 0; j < type_size; j++) {
            if(types[i][j] != type[j] && !(types[i][j] == "int" && type[j] == "byte")) break;
            if(j == type_size - 1) cnt++; // we found that this type already exist, success
        }
    }
    if(cnt == 0) return -1; // errorPrototypeMismatch
    else if(cnt == 1) return 0; // success
    else return -6; // errorAmbiguousCall
}

int TableValue::insertValue(vector<string> type, int offset) {
    if(this->isFunc) {
        return this->val->functions->insertFunc(type); // return success or errorDef
    }
    else {
        val->variable->setTypeOffset(type[0], offset);
        return 0; // success
    }
}

int SymbolTable::insertSymbol(const string& name, vector<string> type, int offset, bool isOverride, bool isFunc) {
    if(table.contains(name)) {
        if(!isFunc) {
            return -1; // errorDef
        }
        if(isFunc && isOverride && table[name]->val->functions->isOverride()) {
            return table[name]->insertValue(type, offset); // return success or errorDef
        }
        else if(!(table[name]->val->functions->isOverride)) {
            return -2; // errorFuncNoOverride
        }
        else {
            return -3; // errorOverrideWithoutDeclaration
        }
    }
    else {
        SymbolTable* current = parent;
        while(current) {
            if(current->contains(name)) {
                if(!isFunc) {
                    return -1; // errorDef
                }
                if(isFunc && isOverride && current[name]->val->functions->isOverride) {
                    break;
                }
                if(!(current[name]->val->functions->isOverride)) {
                    return -2;
                }
                return -3;
            }

            current = current->parent;
        }
        table[name] = new TableValue(isOverride, isFunc);
        return table[name]->insertValue(type, offset); // return success
    }
    return 0; // not gonna get here
}

int SymbolTable::containsSymbol(const string& name, const vector<const string&>& type, const bool isFunc) {
    if(table.contains(name)) {
        if(table[name]->isFunc) {
            if(!isFunc) return -5; // errorUndef
            return table[name]->val->functions->containsType(type); 
            // success 0 or errorPrototypeMismatch -1 or errorAmbiguousCall -6
        }
        else {
            if(isFunc) return -3; // errorUndefFunc
            if(table[name]->val->variable->getType() == type[0]) return 0; // contains
            else return -2; // errorMismatch
        }
    }
    else {
        isFunc ? return -3 : return -4; // -3 errorUndefFunc, -4 errorUndef
    }
    return 0; // not gonna get here
}

bool SymbolTable::containsName(const string &name)
{
    return this->table.contains(name);
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
    return string();
}

bool TableStack::containsMain() {
    return false;
}

bool TableStack::isCurrentScopeWhile() {
    if(this->tables.empty()) return false;
    return this->tables.top()->isWhile;
}

void TableStack::openGlobalScope() {
    SymbolTable* table = new SymbolTable();
    this->tables.push(table);
    this->offsets.push(0);

    table->insertSymbol("print", {"void", "string"}, 0, false, true);
    table->insertSymbol("printi", {"void", "int"}, 0, false, true);
}

void TableStack::newScope(bool isWhileScope) {
    int offset = this->offsets.empty() ? 0 : this->offsets.top();
    this->offsets.push(offset);
    SymbolTable* parent = this->tables.empty() ? nullptr : this->tables.top();
    SymbolTable* table = new SymbolTable(parent, isWhileScope);
    this->tables.push(table);
}

void TableStack::closeScope() {
    if(this->table.empty()) return;
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
            string retType = it.second->val->functions
        }
        else {
            output::printID(it.first, it.second->val->variable->offset, it.second->val->variable->type);
        }
    }
    this->offsets.pop();
    this->tables.pop();
}

void TableStack::MakeTable(SymbolTable* parent, bool isWhile) { 
    SymbolTable* table = new SymbolTable(parent, isWhile); 
    tables.push(table);
    offsets->newScope();
}

int TableStack::Insert(string name, vector<string> type, int offset, bool isOverride, bool isFunc) {
    SymbolTable* topTable = tables.top();
    int res = topTable->insertSymbol(name, type, offset, isOverride, isFunc);
    if(res == 0) {
        if(!isFunc) {
            offsets->increaseOffset();
        }
    }
}

#endif