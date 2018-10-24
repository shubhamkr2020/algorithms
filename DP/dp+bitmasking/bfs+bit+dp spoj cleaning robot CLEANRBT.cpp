// https://www.spoj.com/problems/CLEANRBT/
// Solution:

#include<bits/stdc++.h>
using namespace std;

#define rep(i,j,k) for(i=j;i<k;i++)
#define ll long long
#define pii pair<int,int>
#define xx first
#define yy second
#define N 25

string a[N];
ll n,m,si,sj,c;
ll dp[(1<<12)][N][N];
ll allmask;
pii mv[4] = {{0,-1},{-1,0},{0,1},{1,0}};

bool check(int i, int j) {
    if(i>=0 && j>=0 && i<n && j<m && a[i][j] != 'x') return true;
    return false;
}

ll bfs() {
    ll vm, mi = INT_MAX, vi, vj, i, ui, uj, um;
    queue<ll> q;
    q.push(si);
    q.push(sj);
    q.push(0);
    dp[0][si][sj] = 0;
    while(!q.empty()) {
        vi = q.front(); q.pop();
        vj = q.front(); q.pop();
        vm = q.front(); q.pop();
        rep(i,0,4) {
            ui = vi+mv[i].xx;
            uj = vj+mv[i].yy;
            um = vm;
            if(check(ui,uj)) {
                if(isupper(a[ui][uj])) um |= (1<<(a[ui][uj]-'A'));
                if(dp[um][ui][uj] > dp[vm][vi][vj]+1) {
                    dp[um][ui][uj] = dp[vm][vi][vj]+1;
                    if(um == allmask) {
                        mi=min(mi, dp[um][ui][uj]);
                        // cout<<mi<<endl;
                    }
                    q.push(ui);
                    q.push(uj);
                    q.push(um);
                }
            }
        }
    }
    return mi;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1) {
        cin>>m>>n;
        if(!(n+m)) break;
        ll i,j;
        c=0;
        rep(i,0,n) cin>>a[i];
        rep(i,0,n) {
            rep(j,0,m) {
                if(a[i][j] == 'o') {
                    si=i;
                    sj=j;
                }
                else if(a[i][j] == '*') 
                    a[i][j] = c++ + 'A';
            }
        }
        // rep(i,0,n)  {
        //     rep(j,0,m) cout<<a[i][j]<<" "; cout<<endl;
        // }
        ll k;
        allmask = (1<<c)-1;
        // cout<<allmask<<endl;
        rep(k,0,(1<<c)) {
            rep(i,0,n+1) {
                rep(j,0,m+1) 
                dp[k][i][j] = INT_MAX;
            }
        }
        ll ans = bfs();
        if(ans < INT_MAX) cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}