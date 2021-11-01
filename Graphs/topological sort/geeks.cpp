/*

1. topological sort using dfs, recursion stack me stack - pehle usko explore jo baad me h and push that to stack.
		https://www.geeksforgeeks.org/topological-sorting/

2. Kahn's algo - bfs type: pick up the node with 0 in-degree and reduce indegrees of all other nodes connected to it, then pickup 0 indegree again
		https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/

3. Longest path in a graph:
	=> NP hard for normal graphs from a source but O(n^2) for undirected graph for any two vertices.
	=> for DAG, we can use top sort and relax for max every connected vertices in topological order.
		https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/

4. Given a sorted dictionary of an alien language, find order of characters:
	https://www.geeksforgeeks.org/given-sorted-dictionary-find-precedence-characters/


*/