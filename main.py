from LexicalAnalyser import LexicalAnalyser
lexer = LexicalAnalyser().build()

with open("source.c") as f:
    lexer.input(f.read())

for token in lexer:
    print(token.value, token.type, token.lineno, token.lexpos, sep='\t')
