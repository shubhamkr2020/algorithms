double lo=0, hi=1e18;
while (hi - lo > 1e-10) {
	double mid = (lo + hi) / 2;
	if (check(mid)) hi = mid;
	else lo = mid;
}