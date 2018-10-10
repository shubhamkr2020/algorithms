// https://www.geeksforgeeks.org/given-array-strings-find-strings-can-chained-form-circle/

1. Create a graph connecting first and last charachter of every string
2. Check if it has a eulerian circuit or not (if not return false;)
	else return true;