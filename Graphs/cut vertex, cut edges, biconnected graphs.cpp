
// Conditions for a node (v) to be an articulation point(any one):
// 1. if v is a root than there should be two children in its dfs tree
// 2. otherwise there should be an adjacent vertex (u) such that:
//      low[u] >= disc[v] 
// (basically only one condition children should not be connected with any ancestor)
// (here low time is the lowest time of visiting the nodes in the subtree rooted at u)

// For cut edges (edge between v and u):
// low[u] > disc[v]  ---  only one condition i.e. children is not connected with any ancestors

// A graph is said to be Biconnected if:
// 1. It is connected, i.e. it is possible to reach every vertex from every other vertex, by a simple path.
// 2. Even after removing any vertex the graph remains connected.

// https://www.spoj.com/problems/SUBMERGE/

// Solution:
#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(i=j;i<k;i++)
#define ll long long
#define vi vector<ll >
#define pb push_back
#define N 1100000

// variables .........
vi g[N];
ll disc[N];                    // discovery time of ith vertex
ll low[N];                     // minimum disc time for any vertex in tree rooted at i
ll t;                          // time variable
ll arc[N];                     // ith vertex is articulation poll or not
ll par[N];                     // parent vertex of ith vertex
ll vis[N];                     // visited array
ll n,m;

void init(int n) {
    int i;
    t=0;
    rep(i,0,n+2) {
        g[i].clear();
        vis[i]=0;
        disc[i] = -1;
        arc[i]=0;
        low[i]=INT_MAX;
        par[i] = -1;
    }
}

void dfs(ll v) {
    t++;
    disc[v] = t;                                        // discovery time
    low[v] = t;                                         // initial low timw
    vis[v] = 1;                                         // mark visisted
    int child=0;                                        // number of children in dfs tree
    for(int ch: g[v]) {
        if(!vis[ch]) {
            child++;
            par[ch] = v;                                // find the parent
            dfs(ch);

            low[v] = min(low[v], low[ch]);          // update the low by comparing with low of adjacent vertex

            if(par[v] == -1 && child>1) arc[v] = 1;                 // 1st condition
            if(par[v] != -1 && low[ch] >= disc[v]) arc[v] = 1;      // 2nd condition
        }
        else if(ch!=par[v])                     // if adjacent is not visited then update low only if it is not parent
            low[v] = min(low[v], disc[ch]);
    }
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    while(1) {
        cin>>n>>m;
        if(n==0 && m==0) break;
        
        init(n);
        int i;
        rep(i,0,m) {
            int a,b;
            cin>>a>>b;
            g[a].pb(b);
            g[b].pb(a);
        }
        
        rep(i,1,n+1) {
            if(!vis[i])
            dfs(i);
        }
        
        ll c=0;
        rep(i,1,n+1) {
            if(arc[i])
            c++;
            //if(ap[i]) cout<<i<<" ";
        }
        
        cout<<c<<endl;
        
    }
    
    return 0;
}