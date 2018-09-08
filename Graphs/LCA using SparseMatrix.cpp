#include<bits/stdc++.h>
using namespace std;

#define gc getchar
#define rep(i,j,k) for(i=j; i<k; i++)
#define rrep(i,j,k) for(i=j; i>=k; i--)
#define repmat(i,j,n,m) for(i=0; i<n; i++) for(j=0; j<m; j++)
#define tr(c,it) for(auto it = (c).begin(); it != (c).end(); it++)
#define cinv(v,s,n) ll v_i; rep(v_i,s,n) cin>>v[v_i];
#define coutv(v,s,n) ll v_i; rep(v_i,s,n) cout<<v[v_i]<<" "; cout<<endl;
#define pb push_back 
#define all(c) (c).begin(),(c).end()
#define fin scan_int()
#define xx first
#define yy second
#define INOUT take_input_and_output_from_file();
#define TIME 1.0*clock()/CLOCKS_PER_SEC
mt19937 genrand(chrono::system_clock::now().time_since_epoch().count());
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
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

#define MAXN 100011
#define level 18

vector <ll > g[MAXN];
ll depth[MAXN];
ll parent[MAXN][level];

void dfs(ll cur, ll prev) {
    depth[cur] = depth[prev] + 1;
    parent[cur][0] = prev;
    for (ll i=0; i<g[cur].size(); i++) {
        if (g[cur][i] != prev)
            dfs(g[cur][i], cur);
    }
}

void precomputeSparseMatrix(ll n) {
    for (ll i=1; i<level; i++) {
        for (ll node = 1; node <= n; node++) {
            if (parent[node][i-1] != -1)
                parent[node][i] =
                    parent[parent[node][i-1]][i-1];
        }
    }
}

ll lca(ll u, ll v) {
    if (depth[v] < depth[u])
        swap(u, v);
 
    ll diff = depth[v] - depth[u];
 
    // Step 1 of the pseudocode
    for (ll i=0; i<level; i++)
        if ((diff>>i)&1)
            v = parent[v][i];
 
    // now depth[u] == depth[v]
    if (u == v)
        return u;
 
    // Step 2 of the pseudocode
    for (ll i=level-1; i>=0; i--)
        if (parent[u][i] != parent[v][i])
        {
            u = parent[u][i];
            v = parent[v][i];
        }
 
    return parent[u][0];
}

int main(){

    ll n=fin, m=fin, q=fin;
    ll i;

    rep(i,0,m) {
        ll a=fin, b=fin, c=fin;
        g[a].pb(b);
        g[b].pb(a);
    }
    
    depth[0]=0;
    dfs(1,0);
    precomputeSparseMatrix(n);

    while(q--) {
        ll p=fin, q=fin;
        cout<<lca(p,q)<<endl;
    }    

    return 0;
}