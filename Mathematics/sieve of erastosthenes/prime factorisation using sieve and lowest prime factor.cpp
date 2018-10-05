#include <bits/stdc++.h>
using namespace std;

#define N 15000001

int lp[N];              // lowest prime factor of i
// int pr[N];              // ifPrime(i)

void sieve() {
    int i,j;
    for(i=2; i<N; i++) {
        // pr[i]=1;
        lp[i]=i;
    }
    for(i=2; i*i<N; i++) {
        if(lp[i] == i)
        for(j=i*i; j<N; j+=i) {
            // pr[j] = 0;
            lp[j] = min(lp[j], i);
        }
    }
}

void primeFactorise(int n) {
    int i;
    vector<int > v;
    while(n > 1) {
        int lo = lp[n];
        while(n%lo == 0) {
            // cout<<lo<<" ";
            v.push_back(lo);
            n = n/lo;
        }
    }
    for(i=0; i<v.size(); i++) cout<<v[i]<<" "; cout<<endl;
}

int main() {

    int i;
    sieve();

    int n=100;
    // for(i=1; i<100; i++) cout<<lp[i]<<endl;
    primeFactorise(n);
    
}
