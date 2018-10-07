// WALMART coding round....

#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(i=j;i<k;i++)
#define ll long long
#define N 1500011
#define pii pair<ll,ll>
#define xx first
#define yy second

ll d[N],a,b,x;

void dijkstra() {
    set<pii> st;
    st.insert({0,0});
    d[0] = 0;
    while(!st.empty()) {
        auto it = st.begin();
        st.erase(it);
        ll v = it->yy, vd = it->xx;
        ll u = v+1;
        ll ud = vd + a;
        if(u<N && ud<d[u]) {
            if(st.find({d[u], u}) != st.end()) st.erase(st.find({d[u], u}));
            d[u] = ud;
            st.insert({d[u], u});
        }
        u = v-1;
        ud = vd + a;
        if(u>0 && ud<d[u]) {
            if(st.find({d[u], u}) != st.end()) st.erase(st.find({d[u], u}));
            d[u] = ud;
            st.insert({d[u], u});
        }
        u = 2*v;
        ud = vd + b;
        if(u<N && ud<d[u]) {
            if(st.find({d[u], u}) != st.end()) st.erase(st.find({d[u], u}));
            d[u] = ud;
            st.insert({d[u], u});
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t;
    cin>>t;
    int i;
    cin>>a>>b;
    rep(i,0,N) d[i] = INT_MAX;
    dijkstra();
    while(t--) {
        cin>>x;
        cout<<d[x]<<endl;
    }
    
    return 0;
}