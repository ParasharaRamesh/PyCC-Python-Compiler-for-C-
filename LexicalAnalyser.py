import ply.lex as lex
import ply.yacc as yacc
import sys

class LexicalAnalyser:
    def __init__():
        #list of all tokens

        self.tokens = [
            "ID",
            "KEYWORD",
            "RELOP",
            "OPERATORS",
            "SEPERATORS",
            "LBRACKET",
            "RBRACKET",
            "LPARANTH",
            "RPARANTH",
            "LBRACE",
            "RBRACE"
        ]

        #regular definitions
        letter=r'[_a-zA-Z]'
        digit=r'[0-9]'

        #below this follows all the tokens regex in the following format
        #t_tokenName= r'regex'

        #just saw this in other python c compilers using ply

        t_ID= r'[a-zA-Z_$][\w]*'
        t_KEYWORD= r'' # Keywords are reserved in C, and ply handles reserved words in a different way okay so yno need of that then
        t_RELOP= r''
        t_OPERATORS=r''
        t_SEPERATORS= r''
        t_LBRACKET= r'\['
        t_RBRACKET= r'\]'
        t_LPARANTH= r'\('
        t_RPARANTH= r'\)'
        t_LBRACE= r'\{'
        t_RBRACE= r'\}'

#bro look at this link
#https://github.com/shiyanhui/Compiler/blob/master/compiler.py

    #below this are all the functions for each token in the following format
    '''
        def t_tokenName():
           blah
    '''

    def t_ID(t):
        pass


    #need a function called run() which will take in line by line from the sample c file and pass it to LexicalAnalyser
    def run():
        pass
