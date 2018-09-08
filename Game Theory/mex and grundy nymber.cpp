 	// GRUNDY NUMBER WITH MEX(minimum excludant - smallest non-negative number not present in the set)..................
 	// game theory when a player can subtract 2,3 or 5 from n .................................
 	// xor of grundy numbers of sub games decides the winner if(0) then second wins else first .....................
int grundy[101];
int mex(set<int> s) {
    int m=0;
    while(s.find(m) != s.end())
        m++;
    return m;
}

int Grundy(int n) {
    set<int> s;
    memset(grundy,-1,sizeof(grundy));
    grundy[0] = 0;
    grundy[1] = 0;
    grundy[2] = 1;
    grundy[3] = 2;
    grundy[4] = 2;
    grundy[5] = 1;
    if(grundy[n] != -1)
        return grundy[n];
    s.insert(Grundy(n-2));
    s.insert(Grundy(n-3));
    s.insert(Grundy(n-5));
    grundy[n] = mex(s);
    return grundy[n];
}
