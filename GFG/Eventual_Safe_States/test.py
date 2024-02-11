# import numpy as np

#Back-end complete function Template for Python 3

from typing import List
import sys
sys.setrecursionlimit(10**8)

# Depth First Search to check if a cycle is present and mark the nodes present in the cycle
def dfs(u, adj, is_visited, in_stack, nodes_present_in_cycle):
    is_visited[u] = True
    in_stack[u] = True

    # Explore all the adjacent nodes
    for v in adj[u]:
        if is_visited[v] == False:
            # Recursive call to check if there is a cycle
            is_cycle_present = dfs(v, adj, is_visited, in_stack, nodes_present_in_cycle)
            if is_cycle_present == True:
                # Mark the current node as present in the cycle and return True
                nodes_present_in_cycle[u] = True
                return True
        # If an adjacent node is visited and is in the current recursion stack, a cycle is present
        elif is_visited[v] == True and in_stack[v] == True:
            nodes_present_in_cycle[u] = True
            return True

    # Mark the current node as not in recursion stack
    in_stack[u] = False
    return False 


class Solution:    
    def eventualSafeNodes(self, V : int, adj : List[List[int]]) -> List[int]:
        safeNodes = []
        is_visited = [False] * V
        in_stack = [False] * V
        nodes_present_in_cycle = [False] * V

        # Traverse each node and perform a DFS
        for i in range(V):
            if is_visited[i] == False:
                dfs(i, adj, is_visited, in_stack, nodes_present_in_cycle)
        
        # Add the nodes that are not present in any cycle to the safeNodes list
        for i in range(V):
            if nodes_present_in_cycle[i] == False:
                safeNodes.append(i)

        return safeNodes
    
from random import shuffle


def generate_edges(v, e):
    if e > v * (v - 1):
        print("Error: Number of edges exceeds the maximum possible for this number of nodes.")
        return []

    edges = set()
    while len(edges) < e:
        src = randint(0, v - 1)
        dest = randint(0, v - 1)
        if src != dest:  # Ensure no self-loops
            edges.add((src, dest))

    return list(edges)

ob=Solution()



def writeTest(ques, filename):
    with open(filename,'w') as f:
        f.write(f'{len(ques)}\n')
        for q in ques:
            for e in q:
                f.write(f'{e[0]} {e[1]}\n')
            f.write(f'~\n')

def writeSoln(ans, filename):
    with open(filename,'w') as f:
        for a in ans:
            f.write(' '.join(str(x)for x in a))
            f.write(f'\n~\n')


# from random import randint, shuffle
from numpy.random import randint, random

##################### TC 1 ##################################

ques=[
    [
        [0,0,0],
        [0,0,0],
        [0,0,0]
    ],
    [
        [1,0,0],
        [0,1,0],
        [0,0,1]
    ],
    [
        [1,1],
        [1,1]
    ],
    [
        [0,1,1,0],
        [1,0,0,0],
        [1,0,0,0],
        [0,0,0,0]
    ],
    [
        [1,1,0,1],
        [0,1,1,0],
        [0,0,1,1],
        [0,0,0,1]
    ],
    [
        [1,0,0,1],
        [0,0,0,0],
        [0,0,0,0],
        [0,0,0,0]
    ],
    [
        [0]
    ],
    [
        [1]
    ],
]
# for i in range(2):
#     n = 5
#     ques.append(np.random.randint(0,2,(n,n)).tolist())
# ans = [transitiveClosure(len(q),q) for q in ques]

# writeTest(ques, 'zt1.txt')
# writeSoln(ans, 'zs1.txt')

##################### TC 2 ##################################

# ques = []
# ans = []
# for i in range(1000):
#     print('\r',i,end='')
#     v=randint(10,100)
#     e = min(v*v-v,randint(2*v, v+500))
#     # print(v,e)
#     es = generate_edges(v,e)
#     adj=[[]for _ in range(v)]
#     for a,b in es:
#         adj[a]+=[b]
#     # print(v,e)
#     ques.append([[v,e]]+es)
#     ans.append(ob.eventualSafeNodes(v,adj))

# writeTest(ques, 'zt2.txt')
# writeSoln(ans, 'zs2.txt')


##################### TC 3 ##################################

ques = []
ans = []
for i in range(100):
    v = randint(1000,10001)
    e = v
    # print(v,e)
    es = generate_edges(v,e)
    adj=[[]for _ in range(v)]
    for a,b in es:
        adj[a]+=[b]
    # print(v,e)
    ques.append([[v,e]]+es)
    ans.append(ob.eventualSafeNodes(v,adj))


##################### TC 4 ##################################

# ques = []
# ans = []
# for i in range(5):
#     print(i)
#     v = 10000
#     e = 10000
#     # print(v,e)
#     es = generate_edges(v,e)
#     adj=[[]for _ in range(v)]
#     for a,b in es:
#         adj[a]+=[b]
#     # print(v,e)
#     ques.append([[v,e]]+es)
#     ans.append(ob.eventualSafeNodes(v,adj))

# writeTest(ques, 'zt4.txt')
# writeSoln(ans, 'zs4.txt')