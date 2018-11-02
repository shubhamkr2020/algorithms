// https://kartikkukreja.wordpress.com/2013/12/02/range-updates-with-bit-fenwick-tree/#more-420

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

ll n;
void update(ll bit[], ll p, ll val) {
    for(p; p<=n; p+=p&(-p))
        bit[p] += val;
}

void rupdate(ll b1[], ll b2[], ll l, ll r, ll val) {
    update(b1, l, val);
    update(b1, r+1, -val);
    update(b2, l, val*(l-1));
    update(b2, r+1, -val*r);
}

ll query(ll bit[], ll p) {
    ll ret=0;
    for(p; p>0; p -= p&(-p))
        ret += bit[p];
    return ret;
}

ll query(ll b1[], ll b2[], ll p) {
    return query(b1,p)*p - query(b2,p);
}

ll rquery(ll b1[], ll b2[], ll l, ll r) {
    return query(b1,b2,r)-  query(b1,b2,l-1);
}

int main() {
    
    ll t=fin;
    while(t--) {
        n=fin;
        ll u=fin;
        ll i;
        ll b1[n+1] = {0};
        ll b2[n+1] = {0};
        rep(i,0,u) {
            ll l=fin, r=fin, v=fin;
            l++;
            r++;
            rupdate(b1,b2,l,r,v);
        }
        ll q=fin;
        while(q--) {
            ll idx=fin;
            idx++;
            cout<<rquery(b1,b2,idx,idx)<<endl;
        }
    }
    
    return 0;
}