
// https://www.hackerrank.com/challenges/kevin-and-expected-value/problem
// When the number(N) is very large we can do integration instead of summation to find Sum(g(x)) from 0 to N.

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define rep(i,j,k) for(i=j; i<k; i++)

double fun(double i) {
	return (1+sqrt(1+4*i))/2;
}

double intgralfun(double n) {
	return (1.0*(n-1)/2 + 1.0*pow(1+4*(n-1), 1.5)/12 - 1/12)/n;
}

int main() {
    int t;
    cin>>t;
    int i;
    double b[1000001];
    b[0] = 0.00;
    rep(i,1,1000001) {
        b[i] = fun(i);
        b[i] = b[i-1] + b[i];
    }
    
    //cout<<pow(4,1.5)<<endl;
    //rep(i,0,5)cout<<b[i]<<" ";cout<<endl;
    //rep(i,1,5111111) 
    //rep(i,0,5)cout<<b[i]<<" ";cout<<endl;
    
    while(t--) {
        double n;
        cin>>n;
        double ans;
        if(n<1000001)
        ans = 1.0*b[int(n-1)]/n;
        else ans = intgralfun(n);			// Integration from 0 to n;
        
        //cout<<ans<<endl;
        //ans = 0.5 + 0.5*(ans);
        
        printf("%.32lf\n",ans);
        
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
