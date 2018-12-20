// https://www.geeksforgeeks.org/check-graphs-cycle-odd-length/

// if a graph is bipartite (colorable with two colors) then there is no odd cycle in the graph.
// check bipartite using two coloring method.

// question - https://codeforces.com/contest/1093/problem/D

// solution:

#include<bits/stdc++.h>
using namespace std;

#define gc getchar
#define rep(i,j,k) for(i=j; i<k; i++)
#define rrep(i,j,k) for(i=j; i>=k; i--)
#define tr(c,it) for(auto it = (c).begin(); it != (c).end(); it++)
#define pb push_back 
#define all(c) (c).begin(),(c).end()
#define fin scan_int()
#define xx first
#define yy second
#define INOUT take_input_and_output_from_file();
#define TIME 1.0*clock()/CLOCKS_PER_SEC
mt19937 genrand(chrono::system_clock::now().time_since_epoch().count());
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 998244353
typedef long long ll;
typedef vector<ll > vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<string,ll > psi; 
typedef pair<ll ,ll > pii;

#define strtoint(s,n) if (!(istringstream(s) >> n) ) n = 0;
string inttostr(ll str){stringstream stream; stream << str; return stream.str();}
string numtobin(ll n) {string r = "";while(n) r = ((n&1) ? '1' : '0') + r, n >>= 1;return r;}
ll bintonum(string s) {ll n=0, p=1<<(s.length()-1);for(char i : s) n += (i-'0')*p, p>>=1;return n;}
ll modexpo(ll a,ll b,ll n){ll d=1;while(b){if(b&1)d=(d*a)%n;b>>=1;a=(a*a)%n;}return d;}
ll expo(ll a,ll b){ll d=1;while(b){if(b&1)d=d*a;b>>=1;a=a*a;}return d;}
inline ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
inline ll lcm(ll a, ll b) {return (a*b)/gcd(a,b);}
ll inv(ll a,ll m) {return modexpo(a,m-2,m);}
void take_input_and_output_from_file() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
inline ll scan_int() {
    ll NR=0,sign=1;
    char c=gc();
    while( c < 48 || c > 57 ) {
        if(c=='-') sign=0;
        c=gc();
    }
    while(c>47 && c< 58) {
        NR = (NR << 3) + (NR << 1) + (c - 48);
        c=gc();
    }
    return (sign?NR:(-NR));
}

////////////////////////////////////////////////////////////////////////////////////////////

#define N 400001

vi g[N];
ll vis[N], col[N], c[2];
ll n,m;

void color(ll v) {
    vis[v] = 1;
    for(ll u:g[v]) {
        if(!vis[u]) {
            col[u] = 1-col[v];
            color(u);
        }
    }
}

bool check(ll v) {
    for(ll u:g[v]) {
        if(col[v] == col[u]) return false;
    }
    return true;
}

bool checkbp() {
    ll i;
    rep(i,1,n+1) {
        if(!check(i)) return false;
    }
    return true;
}

void dfs(int v) {
    vis[v] = 1;
    c[col[v]]++;
    for(int u:g[v]) {
        if(!vis[u]) {
            dfs(u);
        }
    }
}


int main(){

    ll t=fin;
    while(t--) {
        n=fin;
        m=fin;
        ll i;
        rep(i,0,n+1) g[i].clear();
        rep(i,0,n+1) vis[i] = 0;
        rep(i,0,n+1) col[i] = -1;

        while(m--) {
            ll a=fin, b=fin;
            g[a].pb(b);
            g[b].pb(a);
        }

        rep(i,1,n+1) {
            if(!vis[i]) {
                col[i] = 0;
                color(i);
            }
        }

        // rep(i,0,n+1) cout<<col[i]<<" "; cout<<endl;

        if(!checkbp()) cout<<"0"<<endl;
        else {
            ll ans=1ll;
            rep(i,0,n+1) vis[i] = 0;
            rep(i,1,n+1) {
                if(g[i].size() == 0) ans = (ans*3)%mod;
                else if(!vis[i]) {
                    c[0] = 0;
                    c[1] = 0;
                    dfs(i);
                    ans = (ans*(modexpo(2,c[0],mod)+modexpo(2,c[1],mod))%mod)%mod;
                }
            }
            cout<<ans<<endl;
        }
    }

    return 0;
}