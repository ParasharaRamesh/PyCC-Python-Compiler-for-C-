import ply.lex as lex
import ply.yacc as yacc
import SymbolTable as ST#make this import correct
import sys

lexer = None

reserved = {
   "if" : "IF",
   "else" : "ELSE",
   "else if" : "ELSEIF",
   "while" : "WHILE",
   "do"     :"DO",
   "switch" : "SWITCH",
   "case" : "CASE",
   "int" : "INTEGER",
   "float" : "FLOAT",
   "char" : "CHARACTER",
   "double" : "DOUBLE"
}

tokens = [
    "ID",
    "FUNCTION",
    "RELOP",
    "OPERATOR",
    "SEPERATOR",
    "LBRACKET",
    "RBRACKET",
    "LPARANTH",
    "RPARANTH",
    "LBRACE",
    "RBRACE",
    "EQUALS",
    "NEWLINE",
    "WHITESPACE",
    "NUMBER",
    "COMMENT",
    # Consider the below ones later
      # 'ERROR','COL',
      # 'INTEGER','FLOAT','STRING',
] + list(reserved.values())

options = {
    "+": "PLUS",
    "-": "MINUS",
    "*": "TIMES",
    "/": "DIVIDE",
    "%": "MOD",
    ">": "GT",
    "<": "LT",
    ">=": "GE",
    "<=": "LE",
    "==": "EQ",
    "!=": "NE"
}

#below this follows all the tokens regex in the following format
#t_tokenName= r'regex'
t_ignore = ' \t' #Dont put an r.
t_SEPERATOR = r'\;'
t_LBRACKET = r'\['
t_RBRACKET = r'\]'
t_LPARANTH = r'\('
t_RPARANTH = r'\)'
t_LBRACE = r'\{'
t_RBRACE = r'\}'
t_NUMBER = r'\d+'
# t_EQUALS = r'='
# t_WHITESPACE = r' '


def t_ID(t):
    r'[a-zA-Z_$][\w]*'
    t.type = reserved.get(t.value, "ID")
    return t

def t_OPERATOR(t):
    r'(\+)|(-)|(\*)|(/)|(%)'
    t.value = options[t.value]
    return t

def t_RELOP(t):
    r'(>)|(<)|(>=)|(<=)|(==)'
    t.value = options[t.value]
    return t

def t_NEWLINE(t):
    r'\n+'
    t.lexer.lineno += len(t.value)
    return t

def t_error(t):
    print("Illegal character '%s' skipping to the next character" % t.value[0])
    t.lexer.skip(1)

#need a function called run() which will take in line by line from the sample c file and pass it to LexicalAnalyser
'''
def lexBuild():
    global lexer
    lexer = lex.lex()#error here? - yes maybe we should combine both lexbuild and takeinput as one function
    # - we'll strip the func calls and put everything in if name == __main__: okay
    data = open('/test.c','r')
    lex.input(data.read())
    data.close()

def takeInput():#first go to symbol table and see if everyting makes sense ok
    st = ST.SymbolTable() #TypeError: __init__() takes 0 positional arguments but 1 was given
    for tok in lexer:
        st.insert(tok.value,tok.type,[tok.line,tok.lexpos])#is this correct??
'''
if __name__== "__main__":
    data = open('source.c','r')
    lexer=lex.lex()
    lexer.input(data.read())
    data.close()
    st = ST.SymbolTable()
    #for tok in lexer:
    while True:
        tok=lex.token()
        if not tok:
            break
        st.insert(tok.value,tok.type,[tok.lineno,tok.lexpos])#is this correct??
    st.expose()
