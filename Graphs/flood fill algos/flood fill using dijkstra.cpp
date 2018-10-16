
// https://www.hackerearth.com/practice/algorithms/graphs/flood-fill-algorithm/tutorial/

// Solution for sample problem (flood fill using dijkstra's algo):

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
#define inf 111111

void dijkstra() {
    set<pair<int,pii> > st;
    st.insert({0,{0,0}});
    vis[0][0]=0;
    while(!st.empty()) {
        auto it = st.begin();
        st.erase(it);
        int u=it->yy.xx, v=it->yy.yy, d=it->xx, i;
        rep(i,0,4) {
            int x = mv[i].xx+u;
            int y = mv[i].yy+v;
            if(x<0 || y<0 || x>=n || y>=m || a[x][y]==0) continue;
            if(vis[x][y] > d+1) {
                auto z = st.find({vis[x][y],{x,y}});
                if(z!=st.end()) st.erase({vis[x][y],{x,y}});
                vis[x][y] = d+1;
                st.insert({d+1,{x,y}});
            }
        }
    }
}

int main(){
    cin>>n>>m;
    int i,j;
    rep(i,0,n) rep(j,0,m) cin>>a[i][j];
    rep(i,0,n+1) rep(j,0,m+1) vis[i][j] = inf;
    
    dijkstra();
    // rep(i,0,n) {rep(j,0,m) cout<<vis[i][j]<<" "; cout<<endl;}
    if(vis[n-1][m-1] < inf) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
    return 0;
}