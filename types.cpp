#include "types.hpp"

bool isLegalAssign(string left, string right)
{
    if(left == "" || right == "") return false;
    return left == right || (left == "int" && right == "byte");
}

bool IsLegalConvertion(string from_type, string to_type)
{
    return from_type == to_type || 
            ((from_type == "int" || from_type == "btye") && 
                (to_type == "int" || to_type == "byte"));
}

string GetSumType(string left_type, string right_type)
{
    if(left_type == "int") {
        if(right_type == "int" || right_type == "byte") return "int";
    }
    else if(left_type == "byte") {
        if(right_type == "int") return "int";
        else if(right_type == "byte") return "byte";
    }

    return "";
}
