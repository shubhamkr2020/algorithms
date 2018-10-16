// https://www.hackerearth.com/practice/algorithms/graphs/flood-fill-algorithm/tutorial/

// Solution for sample problem (flood fill using bfs):

#include<bits/stdc++.h>
using namespace std;

#define rep(i,j,k) for(i=j; i<k; i++)
#define pb push_back 
#define xx first
#define yy second
typedef long long ll;
typedef vector<ll > vi;
typedef pair<ll ,ll > pii;

#define N 1100
int a[N][N], n, m;
bool vis[N][N];
pii mv[4] = {{-1,0},{0,-1},{1,0},{0,1}};

void bfs() {
    queue<pii> q;
    q.push({0,0});
    vis[0][0] = 1;
    while(!q.empty()) {
        pii p = q.front();
        q.pop();
        int i;
        rep(i,0,4) {
            int x = mv[i].xx+p.xx;
            int y = mv[i].yy+p.yy;
            if(x<0 || y<0 || x>=n || y>=m || a[x][y]==0) continue ;
            if(!vis[x][y]) {
                vis[x][y] = 1;
                q.push({x,y});
            }
        }
    }
}

int main(){
    cin>>n>>m;
    int i,j;
    rep(i,0,n) rep(j,0,m) cin>>a[i][j];
    rep(i,0,n+1) rep(j,0,m+1) vis[i][j] = false;
    
    bfs();
    // rep(i,0,n) {rep(j,0,m) cout<<vis[i][j]<<" "; cout<<endl;}
    if(vis[n-1][m-1] == true) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
    return 0;
}