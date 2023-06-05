#include "Types.hpp"
using namespace std;

/**
 * checks legality of conversion from one type to another
 * */
bool ConversionLegality(TypesEnum from, TypesEnum to) {
    return ((from == INT || from == BYTE) && (to == INT || to == BYTE)) || from == to;
}

/**
 * checks the legality of an assignment from one type to another
 * */
bool AssignLegality(TypesEnum left, TypesEnum right) {
    return (left == INT && right == BYTE) || left == right;
}

/**
 * checks binary operator result type
 * */
TypesEnum SumType(TypesEnum left, TypesEnum right) {
    if (left == INT && right == INT)
        return INT;
    else if (left == BYTE && right == INT)
        return INT;
    else if (left == INT && right == BYTE)
        return INT;
    else if (left == BYTE && right == BYTE)
        return  BYTE;
    return NULL_TYPE;
}

/**
 * converts string to type enum
 * */
TypesEnum StringToType(const string& s) {
    if (!s.compare("BOOL"))
        return BOOL;
    else if (!s.compare("BYTE"))
        return BYTE;
    else if (!s.compare("INT"))
        return INT;
    else if (!s.compare("STRING"))
        return STRING;
    else if (!s.compare("VOID"))
        return VOID;
    return  NULL_TYPE;
}

/**
 * converts type enum to string type
 * */
string TypeToString(TypesEnum type) {
    if (type == VOID)
        return "VOID";
    if (type == BOOL)
        return "BOOL";
    if (type == INT)
        return "INT";
    if (type == BYTE)
        return "BYTE";
    if (type == STRING)
        return "STRING";
    return  "";
}