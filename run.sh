#!/bin/bash

if [ $# -eq 0 ]
	then
		echo "Please Enter name of the Source file"
		exit
fi

echo "---------------------------------------------------------------------------------------------------------------"
echo "PRE OPTIMIZATIONS"
echo "1.Constant Folding optimization"
python ConstantFolding.py
cat CF.c
echo "---------------------------------------------------------------------------------------------------------------"
echo "2.Common Subexpression Elimination"
python2 CSE.py
cat CSE.c


echo "Lexical Analysis"
echo "---------------------------------------------------------------------------------------------------------------"
python remove_comments.py $1


sleep 1
echo "----------------------------------------------------------------------------------------------------------------"
echo "Symbol table"
python ConstructST.py $1
echo ""


sleep 2
echo "---------------------------------------------------------------------------------------------------------------"
echo "Syntax Analysis"
echo "Abstract Syntax Tree"
python GenerateToken.py $1


echo ""
sleep 2
echo "---------------------------------------------------------------------------------------------------------------"
echo "Three Address Code"
cd C-programm-to-3-address-translator
#make clean
#make
./trans test2.c
cd -
#change this

#old code
# yacc -d yacc.y
# lex lex.l
# gcc -w y.tab.c lex.yy.c -std=c99 -o TAC
# ./TAC < $1 > tac.txt
# cat tac.txt

echo "---------------------------------------------------------------------------------------------------------------"
echo "POST OPTIMIZATIONS"

echo "3.Dead Code Elimination"
python code_optimizer.py
cat DCE.txt

# echo "---------------------------------------------------------------------------------------------------------------"
# echo "deleting uneccesary files"
# rm *.pyc
# rm lex.yy.c
# rm y.tab.*
# rm TAC
# rm parse*
