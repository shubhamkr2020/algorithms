
// A directed graph has an eulerian cycle if following conditions are true.
// 1) All vertices with nonzero degree belong to a single strongly connected component.
// 2) In degree and out degree of every vertex is same.


// For undirected graph :

//	1. Eulerian Cycle:
// 	An undirected graph has Eulerian cycle if following two conditions are true.
// 	….a) All vertices with non-zero degree are connected. We don’t care about vertices with zero degree because they don’t belong to Eulerian Cycle or Path (we only consider all edges).
// 	….b) All vertices have even degree.

// 	2. Eulerian path:
//	An undirected graph has Eulerian Path if following two conditions are true.
// 	….a) Same as condition (a) for Eulerian Cycle
// 	….b) If two vertices have odd degree and all other vertices have even degree. 
// 			Note that only one vertex with odd degree is not possible in an undirected graph 
// 			(sum of all degrees is always even in an undirected graph)



// https://www.geeksforgeeks.org/eulerian-path-and-circuit/

// https://www.geeksforgeeks.org/euler-circuit-directed-graph/


1. Find if vertices with non zero degree are strongly connected or not (if not return false;)
2. Find indegree of every vertices
3. check for all nodes if indegree = outdegree or not (if not return false;)
4. return true;