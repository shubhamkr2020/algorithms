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


int main(){
    //INOUT;

    int n=fin;
    pii pp[n];
    int i;
    rep(i,0,n-1) {
        int a=fin, b=fin;
        pp[i] = {a,b};
    }
    int a[n];
    rep(i,0,n) a[i]=fin;
    int ind[n+1];
    rep(i,0,n) ind[a[i]] = i;

    vector<pii > gg[n+1];

    rep(i,0,n) {
        int a = pp[i].xx;
        int b = pp[i].yy;
        gg[a].pb({ind[b],b});
        gg[b].pb({ind[a],a});
    }

    rep(i,0,n+1) sort(all(gg[i]));
    // rep(i,0,n+1) cout<<gg[i].size()<<endl;

    vi g[n+1];
    rep(i,1,n+1) {
        int j;
        rep(j,0,gg[i].size()) g[i].pb(gg[i][j].yy);
    }
    // rep(i,1,n+1) { int j; rep(j,0,g[i].size()) cout<<g[i][j]<<" "; cout<<endl; }

    if(a[0] != 1) {
        cout<<"NO"<<endl;
        return 0;
    }

    queue<int > q;
    q.push(1);
    int k=1;
    int vis[n+1] = {0};
    vis[1] = 1;
    // cout<<1<<" ";
    while(!q.empty()) {
        int ff = q.front();
        q.pop();
        rep(i,0,g[ff].size()) {
            int f = g[ff][i];
            if(!vis[f]) {
                vis[f] = 1;
                q.push(f);
                // cout<<f<<" ";
                if(a[k] != f) {
                    cout<<"NO"<<endl;
                    return 0;
                }
                k++;
            }
        }
    }
    cout<<"YES"<<endl;

    return 0;
}