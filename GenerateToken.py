import sys
import Node
import ply.lex as lex
import ply.yacc as yacc

# reserved = {
#    'while': 'WHILE',
#    'do': 'DO',
#    'main':'MAIN'
# }
keywords = {'true':'TRUE','false':'FALSE','return':'RETURN','while':'WHILE','do':'DO','main':'MAIN','if':'IF', 'then':'THEN','else':'ELSE','int':'INT','float':'FLOAT','case':'CASE','default':'DEFAULT','switch':'SWITCH','break':'BREAK','return':'RETURN'}
literals=['(',')','=',';','}','{','+','-']

lit=['LBRACE','RBRACE']
comparators=['LESSTHAN','GREATERTHAN','EQUALS','NOTEQUALS','LESSTHANOREQUAL','GREATERTHANOREQUAL']
unary=['DECREMENT','INCREMENT']


tokens = ['UNARY','COMPARATORS','LBRACE','RBRACE','AND','OR','RSQUARE','LSQUARE','LITERALSTRING','LPAREN','RPAREN','NUMBER','PLUS',
		  'MINUS','TIMES','DIVIDE','SEMICOLON','COLON','ID','ASSIGNMENT','HASH','DOT'] + list(keywords.values()) #+list(reserved.values())

print("tokens are ",tokens)
# Regular expression rules for simple tokens
# t_MAIN= r'main'
# t_DO=r'do'
# t_WHILE= r'while'
t_PLUS= r'\+'
t_MINUS= r'-'
t_TIMES= r'\*'
t_DIVIDE= r'/'
t_LPAREN= r'\('
t_RPAREN= r'\)'
t_SEMICOLON=r';'
t_COLON=r'\:'
t_ASSIGNMENT=r'='
#t_DECREMENT=r'--'
#t_INCREMENT=r'\+\+'
t_LBRACE=r'\{' #remove varvalues from tokens when this is commented
t_RBRACE=r'\}' #add when uncommented #better use another list like we have used lit[]
t_LITERALSTRING=r'\".*\"'
#t_LESSTHAN=r'<'
#t_GREATERTHAN=r'>'
t_AND=r'&&'
t_OR=r'\|\|'
#t_EQUALS=r'=='
#t_NOTEQUALS=r'!='
t_RSQUARE=r'\]'
t_LSQUARE=r'\['
t_HASH=r'\#'
t_DOT=r'\.'
# A regular expression rule with some action code

precedence = (
	('left','PLUS','MINUS'),
	('left','TIMES','DIVIDE'),
	)


def t_UNARY(t):
	r'( \+\+ | -- )'
	t.type='UNARY'    #this return type should match varvalues from tokens[] list!important
	return t

def t_COMPARATORS(t):
	r'( < | > | >= | <= | == | != )'
	t.type = 'COMPARATORS'
	return t


def t_ID(t):
	r'[a-zA-Z_][a-zA-Z_0-9]*'
	#t.type = reserved.get(t.value,'ID')    # Check for reserved words
	t.type = keywords.get(t.value,'ID')
	return t


def t_NUMBER(t):
    r'(\d+.\d+)|(\d+)'
    if '.' in t.value:
        t.value = float(t.value)
    else:#if('+' not in t.value and '-' not in t.value and '*' not in t.value and '/' not in t.value):#was just else
        t.value= int(t.value)
    return t

# Define a rule so we can track line numbers
def t_newline(t):
	r'\n+'
	t.lexer.lineno += len(t.value)

# A string containing ignored characters (spaces and tabs)
t_ignore  = ' \t'

# Error handling rule
def t_error(t):
	print("Illegal character '%s'" % t.value[0])
	t.lexer.skip(1)

# Build the lexer
#lexer = lex.lex()

lex.lex()

# Test it out
'''
3 + 4 * 10
  + -20 *2 if==(=)else{--};
'''

# Give the lexer some input
#lexer.input(data)




varvalues={ }
types={ }

