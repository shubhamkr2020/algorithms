// https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/lucky-string-jackpot-1/description/

// Brute force.......... and the pattern is cullen numbers at odd places.

#include<bits/stdc++.h>
using namespace std;

#define gc getchar
#define rep(i,j,k) for(i=j; i<k; i++)
#define rrep(i,j,k) for(i=j; i>=k; i--)
#define repm(i,j,n,m) for(i=0; i<n; i++) for(j=0; j<m; j++)
#define tr(c,it) for(auto it = (c).begin(); it != (c).end(); it++)
#define ZERO(a) memset(a,0,sizeof(a))
#define lowbit(x) (x&(-x))
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end()
#define fin scan_int()
#define fout(x) fast_out(x)
#define pd(x) printf("%d ",x)
#define newl printf("\n")
#define xx first
#define yy second
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define compress(s) sort(all(s)); s.resize(unique(s.begin(),s.end())-s.begin());
#define strtoint(s,n) if (!(istringstream(s) >> n) ) n = 0;
#define mod 1000000007
typedef long long ll;
typedef vector<ll > vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<string,ll > psi; 
typedef pair<ll ,ll > pii;

string inttostr(ll str){stringstream stream;stream << str;return stream.str();}
ll modexpo(ll a,ll b,ll n){ll d=1;while(b){if(b&1)d=(d*a)%n;b>>=1;a=(a*a)%n;}return d;}
ll expo(ll a,ll b){ll d=1;while(b){if(b&1)d=d*a;b>>=1;a=a*a;}return d;}
inline ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
inline ll lcm(ll a,ll b) {return (a*b)/gcd(a,b);}
ll inv(ll a,ll m){return modexpo(a,m-2,m);}
void parr(ll a[],ll n){ll i;rep(i,0,n)cout<<a[i]<<" ";cout<<endl;}

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

int main() {
    ll t=fin;
    
    vi v;

    vector<string > st;
    st.pb("4");
    st.pb("5");
    int i;
    vector<string > lv;
    lv.pb("4");
    lv.pb("5");
    rep(i,0,15) {
        vs v;
        tr(lv, it) {
            string x = "4"+(*it);
            v.pb(x);
        }
        tr(lv, it) {
            string x = "5"+(*it);
            v.pb(x);
        }
        tr(v, it) st.pb(*it);
        lv = v;
    }

    string s=" ";
    tr(st, it) s += (*it);
    cout<<s.length()<<endl;

    int dp[11111] = {0};
    int cur=0;
    dp[1] = 1;
    rep(i,2,2222) {
        if(s[i] == '4')
            dp[i] = max(dp[i-1], ++cur);
        else {
            dp[i] = dp[i-1];
            cur=0;
        }
    }
    //rep(i,0,2222) cout<<dp[i]<<" "; cout<<endl;
    int c[111111]={0};
    rep(i,0,2222) c[dp[i]]++;
    rep(i,0,25) cout<<c[i]<<" "; cout<<endl;
    while(t--) {
        ll n=fin;


    }

    return 0;
}