'''
performs unreachable code elimination by building CFG and seeing which basic blocks are not reachable using DFS

takes input from the tac.txt file and outputs optimised code to tac-optimised.txt
takes input in the form where each line is denoted with a line # and the first line in the file is Three Address Code
'''
#any line which says GOTO <last_lineno> is basically program exit
with open("tac.txt","r") as tac:
    lines=[]
    for line in tac:
        lines.append(line.split())
    last_lineno=str(int(lines[-1][0])+1)
    del lines[-1]
    print(lines)
exit=len(lines)


#return a dictionary of blocks and a dictioary as the adjacency list
def buildCFG(lines):
    adjlist=dict()
    blocks=dict()
    leaders=[]
    leaders.append(0)
    for i in range(0,len(lines)):
        if('goto' in lines[i]):
            leaders.append(i+1)
    print("leaders",leaders)
    del leaders[-1]
    print("leaders now",leaders)
    #now for building all the blocks
    for leader in leaders:
        blocks[leader]=[]
        adjlist[leader]=[]
    for j in range(0,len(leaders)-1):
        for i in range(leaders[j],leaders[j+1]):
            blocks[leaders[j]].append(lines[i])
    for i in range(leaders[-1],len(lines)):
        blocks[leaders[-1]].append(lines[i])

    print("blocks",blocks)
    #now building block transitions
    for block in blocks.keys():
        lastlineofblock=blocks[block][-1]
        #print("last",lastlineofblock)
        if('goto' in lastlineofblock):
            adjlist[block].append(int(lastlineofblock[-1]))
        #print("adjlist before",adjlist)
        for word in lastlineofblock:
            if(("FALSE" in word) or ("TRUE" in word) or ("==" in word) or ("!=" in word) or (">=" in word) or ("<=" in word)):
                if((leaders.index(block)+1)<len(leaders)):
                    adjlist[block].append(leaders[leaders.index(block)+1])


    print("adjlist",adjlist)
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
    for ub in unreachableBlocks:
        del adjlist[ub]
        del blocks[ub]

    optlines=[]
    for block in sorted(list(blocks.keys())):
        for line in blocks[block]:
            optlines.append(line)
    oldexit=str(exit)
    newexit=str(len(optlines))

    for line in optlines:#you  have changed it there
        if('GOTO' in line):
            if(line[line.index("GOTO")+1]==oldexit):
                line[line.index("GOTO")+1]=newexit

    optcode=[]
    for line in optlines:
        optcode.append(" ".join(line))
    with open("DCE.txt","w") as tac:
        for line in optcode:
            tac.write(line)
            tac.write("\n")
        print("sucess!")



blocks,adjlist=buildCFG(lines)
unreachableBlocks=getAllUnreachableBlocks(blocks,adjlist)
buildOptimisedCode(unreachableBlocks,blocks,adjlist)