'''
grammer rules used here:

PROGRAM: INT MAIN LPAREN RPAREN LBRACE CODE RBRACE
CODE: STMT CODE
CODE: empty
STMT: S1 | S2 | S3 | S4 | BREAK SEMICOLON
S1: TYPE_NAME_STORE SEMICOLON
TYPE_NAME_STORE: INT ID ASSIGNMENT EXPR
TYPE_NAME_STORE: FLOAT ID ASSIGNMENT EXPR
S2: BASICIF | COMPLEXIF

S2:	SWITCH LPAREN EXPR RPAREN LBRACE MULTICASE RBRACE
MULTICASE: CASESTMT MULTICASE |
CASESTMT: CASE EXPR COLON STMT | DEFAULT COLON STMT


BASICIF: IF LPAREN COND RPAREN LBRACE CODE RBRACE
COMPLEXIF: BASICIF ELSE LBRACE CODE RBRACE
S3: DO LBRACE CODE RBRACE WHILE LPAREN COND RPAREN SEMICOLON

S3 : WHILE LPAREN COND RPAREN LBRACE CODE RBRACE

S4: ID ASSIGNMENT EXPR SEMICOLON


EXPR: NUMBER
EXPR: ID
EXPR: EXPR PLUS EXPR
EXPR: EXPR MINUS EXPR
EXPR: EXPR MUL EXPR
EXPR: EXPR DIV EXPR
EXPR: LPAREN EXPR RPAREN

COND: EXPR OR EXPR
COND: EXPR AND EXPR
COND: NOT COND(not included)
COND: EXPR COMPARATORS EXPR
COND: ID
COND: NUMBER
COND: TRUE
COND: FALSE


'''


def p_PROGRAM(p):
    'PROGRAM : INT MAIN LPAREN RPAREN LBRACE CODE RBRACE'
    print("-------------------------------------\nVALID")
    # just for checking the values of variables at the end of the program!
    print("-------------------------------------\nvarvalues:\nvariable\t   value")
    for keys in varvalues:
        print(keys,"\t\t  ", varvalues[keys])
    print("-------------------------------------\nTypes:\nVariable  type")
    for keys in types:
        print(keys,"\t\t  ", types[keys])
    # print("varvalues=",varvalues)
    # print("types=",types)

def p_CODE(p):
    '''CODE : STMT CODE
            | '''
    pass

# def p_CODE_empty(p):
#     'CODE : empty'
#     pass

def p_STMT(p):
    '''STMT : S1
            | S2
            | S3
            | S4
			| S5
			| S6
	'''
    pass

def p_S5(p):
	'''S5 : BREAK SEMICOLON'''
	pass

def p_S6(p):
	'''S6 : RETURN SEMICOLON'''
	pass

def p_S1(p):
    '''S1 : TYPE_NAME_STORE SEMICOLON'''
    pass

# def p_S2(p):old
#     '''S2 : BASICIF
#           | COMPLEXIF'''
#     pass

def p_S2(p):
    '''S2 :	SWITCH LPAREN EXPR RPAREN LBRACE MULTICASE RBRACE'''
    pass

def p_MULTICASE(p):
	'''MULTICASE : CASESTMT MULTICASE
				|'''
	pass

def p_CASESTMT(p):
	'''CASESTMT : CASE EXPR COLON CODE
			   | DEFAULT COLON CODE'''
	pass

# def p_S3(p):
#     '''S3 : DO LBRACE CODE RBRACE WHILE LPAREN COND RPAREN SEMICOLON'''
#     pass

def p_S3(p):
    '''S3 : WHILE LPAREN COND RPAREN LBRACE CODE RBRACE'''
    pass

