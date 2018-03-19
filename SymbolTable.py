import ply.lex as lex
import ply.yacc as yacc
import sys


#SymbolTable is a dictionary with key as "token name" and value as a list of "token type,token attributes "
#token attributes are =lexeme, value, type(if applicable),line number, lex position

#So for each scope also we need a SymbolTable .ie each scope as in anything within {} so we can create a new Symbol table object and move on
class SymbolTable:

    def insert(self,lexeme,token,attributes):#by definition save lexeme s and token t and return pointer
        self.st[lexeme]=[token]+attributes #We'll have varying lengths of attributes.
        # if lexeme not in self.st:
        #     self.st[lexeme]=[token]+attributes #We'll have varying lengths of attributes.
        # else:
        #     raise Exception('Could not add the current lexeme to the symbol table!')

    def __init__(self):
        self.st=dict()
        #reserved=("while")
        #self.st.insert(rword for rword in reserved)

    def insertAttribute(self,lexeme,newAttrType,newAttrValue):#is this function necessary?
        if lexeme not in self.st:
            """
                attrTypes = {"TOKENTYPE": 0, "ADDR": 1, "DATATYPE": 2}
            """
            self.st[lexeme][attrTypes[newAttrType]] = newAttrValue
        else:
            raise Exception('Could not add the new Attribute for the current lexeme!')

    def lookup(self,lexeme):#by definition return index of entry for lexeme s or 0 if s is not found
        if lexeme in self.st.keys():
            return self.st[lexeme]
        else:
            raise Exception(' Current lexeme is not present in SymbolTable')

    def delete(self,lexeme):#maybe remove a lexeme from the SymbolTable
        if lexeme in self.st.keys():
            del self.st[lexeme]
        else:
            raise Exception('Current lexeme is not present in SymbolTable so cant be deleted!')

    def flushSymbolTable(self):#maybe completely remove all the rows in the SymbolTable
        for k in self.st.keys():
            del self.st[lexeme]
        print("Sucessfully flushed the symbol table")

    def expose(self):#okay maru test it now ! put the path of the c file correcctly and try it out!
        [print(key, self.st[key]) for key in self.st]
