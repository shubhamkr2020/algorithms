/*

Tarjan's Algorithm for finding Strongly Connected Components in a graph:
https://www.youtube.com/watch?v=wUgWX0nc4NY


Concepts:

1. Strongly connected components are the components in which all nodes can be visited from any other node and vice versa (self contained cycles)
2. low-link value: is the smallest node id reachable from that node (including itslef) in the SCC. assign ids yourslef or use given ids.


Tarjan's Algo:

1. Do dfs from every unvisited node
2. push it to a stack to identify if it being explored. 
3. find the low link value of the node by visiting all the neighbours and while backtrack assign the low[u] = min(low[u], low[v]).
4. then while the low[u] != u, pop all the nodes from the stack and assign that they are visited and part of one scc.
5. continue for the left nodes and find the next scc.




To check a cycle in the graph:

while poping form the stack in step 4 if more than one node is popped then there was a cycle in the SCC. 
If only one node is popped then also check the self loop.



*/
