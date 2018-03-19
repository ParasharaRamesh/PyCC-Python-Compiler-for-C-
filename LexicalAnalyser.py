import ply.lex as lex
from GlobalConstants import GlobalConstants # i changed the name of the ffile has the same name as the class
#so should i rename the file to GlobalConstants - do it later i did it check - you'll have to close and open the file
#did it - keep your cursor in that file - got it
class LexicalAnalyser:
    """description of class"""
    tokens = GlobalConstants.tokens
    # Keywords
    t_DO        = r'do'
    t_WHILE     = r'while'
    t_SWITCH    = r'switch'
    t_CASE      = r'case'
    t_DEFAULT   = r'default'
    t_BREAK     = r'break'
    t_CONTINUE  = r'continue'
    t_IF        = r'if'
    t_ELSE      = r'else'
    t_FOR       = r'for'
    t_RETURN    = r'return'
    t_STATIC    = r'static'
    t_GOTO      = r'goto'
    t_SIZEOF    = r'sizeof'
    t_CONST     = r'const'

    # Separators
    t_COLON     = r':'
    t_COMMA     = r','
    t_DOT       = r'\.'
    t_SEMICOLON = r';'

    # Brackets
    t_OPRNTH = r'\('
    t_CPRNTH = r'\)'
    t_OBRACE = r'\{'
    t_CBRACE = r'\}'
    t_OBRCKT = r'\['
    t_CBRCKT = r'\]'

    # Types
    t_INT    = r'int'
    t_FLOAT  = r'float'
    t_DOUBLE = r'double'
    t_CHAR   = r'char'

    # Operators
    t_EQ        = r'=='
    t_GT        = r'>'
    t_GE        = r'>='
    t_LT        = r'<'
    t_LE        = r'<='
    t_NE        = r'!='
    t_PLUS      = r'\+'
    t_MINUS     = r'\-'
    t_TIMES     = r'\*'
    t_DIV       = r'\/'
    t_MOD       = r'%'
    t_UINCR     = r'\+\+'
    t_UDECR     = r'\-\-'
    t_SHINCR    = r'\+='
    t_SHDECR    = r'\-='
    t_SHTIMES   = r'\*='
    t_SHDIV     = r'\/='

    #Identifier and literals
    t_ID        = r'[a-zA-Z_][\w]*'
    t_STRLIT    = r'\"(\\.|[^\\"])*\"'
    t_CHRLIT    = r'\'(\\.|[^\'\\])\'' #https://stackoverflow.com/a/2039820/5356535
    t_NUMLIT    = r'\d+'
    t_FLOATLIT  = r'\d+\.\d+' # xD
    #Cant we do one for all numbers ??like what ? for long ,double etc??
    # - That's an improvement, This is enough for now yeah
    #i dont understand the STRLIT and NUMLIT regexes are they correct? in strlit what is the part i am highlighting?
    # - escape chars allows for backslashes etc within it okay peace
    #lemme run main and check
    t_ignore = '[ \t]'

    def t_COMMENT(self, t):
        r'\/\/.*'
        pass

    def t_NEWLINE(self, t):
        r'\n+'
        t.lexer.lineno += len(t.value)
        return t

    def t_error(self, t):
        #print("Illegal character '%s' skipping to the next character" % t.value[0])
        t.lexer.skip(1)

    def build(self):
        self.lexer = lex.lex(module=self)
        return self.lexer

    def t_ID(self,t):
        r'[a-zA-Z_][\w]*'
        if(t not in st):
            st.insert(t.value,"ID",[])
        #t.type = reserved.get(t.value, "ID")
        return t





