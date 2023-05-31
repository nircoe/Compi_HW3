#ifndef AUX_CPP
#define AUX_CPP

#include <iostream>
#include <unordered_map>
#include <stack>
using std::unordered_map;
using std::string;
using std::stack;


class FunctionValue {
    unordered_map<string, int> types; // key type, value offset

    public:
        FunctionValue() {};
        int insertFunc(string type, int offset) { 
            if(types.contains(type)) return -1; // errorDef
            types[type] = offset;
            return 0; // success
        }
        bool containsType(string type) {
            if(types.contains(type)) return true; // success
            return false; // errorUndefFunc
        }
        int getOffset(string type) {
            if(types.contains(type)) return types[type]; // success
            return -1; // errorUndefFunc
        }
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
        UnionValue() function(nullptr) : variable(nullptr) {};
        ~UnionValue() {
            if(functions != nullptr) delete functions;
            if(variable != nullptr) delete variable;
        };
};

class TableValue {
    bool isOverride;
    bool isFunc;
    UnionValue* val;

    public:
        TableValue(bool _isOverride, bool _isFunc) isOverride(_isOverride) : isFunc(_isFunc) {
            val = new UnionValue();
            if(_isOverride) {
                val->functions = new FunctionValue();
            }
            else {
                val->variable = new VariableValue();
            }
        }
        ~TableValue() {
            delete val;
        };
        int insertValue(string type, int offset) {
            if(this->isOverride) {
                return this->val.functions.insertFunc(type, offset); // return success or errorDef
            }
            else {
                val.variable.setTypeOffset(type, offset);
                return 0; // success
            }
        }

};

class SymbolTable {
    unordered_map<string, TableValue*> table;
    SymbolTable* parent;

    public:
        SymbolTable(SymbolTable* _parent) parent(_parent) {};
        ~SymbolTable() { 
            for(auto& it : table) {
                delete it.second;
            }
        };
        int insertSymbol(string name, string type, int offset, bool isOverride, bool isFunc) {
            if(table.contains(name)) {
                if(!isFunc) {
                    return -1; // errorDef
                }
                if(isFunc && isOverride && table[name]->isOverride) {
                    return table[name]->insertValue(type, offset); // return success or errorDef
                }
                else if(!(table[name]->isOverride)) {
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
                        if(isFunc && isOverride && current[name]->isOverride) {
                            break;
                        }
                        if(!(current[name]->isOverride)) {
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
        int containsSymbol(string name, string type, bool isFunc) {
            if(table.contains(name)) {
                if(table[name]->isOverride) {
                    if(!isFunc) return -5; // errorUndef
                    table[name]->val.functions.containsType(type) ? return 0 : return -1; // -1 is errorPrototypeMismatch
                }
                else {
                    // need to add check if val is func and if isFunc is true for errorUndefFunc
                    if(table[name]->val.variable.getType() == type) return 0; // contains
                    else return -2; // errorMismatch
                }
            }
            else {
                isFunc ? return -3 : return -4; // -3 errorUndefFunc, -4 errorUndef
            }
            return 0; // not gonna get here
        }
};

class OffsetStack {
    stack<int> offsets;

    public:
        OffsetStack() { offsets.push(0); };
        void newScope() { offsets.push(offsets.top()); }
        void increaseOffset() {
            offsets.top() += 1;
            /* int temp = offsets.top();
            temp += size;
            offsets.pop();
            offsets.push(temp); */
        }
};

class TableStack {
    stack<SymbolTable*> tables;
    OffsetStack* offsets;

    public:
        TableStack() {
            SymbolTable* base = new SymbolTable(nullptr);
            tables.push(base);
            offsets = new OffsetStack();
        };
        ~TableStack() {
            delete offsets;
        };
        void MakeTable(SymbolTable* parent) { 
            SymbolTable* table = new SymbolTable(parent); 
            tables.push(table);
            offsets->newScope();
        }
        int Insert(string name, string type, int offset, bool isOverride, bool isFunc) {
            SymbolTable* topTable = tables.top();
            int res = topTable->insertSymbol(name, type, offset, isOverride, isFunc);
            if(res == 0) {
                if(!isFunc) {
                    offsets->increaseOffset();
                }
            }
        }
}

#endif