
// never use this implementation....

double lo=0, hi=1e18;
while (hi - lo > 1e-10) {
	double mid = (lo + hi) / 2;
	if (check(mid)) hi = mid;
	else lo = mid;
}


// Use this.....

double a = 0.0; //never gonna happend
double b = 100000000000000000000.0; //never gonna happen
for (int it = 1; it <= 70; it++) { // some coders use 40, others 70, Same varies according to the problem
   double mid = (a + b) / 2.0;
   if (check(mid)) b = mid;
   else a = mid;
}
cout << b << endl;


// You can do simple binary search on integers by this method as well.
// follow this - https://codeforces.com/blog/entry/9901 for details