# import ply.lex as lex
# import ply.yacc as yacc
# import SymbolTable as ST#make this import correct
# import sys
#
# lexer = None
#
# reserved = {
#    "if" : "IF",
#    "else" : "ELSE",
#    "else if" : "ELSEIF",
#    "while" : "WHILE",
#    "do"     :"DO",
#    "switch" : "SWITCH",
#    "case" : "CASE",
#    "int" : "INTEGER",
#    "float" : "FLOAT",
#    "char" : "CHARACTER",
#    "double" : "DOUBLE",
#    "return" : "RETURN",
# }
#
# tokens = [
#     "ID",
#     "FUNCTION",
#     "RELOP",
#     "OPERATOR",
#     "SEPERATOR",
#     "LBRACKET",
#     "RBRACKET",
#     "LPARANTH",
#     "RPARANTH",
#     "LBRACE",
#     "RBRACE",
#     "EQUALS",
#     "NEWLINE",
#     "WHITESPACE",
#     "NUMBER",
#     "COMMENT",
#     "LITERAL"
#     # Consider the below ones later
#       # 'ERROR','COL',
#       # 'INTEGER','FLOAT','STRING',
# ] + list(reserved.values())
#
# options = {
#     "+": "PLUS",
#     "-": "MINUS",
#     "*": "TIMES",
#     "/": "DIVIDE",
#     "%": "MOD",
#     ">": "GT",
#     "<": "LT",
#     ">=": "GE",
#     "<=": "LE",
#     "==": "EQ",
#     "!=": "NE"
# }
#
# #below this follows all the tokens regex in the following format
# #t_tokenName= r'regex'
# t_ignore = ' \t' #WE CAN PROBABLY IGNORE THE COMMENTS HERE!!
# t_SEPERATOR = r'\;'
# t_LBRACKET = r'\['
# t_RBRACKET = r'\]'
# t_LPARANTH = r'\('
# t_RPARANTH = r'\)'
# t_LBRACE = r'\{'
# t_RBRACE = r'\}'
# t_NUMBER = r'\d+'
# t_LITERAL = r'\"
# # t_EQUALS = r'='
# # t_WHITESPACE = r' '
# '''
# Need to add all the reserved words into the symbol table initially. oh yeah you can do that in init only i think
# but insert follows the init function. um i dont know how to insert now okay wait come there
# okay do that i will do that commmets thing and join you
# '''
#
# def t_COMMENT(t):
#     r'\/\*(\*(?!\/)|[^*])*\*\/'
#     pass
#
# def t_ID(t):
#     r'[a-zA-Z_$][\w]*'
#     t.type = reserved.get(t.value, "ID")
#     return t
#
# def t_OPERATOR(t):
#     r'(\+)|(-)|(\*)|(/)|(%)'
#     t.value = options[t.value]
#     return t
#
# def t_RELOP(t):
#     r'(>)|(<)|(>=)|(<=)|(==)'
#     t.value = options[t.value]
#     return t
#
# def t_NEWLINE(t):
#     r'\n+'
#     t.lexer.lineno += len(t.value)
#     return t
#
# def t_error(t):
#     #print("Illegal character '%s' skipping to the next character" % t.value[0])
#     t.lexer.skip(1)
#
# #need a function called run() which will take in line by line from the sample c file and pass it to LexicalAnalyser
# '''
# def lexBuild():
#     global lexer
#     lexer = lex.lex()#error here? - yes maybe we should combine both lexbuild and takeinput as one function
#     # - we'll strip the func calls and put everything in if name == __main__: okay
#     data = open('/test.c','r')
#     lex.input(data.read())
#     data.close()
#
# def takeInput():#first go to symbol table and see if everyting makes sense ok
#     st = ST.SymbolTable() #TypeError: __init__() takes 0 positional arguments but 1 was given
#     for tok in lexer:
#         st.insert(tok.value,tok.type,[tok.line,tok.lexpos])#is this correct??
# '''
# if __name__== "__main__":
#     data = open('source.c','r')
#     lexer=lex.lex()
#     lexer.input(data.read())
#     data.close()
#     st = ST.SymbolTable()
#
#     #for tok in lexer:
#     while True:
#         tok=lex.token()
#         if not tok:
#             break
#         st.insert(tok.value,tok.type,[tok.lineno,tok.lexpos])#is this correct??
#     st.expose()
