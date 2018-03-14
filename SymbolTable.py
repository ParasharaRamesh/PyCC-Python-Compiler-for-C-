import ply.lex as lex
import ply.yacc as yacc
import sys


#SymbolTable is a dictionary with key as "token name" and value as a list of "token type,token attributes "

#So for each scope also we need a SymbolTable .ie each scope as in anything within {} so we can create a new Symbol table object and move on
class SymbolTable:
    def __init__():
        self.st=dict()

#these functions are apprently the "official " interface to the ST insert and lookup but dont know how to immplement it !
    def insert(self,lexeme,token,attributes):#by definition save lexeme s and token t and return pointer
        #found anything about the attributes?
        # I was talking to Rishabh
        # He said key is 'ID', 'KEYWORD', etc
        # value is a list of lists
        # with each list containing lexeme and additional attributes(that aditional attributes is the only thing we need to know what can they be?)
        #bro that sounds convoluted !,our design is pretty good i feel - this was what Prakasha taught it seems
        # Yeah, that's what I also thought
        # It all depends on how the symbol table is used in the following phases
        # In each phase, atrributes have to be added to each lexeme
        #so let the attributes be a list to which we can append stuff as and when required - Yep
        #i am searching for other implementations of this to see we  have missed anything
        # you go and do regex i will join you once i am sure this is fine
        #oh what about inserting more attributes in the attributes lists
        #i will make another function but what should i call that?
        #
        if lexeme not in self.st:
            self.st[lexeme]=[token,attributes]
        else:
            raise Exception('Could not add the current lexeme to the symbol table!')

        # def insertAttr(self, attrType, attrValue)
        #so you are telling me that attributes is a dictionary? okay finish what you have to say
        # not a dictionary, a list, with elements in order of attribute types, for eg., tokentype is list[0], addr is list[1]
        # so this means that a token at a given point of time can have only one token type so thats why its just 2 valued list? - list can have n values
        # n being num. of attributes
        # so say n is 3 how will this list be like? or just update the code directly that might make more sense anyway
        #
        # attrType can be one of TOKEN_TYPE, ADDRESS,
        #wrong indentation
        #wtf python has switch ? crazy
    def insertAttribute(self,lexeme,newAttrType,newAttrValue):
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
