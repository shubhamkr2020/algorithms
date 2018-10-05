#include <bits/stdc++.h>
using namespace std;

#define N 15000001

int lp[N];
vector<int> pr;

void sieve() {
    int i,j;
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

int main() {

    int i;
    sieve();
    // for(i=0; i<20; i++) cout<<pr[i]<<" "; cout<<endl;

}
