
// https://www.codechef.com/problems/TSHIRTS

#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(i=j;i<k;i++)
#define ll long long
#define all(v) v.begin(),v.end()
#define pii pair<ll ,ll >
#define xx first
#define yy second
#define pb push_back
#define N 1100
#define mod 1000000007

vector<ll> ts[N];
ll n, allmask;
ll dp[N][N];

void init() {
    ll i,j;
    allmask = (1<<n)-1;
    rep(i,0,101) {
        ts[i].clear();
    }
    rep(i,0,1025) {
        rep(j,0,101) dp[i][j] = -1;
    }
}

ll solve(ll mask, ll id) {
    if(mask == allmask) return 1;
    if(id>100) return 0;
    if(dp[mask][id] != -1) return dp[mask][id];
    ll res=solve(mask, id+1);
    res %= mod;
    ll i;
    // cout<<mask<<" "<<id<<endl;
    rep(i,0,ts[id].size()) {
        if((mask&(1<<ts[id][i])) == 0) {
            res += solve((mask|(1<<ts[id][i])), id+1);
            res %= mod;
        }
    }
    return dp[mask][id] = res;
}


int main() {

    ll t;
    cin>>t;
    while(t--) {
        cin>>n;
        init();
        ll i,j;
        rep(i,0,n) {
            ll id;
            char ch;
            while(scanf("%lld%c", &id, &ch) != -1) {
                ts[id].pb(i);
                // cout<<id<<" "<<ch<<endl;
                if(ch == '\n') break;
            }
        }
        // rep(i,0,101) {
        //     cout<<i<<": ";
        //     rep(j,0,ts[i].size()) cout<<ts[i][j]<<" "; 
        //     cout<<endl;
        // }
        cout<<solve(0,1)<<endl;
    }    

    return 0;
}