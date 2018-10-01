// 1. https://www.geeksforgeeks.org/ways-color-3n-board-using-4-colors/
// 2. https://codeforces.com/contest/1051/problem/D

// solution for 2:

#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(i=j;i<k;i++)
#define ll long long
#define pb push_back
#define mod 998244353

int main() {    
    ll n, k;
    cin>>n>>k;
    ll i,j,l;
    ll dp[n+1][k+1][4];                // {{w,w},{w,b},{b,w},{b,b}}
    rep(i,0,n+1) rep(j,0,k+1) rep(l,0,4) dp[i][j][l] = 0;
    dp[1][1][0]=1;
    dp[1][2][1]=1;
    dp[1][2][2]=1;
    dp[1][1][3]=1;
    
    rep(i,2,n+1) {
        rep(j,1,k+1) {
            
            dp[i][j][0] = (dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2]+dp[i-1][j-1][3])%mod;
            dp[i][j][1] = (dp[i-1][j-1][0]+dp[i-1][j][1]+(j>1?dp[i-1][j-2][2]:0)+dp[i-1][j-1][3])%mod;
            dp[i][j][2] = (dp[i-1][j-1][0]+(j>1?dp[i-1][j-2][1]:0)+dp[i-1][j][2]+dp[i-1][j-1][3])%mod;
            dp[i][j][3] = (dp[i-1][j-1][0]+dp[i-1][j][1]+dp[i-1][j][2]+dp[i-1][j][3])%mod;
            
        }
    }
    cout<<(dp[n][k][0]+dp[n][k][1]+dp[n][k][2]+dp[n][k][3])%mod<<endl;
    
    return 0;
}