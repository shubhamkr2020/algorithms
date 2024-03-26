/*
  Weighted graph shortest distance
  
  Single source to single destination:
  
  Dijkstras Algo: check above folder.
  
  
  Single source to all nodes:
  
  Bellman ford: https://www.geeksforgeeks.org/?p=27914
  1. For V-1 times do relax the edges and calculate the distances of the vertices from u.
  2. If there is any update in the Vth time relaxation then there is a negative cycle in the graph and shortest distance cannot be found.



  From all source to all node:

  Floyd Warshall: https://www.geeksforgeeks.org/?p=19772
  1. k time s relax by initialising the d[i][j] to known values from direct edges or INF if unknown.
  2. do k: 0 to V
      do i: 0 to V
        do j: 0 to V
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  


*/
