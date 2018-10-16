
// https://codeforces.com/contest/1064/problem/D

// can be solved using 0-1 bfs also because edge weight can only be 0(for top and bottom) or 1(for left and right)

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
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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


char a[2111][2111];

bool check(int i, int j, int n, int m) {
    if(i>=1 && j>=1 && i<=n && j<=m && a[i][j]!='*') return true;
    return false;
}

#define inf LLONG_MAX/10000000

int main(){

    ll n=fin, m=fin;
    ll i,j;
    ll si=fin, sj=fin;
    ll x=fin, y=fin;
    rep(i,0,n) {
        string s;
        cin>>s;
        rep(j,1,m+1) a[i+1][j] = s[j-1];
    }
    // rep(i,1,n+1) {rep(j,1,m+1) cout<<a[i][j]<<" "; cout<<endl;}

    ll dpl[n+2][m+2], dpr[n+2][m+2];

    rep(i,0,n+1) rep(j,0,m+1) dpl[i][j] = inf, dpr[i][j] = inf;

    dpl[si][sj] = 0;
    dpr[si][sj] = 0;
    // rep(i,1,n+1) {rep(j,1,m+1) cout<<dpl[i][j]<<" "; cout<<endl;}

    queue<pii> q;
    q.push({si,sj});
    int vis[n+1][m+1];
    rep(i,0,n+1) rep(j,0,m+1) vis[i][j] = 0;
    vis[si][sj] = 1;
    while(!q.empty()) {
        pii p = q.front();
        q.pop();
        ll xi=p.xx, yi=p.yy;
        if(check(xi,yi-1,n,m)) {
            if(dpl[xi][yi]+1 < dpl[xi][yi-1] ) {
                dpl[xi][yi-1] = dpl[xi][yi]+1;
                q.push({xi, yi-1});    
            }
            if(dpr[xi][yi-1] > dpr[xi][yi]) {
                dpr[xi][yi-1] = dpr[xi][yi];
                q.push({xi, yi-1});
            }
        }

        if(check(xi,yi+1,n,m)) {
            if(dpl[xi][yi+1] > dpl[xi][yi]) {
                dpl[xi][yi+1] = dpl[xi][yi];
                q.push({xi, yi+1});
            }
            if(dpr[xi][yi]+1 < dpr[xi][yi+1]) {
                dpr[xi][yi+1] = dpr[xi][yi]+1;
                q.push({xi, yi+1});
            }
        }

        if(check(xi-1,yi,n,m)) {
            if(dpl[xi-1][yi] > dpl[xi][yi]) {
                dpl[xi-1][yi] = dpl[xi][yi];
                q.push({xi-1, yi});
            }
            if(dpr[xi-1][yi] > dpr[xi][yi]) {
                dpr[xi-1][yi] = min(dpr[xi-1][yi], dpr[xi][yi]);
                q.push({xi-1, yi});
            }
        }

        if(check(xi+1,yi,n,m)) {
            if(dpl[xi+1][yi] > dpl[xi][yi]) {
                dpl[xi+1][yi] = dpl[xi][yi];
                q.push({xi+1, yi});
            }
            if(dpr[xi+1][yi] > dpr[xi][yi]) {
                dpr[xi+1][yi] = dpr[xi][yi];
                q.push({xi+1, yi});
            }
        }
    }

    // rep(i,1,n+1) {rep(j,1,m+1) cout<<dpl[i][j]<<" "; cout<<endl;} cout<<endl;
    // rep(i,1,n+1) {rep(j,1,m+1) cout<<dpr[i][j]<<" "; cout<<endl;}

    ll c=0;
    rep(i,1,n+1) rep(j,1,m+1) {
        if(dpl[i][j] <= x && dpr[i][j] <= y) c++;
    }

    cout<<c<<endl;

    return 0;
}