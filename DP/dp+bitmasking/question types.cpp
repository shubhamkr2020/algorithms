/*

1. Find max subset sum less than k
2. Find minimum cost for n jobs and n person with given cost matrix
3. Find k equal sum subsets - https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/
4. Travelling salesman problem
5. number of ways to fill n*m grd with 1*2 brick horizontally or vertically
  dp(i,mask) = till ith column is filled and (i+1)th column is represented by the mask.


Process to solve these problems:

1. Do a bruteforce approach first - NP hard problem.
2. find the subset mask and use dp to memoize the answers.

OR

Kuch nhi smjh aa rha to dp with bitmask hi hoga... 💁‍♂️


*/
