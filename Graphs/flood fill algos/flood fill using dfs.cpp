
// https://www.hackerearth.com/practice/algorithms/graphs/flood-fill-algorithm/tutorial/

// Solution for sample problem (flood fill using dfs):

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

void dfs(int x,int y) {
    if(x<0 || y<0 || x>=n || y>=m) return ;
    if(vis[x][y] == true) return;
    if(a[x][y] == 0) return;
    vis[x][y] = true;
    int i,j;
    rep(i,0,4) {
        int a = x+mv[i].xx, b = y+mv[i].yy;
        dfs(a,b);
    }
}

int main(){
    cin>>n>>m;
    int i,j;
    rep(i,0,n) rep(j,0,m) cin>>a[i][j];
    rep(i,0,n+1) rep(j,0,m+1) vis[i][j] = false;
    
    dfs(0,0);
    if(vis[n-1][m-1] == true) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
    return 0;
}