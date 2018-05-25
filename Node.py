class Node:#node of a AST
	def __init__(self,type,children=None,leaf=None):
		self.type = type
		if children:
			self.children = children
		else:
			self.children = []
		self.leaf = leaf

	def disp(self):
		print("Internal node",self.type,self.leaf)
		if self.children:
			for e in self.children:
			#	print("e",e)
				print("children-->",e[1].leaf)
		#print('\n')





















#go through AST and draw and verify the nodes and connectivity
#include grammer for expressions in E1 for assignment but limit only to arithmetic operations
#go through code gen and understand
#repeat for while
