#include <bits/stdc++.h>
using namespace std;

#define N 15000001

int pr[N];

void sieve() {
    int i,j;
    for(i=2; i<N; i++) pr[i]=1;
    for(i=2; i*i<N; i++) {
        if(pr[i])
        for(j=i*i; j<N; j+=i) {
            pr[j] = 0;
        }
    }
}

int main() {

    int i;
    sieve();
    // for(i=1; i<100; i++) cout<<pr[i]<<endl;

}
