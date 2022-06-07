grammar Mpc;

input 
    : mpcfunction? mpcvars* EOF                                        
    ;

mpcvars
    : mpcvar;

mpcvar
    : MPC DOT 'bus' LET expression SEMI                         #bus
    | MPC DOT 'gen' LET expression SEMI                         #gen
    | MPC DOT 'branch' LET expression SEMI                      #branch
    | MPC DOT 'version' LET expression SEMI                     #version
    | MPC DOT 'gencost' LET expression SEMI                     #gencost
    | MPC DOT 'baseMVA' LET expression SEMI                     #baseMVA
    ;
     
constvalue
    : FLOAT
    | INTEGER
    | STRING
    ;

mpcfunction
    : FUNCTION MPC LET VARIABLE                                 #function
    ;

vallist
    : constvalue (COMMA? constvalue)*                           #constlist
    ;

valmatrixrow
    :   vallist (SEMI vallist?)*                               
    ;

valmatrix                                                      
	:   vallist 
    |	valmatrixrow
    ;

valarray
    : LBS valmatrix RBS                                         
    ;

expression 
    : constvalue                                                #realconst  
    | VARIABLE                                                  #variable
    | valarray                                                  #array
    ;


FLOAT
    :   SIGN DOT DIGITS (Exponent)?
    |   SIGN DIGITS DOT Exponent
    |   SIGN DIGITS (DOT (DIGITS (Exponent)?)? | Exponent)
    ;


DOT : '.';
LBS: '[' ;
RBS: ']';
LET: '=' ;
FUNCTION : 'function';
INTEGER : SIGN DIGITS;
STRING: '\'' DIGITS '\'';
fragment SIGN: '-'?; 
fragment DIGITS : [0-9]+;
fragment Exponent
    :    ('e' | 'E') ( '+' | '-' )? DIGITS
    ;

MPC : 'mpc';
VARIABLE     : [a-zA-Z_][a-zA-Z_0-9]*;
LINE_COMMENT : '%' ~[\r\n]* -> skip;

NEWLINE:'\r'? '\n' ->skip;
COMMA: ',';
WSK : WS->skip;
WS : [ \t]+;
SEMI : ';';