def p_S4(p):
	''' S4 : ID ASSIGNMENT EXPR SEMICOLON '''
	if types[p[1][0]] == type(p[3][0]):
		varvalues[p[1][0]] = p[3][0] #store value of a in p[0] only if a is declared
		print("done for b=4")
		p[0] = list()
		p[0].append(p[3][0])#value of E
		#list which has p[1] = name of the variable
		p[1] = [ p[1] ]
		#print("p[1] is",p[1])
		p[1].append(Node.Node('ID',[],p[1][0]))
		#print("p[1]  now is",p[1])
		p[0].append(Node.Node('Assign',[p[1],p[3]],p[2]))
		#print('Assign',p[1],p[3])
		print('Assign',p[0][1].leaf,p[0][1].children)
		print("varvalues[p[0]]",p[0])
	else:
		print("SEMANTIC ERROR at line ",p.lineno(1),", The type of LHS i.e ",p[1],"'s type:",types[p[1]]," and that of RHS whose  type is ",type(p[3][0]),"are not compatible")
		raise SyntaxError

def p_BASICIF(p):
    '''BASICIF : IF LPAREN COND RPAREN LBRACE CODE RBRACE'''
    pass

def p_COMPLEXIF(p):
    '''COMPLEXIF : BASICIF ELSE LBRACE CODE RBRACE'''
    pass

def p_STORE_int(p):#was E1
	'''TYPE_NAME_STORE : INT ID ASSIGNMENT EXPR'''
	#print("p[4] is...",p[4])
	if type(p[4][0]) == float and p[4][0] % 1 == 0:
		p[4][0]=int(p[4][0])
		print("converted!",p[4][0],type(p[4][0]))
	if type(p[4][0]) == int:
		varvalues[p[2][0]] = p[4][0]
		types[p[2][0]] = int
	else:
		print("SEMANTIC ERROR:LHS type:'int' RHS type:",type(p[4][0]))
		raise SyntaxError

def p_STORE_float(p):#was E1
	'''TYPE_NAME_STORE : FLOAT ID ASSIGNMENT EXPR'''
	if type(p[4][0]) == float:
		varvalues[p[2][0]] = p[4][0]
		types[p[2][0]] = float
	else:
		print("SEMANTIC ERROR:LHS type:'float' RHS type:",type(p[4][0]))
		raise SyntaxError


def p_COND_or(p):
	'''COND : EXPR OR EXPR'''
	p[0] = list()
	p[0].append(p[1][0] or p[3][0])
	p[0].append(Node.Node('Logop',[p[1],p[3]],p[2]))
	print(p[0][1].disp())

def p_COND_and(p):
	'''COND : EXPR AND EXPR'''
	p[0] = list()
	p[0].append(p[1][0] and p[3][0])
	p[0].append(Node.Node('Logop',[p[1],p[3]],p[2]))
	print(p[0][1].disp())

# def p_COND_not(p):
#     #'''COND : NOT COND'''
#     pass

def p_COND_comparators(p):
	'''COND : EXPR COMPARATORS EXPR'''
	if(p[2] == '<' ):
		p[0] = list()
		p[0].append(p[1][0] < p[3][0])
		p[0].append(Node.Node('Relop',[p[1],p[3]],p[2]))
	elif(p[2] == '>' ):
		p[0] = list()
		p[0].append(p[1][0] > p[3][0])
		p[0].append(Node.Node('Relop',[p[1],p[3]],p[2]))
	elif(p[2] == '<=' ):
		p[0] = list()
		p[0].append(p[1][0] <= p[3][0])
		p[0].append(Node.Node('Relop',[p[1],p[3]],p[2]))
	elif(p[2] == '>=' ):
		p[0] = list()
		p[0].append(p[1][0] >= p[3][0])
		p[0].append(Node.Node('Relop',[p[1],p[3]],p[2]))
	elif(p[2] == '==' ):
		p[0] = list()
		p[0].append(p[1][0] == p[3][0])
		p[0].append(Node.Node('Relop',[p[1],p[3]],p[2]))
	elif(p[2] == '!=' ):
		p[0] = list()
		p[0].append(int(p[1][0]) != int(p[3][0]))
		p[0].append(Node.Node('Relop',[p[1],p[3]],p[2]))
	print(p[0][1].disp())

