from LexicalAnalyser import Lexer, LexicalAnalyser
import pprint
lexer = Lexer().build()

with open("source.c") as f:  # auto close
    lexer.input(f.read())

# lexer is an iterable
tokenList = list(lexer)
symTable = LexicalAnalyser(tokenList).buildSymTable()

pp = pprint.PrettyPrinter(indent=4)
# pp.pprint(tokenList)
print(symTable)
