// https://www.geeksforgeeks.org/subarray-xor-less-k/

1. make trie with XOR of subarrays from 1 to i for every i (i.e. trie contains XOR[1:i] for all i)
2. Trie node should contain a count variable for number of strings below it (or number of strings with that prefix).
3. count number of subarrays with XOR less than k by tarversing the trie for i+1 th element.