#ifndef TYPES_HPP
#define TYPES_HPP

#include <vector>
#include <iostream>
#include <string>
#define YYSTYPE Node*
using std::vector;
using std::string;

class Node {
    public:
        virtual ~Node() {};
};

class TypeNode : public Node {
    string type;

    public:
        TypeNode(string _type) : type(_type) {};
        string GetType() { return type; }
};

class IdNode : public Node {
    const string name;
    
    public:
        IdNode(const string _name) : name(_name) {};
        string GetName() { return name; }
};

class OverrideNode : public Node {
    bool isOverride;

    public:
        OverrideNode(bool _isOverride = false) : isOverride(_isOverride) {};
        bool CheckIsOverride() { return isOverride; }
};

class NumNode : public Node {
    const string num_as_string;

    public:
        NumNode(const string _num_as_string) : num_as_string(_num_as_string) {};
        string GetNumAsString() { return num_as_string; }
};

class ExpNode : public Node {
    string type;

    public:
        ExpNode(string _type) : type(_type) {};
        string GetType() { return type; }
};

class ExpListNode : public Node {
    vector<ExpNode*> exps;

    public:
        ExpListNode(vector<ExpNode*> _exps) : exps(_exps) {};
        ~ExpListNode() {};
        vector<ExpNode*>& GetExpsList() { return exps; }
};

class FormalDeclNode : public Node {
    string type;
    string name;

    public:
        FormalDeclNode(string _type, string _name) : type(_type) , name(_name) {};
        string GetType() { return type; }
        string GetName() { return name; }
};

class FormalsListNode : public Node {
    vector<FormalDeclNode*> decls;

    public:
        FormalsListNode(vector<FormalDeclNode*> _decls) : decls(_decls) {};
        ~FormalsListNode() {};
        vector<FormalDeclNode*>& GetDecls() { return decls; }
};

class FormalsNode : public Node {
    FormalsListNode* list;

    public:
        FormalsNode(FormalsListNode* _list = nullptr) : list(_list) {};
        ~FormalsNode() {};
        vector<FormalDeclNode*>& GetList() { return list->GetDecls(); }
};

class FuncDeclNode : public Node {
    string type;
    string name;
    vector<FormalDeclNode*> decls;

    public:
        FuncDeclNode(string _type, string _name, vector<FormalDeclNode*> _decls) : type(_type) , name(_name) , decls(_decls) {};
        ~FuncDeclNode() {};
        string GetType() { return type; }
        string GetName() { return name; }
        vector<FormalDeclNode*>& GetDecls() { return decls; }
};

class RetTypeNode : public Node {
    string type;

    public:
        RetTypeNode(string _type) : type(_type) {};
        string GetType() { return type; }
};

class CallNode : public Node {
    string type;
    string name;
    
    public:
        CallNode(string _type, string _name) : type(_type) , name(_name) {};
        string GetType() { return type; }
        string GetName() { return name; }
};

bool isLegalAssign(string left, string right);
bool IsLegalConvertion(string from_type, string to_type);
string GetSumType(string left_type, string right_type);

#endif