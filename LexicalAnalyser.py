import ply.lex as lex
from GlobalConstants import GlobalConstants
from SymbolTable import SymbolTable
# i changed the name of the ffile has the same name as the class
#so should i rename the file to GlobalConstants - do it later i did it check - you'll have to close and open the file
#did it - keep your cursor in that file - got it


class Lexer:
    """description of class"""
    tokens = GlobalConstants.tokens
    reserved = GlobalConstants.reserved
    # Keywords
    t_DO = r'do'
    t_WHILE = r'while'
    t_SWITCH = r'switch'
    t_CASE = r'case'
    t_DEFAULT = r'default'
    t_BREAK = r'break'
    t_CONTINUE = r'continue'
    t_IF = r'if'
    t_ELSE = r'else'
    t_FOR = r'for'
    t_RETURN = r'return'
    t_STATIC = r'static'
    t_GOTO = r'goto'
    t_SIZEOF = r'sizeof'
    t_CONST = r'const'

    # Separators
    t_COLON = r':'
    t_COMMA = r','
    t_DOT = r'\.'
    t_SEMICOLON = r';'

    # Brackets
    t_OPRNTH = r'\('
    t_CPRNTH = r'\)'
    t_OBRACE = r'\{'
    t_CBRACE = r'\}'
    t_OBRCKT = r'\['
    t_CBRCKT = r'\]'

    # Types
    t_INT = r'int'
    t_FLOAT = r'float'
    t_DOUBLE = r'double'
    t_CHAR = r'char'

    # Operators
    t_EQ = r'=='
    t_GT = r'>'
    t_GE = r'>='
    t_LT = r'<'
    t_LE = r'<='
    t_NE = r'!='
    t_PLUS = r'\+'
    t_MINUS = r'\-'
    t_TIMES = r'\*'
    t_DIV = r'\/'
    t_MOD = r'%'
    t_UINCR = r'\+\+'
    t_UDECR = r'\-\-'
    t_SHINCR = r'\+='
    t_SHDECR = r'\-='
    t_SHTIMES = r'\*='
    t_SHDIV = r'\/='

    #Identifier and literals
    t_ID = r'[a-zA-Z_][\w]*'
    t_STRLIT = r'\"(\\.|[^\\"])*\"'
    # https://stackoverflow.com/a/2039820/5356535
    t_CHRLIT = r'\'(\\.|[^\'\\])\''
    t_NUMLIT = r'\d+'
    t_FLOATLIT = r'\d+\.\d+'  # xD
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


class LexicalAnalyser:
    def __init__(self, tokenList):
        self.tokenList = tokenList

    def buildSymTable(self):  # returns root node
        curSTNode = SymbolTable()
        curSeqNum = 0
        curSTNode.setSeqNum(curSeqNum)
        curSeqNum += 1
        isEnd = False
        for token in self.tokenList:
            # print(token.value, token.type, token.lineno, token.lexpos, sep='\t')
            if isEnd:
                raise Exception("Illegal tokens after end of program")
            # if token type is ID, do stuff
            if token.type == "ID":
                # only add to st in this case only
                if token.value not in GlobalConstants.reserved:  # -  I think adding functions in LexicalAnaylser.py would have been easier so lets do that all this should be in LexicalAnalyser i think
                    curSTNode.insert(token.value, token.type,
                                     None, None, token.lineno, token.lexpos)
            elif token.type == "OBRACE":
                # TODO: backtrack when 'while' or 'switch' seen, useful in following phases
                stNew = SymbolTable()
                stNew.setSeqNum(curSeqNum)
                print("Seqno", stNew.getSeqNum())
                curSeqNum += 1
                curSTNode.addChild(stNew)
                curSTNode = stNew
            elif token.type == "CBRACE":
                curSTNode = curSTNode.getParent()
                curSeqNum -= 1
                if curSTNode.getParent() is None:
                    isEnd = True
                    print("End of program")
                    return curSTNode

# So token stream is like flattened symbol table?
# so in SymbolTable we only put the IDs but here we gotta show evreything right-?self.
# tokenList has everything, we can add more attributes to each token dynamically if wanted
# okay so what now? someone start
