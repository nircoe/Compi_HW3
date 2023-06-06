#ifndef COMPI_TYPES_H
#define COMPI_TYPES_H

#include <vector>
#include <iostream>
#include <string>
#define YYSTYPE Node*

using std::vector;
using std::string;

enum TypesEnum {
    TYPE_VOID,
    TYPE_BYTE,
    TYPE_BOOL,
    TYPE_INT,
    TYPE_STRING,
    NULL_TYPE
};

/**
 * everyone inherits it
 */
class Node {
public:
    virtual ~Node() {};
};

/**
 * type of token
 */
class TypeNode : public Node {
public:
    TypesEnum type;
    TypeNode(TypesEnum type) : type(type) {};
};

/**
 * override token type
 */
class OverrideNode : public Node {
public:
    bool isOverride;
    OverrideNode(bool isOverride = false) : isOverride(isOverride) {};
};

/**
 * id token type
 */
class IdNode : public Node {
public:
    const string name;
    IdNode(const string name) : name(name){};
};

/**
 * num token type
 */
class NumNode : public Node {
public:
    string num_val;
    NumNode(string num_str) : num_val(num_str){};
};

/**
 * return type of func
 */
class RetTypeNode : public Node {
public:
    TypesEnum type;
    RetTypeNode(TypesEnum type) : type(type) {};
};

/**
 * expression token
 */
class ExpNode : public Node {
public:
    TypesEnum type;
    ExpNode(TypesEnum type) : type(type) {};
};

/**
 * expression list token
 */
class ExpListNode : public Node {
public:
    vector<ExpNode*> exprs;
    ExpListNode(const vector<ExpNode*>& exprs) : exprs(exprs) {};
    ~ExpListNode() { 
        for(int i = 0; i < exprs.size(); i++) {
            if(exprs[i] != nullptr) 
                delete exprs[i]; 
        }
    };
};

/**
 * formal declarations token
 */
class FormalDeclNode : public Node {
public:
    TypesEnum type;
    const string name;
    FormalDeclNode(TypesEnum type, const string& name) : type(type), name(name) {};
};

/**
 * function declarations token
 */
class FuncDeclNode : public Node{
public:
    TypesEnum type;
    string func_name;
    vector<FormalDeclNode*> declarations;
    FuncDeclNode(TypesEnum type , const vector<FormalDeclNode*>& declarations, string func_name) :
                    type(type), declarations(declarations), func_name(func_name){};
    ~FuncDeclNode() {
        for(int i = 0; i < declarations.size(); i++) {
            if(declarations[i] != nullptr) 
                delete declarations[i]; 
        }
    };
};

/**
 * formal token type
 */
class FormalsNode : public Node {
public:
    vector<FormalDeclNode*> declarations;
    FormalsNode(const vector<FormalDeclNode*>& declarations) : declarations(declarations) {};
    FormalsNode() {};
    ~FormalsNode() {
        for(int i = 0; i < declarations.size(); i++) {
            if(declarations[i] != nullptr) 
                delete declarations[i]; 
        }
    };
};

/**
 * call token
 */
class CallNode : public Node {
public:
    TypesEnum type;
    const string call_name;
    CallNode(TypesEnum type, const string name) : type(type), call_name(call_name) {};
};

/**
 * formal list token type
 */
class FormalsListNode : public Node {
public:
    vector<FormalDeclNode*> declarations;
    FormalsListNode(const vector<FormalDeclNode*>& declarations) : declarations(declarations) {};
    ~FormalsListNode() {};
};


bool ConversionLegality(TypesEnum from, TypesEnum to);
bool AssignLegality(TypesEnum leftType, TypesEnum rightType);
TypesEnum SumType(TypesEnum left, TypesEnum right);
TypesEnum StringToType(const string& s);
string TypeToString(TypesEnum type);



#endif //COMPI_TYPES_DECLARATION_H
