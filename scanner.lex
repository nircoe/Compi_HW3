%{
    /* Declarations section */
#include <stdio.h>
#include "hw3_output.hpp"
#include "types_declaration.hpp"
#include "parser.tab.hpp"


using namespace output;

%}

%option yylineno
%option noyywrap

digit   ([0-9])
letter  ([A-Za-z])
whitespace  ([\t\n\r ])


%%

{whitespace}        ;
(void)      return VOID;
(int)       return INT;
(byte)      return BYTE;
(b)         return B;
(bool)      return BOOL;
(override)  return OVERRIDE;
(and)       return AND;
(or)        return OR;
(not)       return NOT;
(true)      return TRUE;
(false)     return FALSE;
(return)    return RETURN;
(if)        return IF;
(else)      return ELSE;
(while)     return WHILE;
(break)     return BREAK;
(continue)  return CONTINUE;
(\;)        return SC;
(\,)        return COMMA;
(\()        return LPAREN;
(\))        return RPAREN;
(\{)        return LBRACE;
(\})        return RBRACE;
(=)         return ASSIGN;
((\<=)|(\>=)|(\<)|(\>))             return RELOP;
((==)|(!=))                         return EQUALOP;
((\+)|(\-))                         return SUMOP;
((\*)|(\/))                         return MULTIPLEOP;
([a-zA-Z]+[a-zA-Z0-9]*)             {yylval = new Id_t(yytext); return ID;}
((0)|[1-9][0-9]*)                   {yylval = new Num_t(yytext); return NUM;}

(\/\/[^\r\n]*[\r|\n|\r\n]?)         ;
(\"([^\n\r\"\\]|\\[rnt"\\])+\")     return STRING;
<<EOF>>                             return END;
.                                   {output::errorLex(yylineno);}
%%