def p_COND_number(p):
	'''COND : NUMBER'''
	p[0] = p[1]

def p_COND_id(p):
	'''COND : ID'''
	p[0] = p[1]
	#print('B_id',p[1])
	#p[0] = p[1]

def p_COND_true(p):
	'''COND : TRUE'''
	p[0] = list()
	p[0].append(True)
	p[0].append(Node.Node('Bool',[],True))
	#print(p[0][1].disp())

def p_COND_false(p):
	'''COND : FALSE'''
	p[0] = list()
	p[0].append(False)
	p[0].append(Node.Node('Bool',[],False))
	#print(p[0][1].disp())

def p_EXPR_PLUS(p):
	'''EXPR : EXPR PLUS EXPR'''
	p[0] = list()
	p[0].append(p[1][0] + p[3][0])
	p[0].append(Node.Node('Binop_plus',[p[1],p[3]],p[2]))
	print(p[0][1].disp())
	#print("parsed E in PLUS:",p[0],p[1],p[2],p[3])

def p_EXPR_MINUS(p):
	'''EXPR : EXPR MINUS EXPR'''
	p[0] = list()
	p[0].append(p[1][0] - p[3][0])
	p[0].append(Node.Node('Binop_minus',[p[1],p[3]],p[2]))
	print(p[0][1].disp())
	# print("parsed E in MINUS:",p[1],p[2],p[3])

def p_EXPR_TIMES(p):
	'''EXPR : EXPR TIMES EXPR'''
	p[0] = list()
	p[0].append(p[1][0] * p[3][0])
	p[0].append(Node.Node('Binop_times',[p[1],p[3]],p[2]))
	print(p[0][1].disp())
	#print("parsed E in PLUS:",p[0],p[1],p[2],p[3])

def p_EXPR_DIVIDE(p):
	'''EXPR : EXPR DIVIDE EXPR'''
	p[0] = list()
	p[0].append(p[1][0] / p[3][0])
	p[0].append(Node.Node('Binop_divide',[p[1],p[3]],p[2]))
	print(p[0][1].disp())
	# print("parsed E in MINUS:",p[1],p[2],p[3])

def p_EXPR_NUMBER(p):
	'''EXPR : NUMBER'''
	p[0] = list()
	p[0].append(p[1])
	p[0].append(Node.Node('Num',[],p[1]))
	#print(p[0][1].disp())
	# print("parsed E:",p[1])

def p_EXPR_ID(p):
	'''EXPR : ID'''
	#print(p[1]) #o/p: a ,ie variable varvalues
	# print("a type:",types[p[1]])
	# print("result type:",type(varvalues[p[1]]))
	# print("p[1]:",varvalues[p[1]])
	if p[1] in varvalues :
		p[0] = list()
		p[0].append(varvalues[p[1]])
		p[0].append(Node.Node('ID',[],p[1]))
		#print(p[0][1].disp())
	else:
		print(p[1]," is not defined, at line", p.lineno(1))
		raise SyntaxError
	#print("parsed E:",p[1],len(p))

def p_EXPR_BRACES(p):
    '''EXPR : LPAREN EXPR RPAREN'''
    p[0]=p[2]

# def p_empty(p):
#     'empty:'
#     pass

def p_error(p):
	print("Syntax error in input!")#" while parsing rule",p)

yacc.yacc()

#while True:
'''try:
	   s = data
   except EOFError:
	   break
   if not s: continue
'''
#print(tokens)
#s=input()
#yacc.parse("if(a){c=a+b;}else{if(c<d){c=0;}}")
if len(sys.argv) < 2:
	print("Please Enter the name of the Source file")
	exit(0)

'''f1 = open('in1.c', 'r+');
data1=f1.read()
yacc.parse(data1)'''
#print(result)

with open(sys.argv[1], 'r+') as f:
	yacc.parse(f.read())#,debug=1)uncomment for error debugging
