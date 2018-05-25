'''
Remove statements that define only one variable and the variable being
defined is not in the live out set.
Algorithm
1) generate a control flow graph (CFG) from the list of instructions
do {
2) perform liveness on CFG
3) for each node in CFG
 if the defs set contains only one temporary
if the temporary being defined is not in the live out set
remove the node from the CFG
} while (changes);
4) generate a list of instructions from the modified CFG
'''
#any line which says goto EXIT is basically program exit
with open("tac.txt","r") as tac:
    lines=[]
    for line in tac:
        lines.append(line.split())
    ##last_lineno=str(int(lines[-1][0])+1)

    #print("lines",lines)
    i=0
    for line in lines:
        line.insert(0,str(i))
        i+=1
    #print("lines after are",lines)
exit=len(lines)
print(exit)


#return a dictionary of blocks and a dictioary as the adjacency list
def buildCFG(lines):
    adjlist=dict()
    blocks=dict()
    labellineno=dict()
    i=0
    for line in lines:
        if("L" in line[1]):# ie if there is a label in the line
            labellineno[line[1]]=i
        i+=1
    print("label line no's are ",labellineno)
    leaders=[]
    leaders.append(0)
    for i in range(0,len(lines)):
        if('goto' in lines[i]):
            leaders.append(i+1)
    for l in labellineno.values():
        leaders.append(l)
    leaders=list(set(leaders))
    #print("leaders is",leaders)
    #del leaders[-1]
    print("leaders are",leaders)
    #now for building all the blocks
    for leader in leaders:
        blocks[leader]=[]
        adjlist[leader]=[]

    for j in range(0,len(leaders)-1):
        for i in range(leaders[j],leaders[j+1]):
            blocks[leaders[j]].append(lines[i])

    for i in range(leaders[-1],len(lines)):
        blocks[leaders[-1]].append(lines[i])

    #print("blocks is",blocks)

    #now building block transitions
    for block in blocks.keys():
        blockgoto=blocks[block][-1]
        #print("blockgoto is ",blockgoto)
        if('goto' in blockgoto):
            if(blockgoto[blockgoto.index("goto")+1]!="EXIT"):
                adjlist[block].append(labellineno[blockgoto[-1]])
        else:
            adjlist[block].append(int(blockgoto[0])+1)

        for word in blockgoto:
            if(("FALSE" in word) or ("TRUE" in word) or ("<" in word) or (">" in word) or ("==" in word) or ("!=" in word)):
                adjlist[block].append(leaders[leaders.index(block)+1])
    print("basic blocks are ",blocks)
    print("adjlist is ",adjlist)
    return blocks,adjlist

#optimize by removing unreachable code and returning new code
def getAllUnreachableBlocks(blocks,adjlist):
    allblocks=blocks.keys()
    frontier=[0]#the block0 is the initial state get all connected components of that
    explored=[]
    while len(frontier)!=0:
        state=frontier.pop()
        explored.append(state)
        for neighbour in adjlist[state]:
            if neighbour!=exit:
                frontierset=set(frontier)
                exploredset=set(explored)
                if neighbour not in frontierset.union(exploredset):
                    frontier.append(neighbour)
    print("all basic blocks are",allblocks)
    print("explored is ",explored)
    unreachableBlocks=list(set(allblocks).difference(set(explored)))
    print("unreachable blocks are ",unreachableBlocks)
    return unreachableBlocks

def buildOptimisedCode(unreachableBlocks,blocks,adjlist):

    noofubs=len(unreachableBlocks)

    for ub in unreachableBlocks:
        del adjlist[ub]
        del blocks[ub]

    optlines=[]
    for block in sorted(list(blocks.keys())):
        for line in blocks[block]:
            optlines.append(line)
    oldexit=str(exit)
    newexit=str(len(optlines))

    optcode=[]
    for line in optlines:
        optcode.append(" ".join(line))
    with open("DCE.txt","w") as tac:
        for line in optcode:
            tac.write(line)
            tac.write("\n")
        if(noofubs>0):
            print("sucess!")
        else:
            print("nothing to optimize! all blocks are reachable!")



blocks,adjlist=buildCFG(lines)
unreachableBlocks=getAllUnreachableBlocks(blocks,adjlist)
buildOptimisedCode(unreachableBlocks,blocks,adjlist)
