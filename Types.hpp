#ifndef COMPI_TYPES_DECLARATION_H
#define COMPI_TYPES_DECLARATION_H
#include <vector>
#include <iostream>
#include <string>
#define  YYSTYPE Node*
using std::vector;
using std::string;

enum TypesEnum {
    VOID,
    BYTE,
    BOOL,
    INT,
    STRING,
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
class type_t : public Node {
public:
    TypesEnum type;
    type_t(TypesEnum type) : type(type) {};
};

/**
 * override token type
 */
class override_t : public Node {
public:
    bool isOverride = false;
    override_t(bool isOverride = false) : isOverride(isOverride) {};
};

/**
 * id token type
 */
class ID_t : public Node {
public:
    TypesEnum type = NULL_TYPE;
    const string ID_name;
    ID_t(const string name) : ID_name(ID_name){};
};

/**
 * num token type
 */
class num_t : public Node {
public:
    TypesEnum type = INT;
    const string num_val;
    num_t(const string num_str) : num_val(num_val){};
};

/**
 * return type of func
 */
class retType_t : public Node {
public:
    TypesEnum type;
    retType_t(TypesEnum type) : type(type) {};
};

/**
 * expression token
 */
class expr_t : public Node {
public:
    TypesEnum type;
    expr_t(TypesEnum type) : type(type){}
};

/**
 * expression list token
 */
class exprList_t : public Node {
public:
    std::vector<expr_t*> exprs;
    exprList_t(const std::vector<expr_t*>& exprs) : exprs(exprs) {};
};

/**
 * formal declarations token
 */
class formalDeclarations_t : public Node {
public:
    TypesEnum type;
    const string name;
    formalDeclarations_t(TypesEnum type, const string& name) : type(type), name(name) {};
};

/**
 * function declarations token
 */
class funcDeclarations_t : public Node{
public:
    TypesEnum type;
    string func_name;
    vector<formalDeclarations_t*> declarations;
    funcDeclarations_t(TypesEnum type , const vector<formalDeclarations_t*>& declarations, string func_name) :
    type(type), declarations(declarations), func_name(func_name){};
};

/**
 * formal token type
 */
class formals_t : public Node {
public:
    vector<formalDeclarations_t*> declarations;
    formals_t(const vector<formalDeclarations_t*>& declarations) : declarations(declarations) {};
    formals_t(){};
};

/**
 * call token
 */
class call_t : public Node {
public:
    TypesEnum type;
    const string call_name;
    call_t(TypesEnum type, const string name) : type(type), call_name(call_name) {};
};

/**
 * formal list token type
 */
class formalsList_t : public Node {
public:
    vector<formalDeclarations_t*> declarations;
    formalsList_t(const vector<formalDeclarations_t*>& declarations) : declarations(declarations) {};
};


bool ConversionLegality(TypesEnum from, TypesEnum to);
bool AssignLegality(TypesEnum leftType, TypesEnum rightType);
TypesEnum SumType(TypesEnum left, TypesEnum right);
TypesEnum StringToType(const string& s);
string TypeToString(TypesEnum type);



#endif //COMPI_TYPES_DECLARATION_H
