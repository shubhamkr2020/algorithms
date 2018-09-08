// https://www.geeksforgeeks.org/find-k-cores-graph/
// Find a subgrapgh having degree of all the vertices greater than k 

// Steps :
// 1. Find the minimum degree vertex in graph and calc degree of every vertex
// 2. Start dfs from that vertex and if degree of vertex is less than k then delete that vertex
//		which means decrease the degree of every connected vertex by 1 and dfs them.
// 3. continue till the degree of vertices are less than k.