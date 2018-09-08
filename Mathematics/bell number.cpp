// https://www.geeksforgeeks.org/bell-numbers-number-of-ways-to-partition-a-set/

// Number of ways of partitioning set of n numbers

// Calculate using bell triangle 
// 1
// 1 2
// 2 3 5
// 5 7 10 15
// 15 20 27 37 52

// B[i][0] = B[i-1][i-1] and
// B[i][j] = B[i][j-1] + B[i-1][j-1]