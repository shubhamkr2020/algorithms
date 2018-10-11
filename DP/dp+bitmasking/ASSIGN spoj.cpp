// https://www.spoj.com/problems/ASSIGN/
// tutorial - http://wilanw.blogspot.com/2010/06/spoj-assignments-assign.html

// if number of students and number of topics are different then use 2D dp. 

// solution:

#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(i=j;i<k;i++)
#define ll long long

ll a[25][25];
ll allmask;
ll n;
ll dp[1100000];

int main() {
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin>>t;
    while(t--) {
        cin>>n;
        ll i,j;
        rep(i,0,n) rep(j,0,n) cin>>a[i][j];
        allmask = (1<<n)-1;
        rep(i,0,allmask+1) dp[i] = 0;
        dp[0]=1;
        int mask;
        rep(mask,0,allmask+1) {
            int c=0, temp=mask;
            while(temp) {
                if(temp&1) c++;
                temp >>= 1;
            }
            rep(i,0,n) {
                if(a[c][i] && (mask&(1<<i)) == 0)
                    dp[mask|(1<<i)] += dp[mask];
            }
        }
        cout<<dp[allmask]<<endl;
    }
}