// https://www.geeksforgeeks.org/find-the-point-where-a-function-becomes-negative/

// First find the bound by repeated multiply by 2 to i and find the upper bound
// then apply normal binary search

  // f(0) 
  // f(1)
  // f(2)
  // f(4)
  // f(8)
  // f(16)
  // f(32)
  // ....
  // ....
  // f(high) 	high is the first element such that f(high) is greater than the element to be found 
  //             which means lo = high-1 & hi = high for normal binary search.
