#include "types.hpp"

// checks legality of conversion from one type to another
bool ConversionLegality(TypesEnum from, TypesEnum to) {
    return ((from == TYPE_INT || from == TYPE_BYTE) && (to == TYPE_INT || to == TYPE_BYTE)) || from == to;
}

// checks the legality of an assignment from one type to another
bool AssignLegality(TypesEnum left, TypesEnum right) {
    return left == right || (left == TYPE_INT && right == TYPE_BYTE);
}

// checks binary operator result type
TypesEnum SumType(TypesEnum left, TypesEnum right) {
    if (left == TYPE_INT && right == TYPE_INT)
        return TYPE_INT;
    else if (left == TYPE_BYTE && right == TYPE_INT)
        return TYPE_INT;
    else if (left == TYPE_INT && right == TYPE_BYTE)
        return TYPE_INT;
    else if (left == TYPE_BYTE && right == TYPE_BYTE)
        return  TYPE_BYTE;
    return NULL_TYPE;
}

// converts string to type enum
TypesEnum StringToType(const string& s) {
    if (!s.compare("BOOL"))
        return TYPE_BOOL;
    else if (!s.compare("BYTE"))
        return TYPE_BYTE;
    else if (!s.compare("INT"))
        return TYPE_INT;
    else if (!s.compare("STRING"))
        return TYPE_STRING;
    else if (!s.compare("VOID"))
        return TYPE_VOID;
    return  NULL_TYPE;
}

// converts type enum to string type
string TypeToString(TypesEnum type) {
    if (type == TYPE_VOID)
        return "VOID";
    if (type == TYPE_BOOL)
        return "BOOL";
    if (type == TYPE_INT)
        return "INT";
    if (type == TYPE_BYTE)
        return "BYTE";
    if (type == TYPE_STRING)
        return "STRING";
    return  "";
}