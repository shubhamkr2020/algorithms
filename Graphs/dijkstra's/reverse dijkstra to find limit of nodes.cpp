// https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/smart-travel-agent/description/
// Solution:

#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(i=j;i<k;i++)
#define pb push_back
#define ll long long
#define pii pair<ll,ll>
#define N 3100
#define xx first
#define yy second

ll n,m,k;
vector<pii> g[N];
ll par[N], s, des, tot, limit[N];
void init() {
    ll i;
    rep(i,0,n+2) {
        g[i].clear();
        par[i] = -1;
        limit[i] = 0;
    }
}

void dijkstra() {
    multiset<pii> st;
    st.insert({INT_MAX,s});
    limit[s] = INT_MAX;
    while(!st.empty()) {
        auto it = st.end();
        it--;
        ll v = it->yy;
        st.erase(it);
        ll i;
        rep(i,0,g[v].size()) {
            pii p = g[v][i];
            ll u = p.yy;
            ll w = p.xx;
            if(limit[u] < min(limit[v],w)) {
                par[u] = v;
                limit[u] = min(limit[v],w);
                st.insert({limit[u], u});
            }
        }
    }
}

int main() {

    cin>>n>>m;
    ll i;
    init();
    rep(i,0,m) {
        ll a,b,w;
        cin>>a>>b>>w;
        g[a].pb({w,b});
        g[b].pb({w,a});
    }

    cin>>s>>des>>tot;
    dijkstra();

    vector<int> path;
    ll temp = par[des];
    path.pb(des);
    while(temp != -1) {
        path.pb(temp);
        temp = par[temp];
    }

    reverse(path.begin(), path.end());
    rep(i,0,path.size()) cout<<path[i]<<" "; cout<<endl;
    ll l = INT_MAX;
    rep(i,0,path.size()) l = min(l, limit[path[i]]);
    cout<<ceil(1.0*tot/(l-1))<<endl;

    return 0;
}