// https://www.geeksforgeeks.org/program-nth-catalan-number/

// C(n) = number of BST with n nodes
// C(n) = take 1 as root -> left = 0 and right = n-1 -> C(0).C(n-1) +
// 			take 2 as root -> left = 1 and right = n-2 -> C(1).C(n-2) +
// 			take 3 as root -> left = 2 and right = n-3 -> C(2).C(n-2) + 
//			.
//			.
//			upto C(n-1).C(0)



// or C(n) = 2nCn/(n+1) 