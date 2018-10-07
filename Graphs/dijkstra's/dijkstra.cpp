
// https://www.spoj.com/problems/EZDIJKST/

#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(i=j;i<k;i++)
#define ll long long
#define N 10011
#define pii pair<ll,ll>
#define xx first
#define yy second
#define pb push_back

ll n,e,s,l,d[N],vis[N];
vector<pii> g[N];

struct comp {
    bool operator() (pii l, pii r) {
        return l.xx < r.xx;
    }   
};

void dijkstra() {
    set<pii, comp> st;
    st.insert({0,s});
    // cout<<s<<l<<endl;
    d[s] = 0;
    while(!st.empty()) {
        pii p = *st.begin();
        st.erase(st.begin());
        ll v = p.yy, vd = p.xx, i;
        if(v == l) break;
        rep(i,0,g[v].size()) {
            ll u = g[v][i].yy;
            ll ud = g[v][i].xx;
            if(d[v] + ud < d[u]) {
                if(st.find({d[u],u}) != st.end()) st.erase(st.find({d[u],u}));
                d[u] = d[v] + ud;
                st.insert({d[u], u});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t;
    cin>>t;
    while(t--) {
        cin>>n>>e;
        ll i;
        rep(i,0,n+1) {
            d[i] = INT_MAX;
            g[i].clear();
            vis[N];
        }
        rep(i,0,e) {
            ll a,b,c;
            cin>>a>>b>>c;
            g[a].pb({c,b});
        }   
        cin>>s>>l;
        dijkstra();
        if(d[l] < INT_MAX) cout<<d[l]<<endl;
        else cout<<"NO"<<endl;
        // rep(i,1,n+1) cout<<d[i]<<" "; cout<<endl<<endl;
    }
    return 0;
}