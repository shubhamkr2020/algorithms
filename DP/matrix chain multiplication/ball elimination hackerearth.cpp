// https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/ball-elimination/description/
// Solution:

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

int n, a[555];
int dp[555][555];

int solve(int l, int r) {
    if(l>r) return 0;
    int &ret = dp[l][r];
    if(ret!=-1) return ret;
    if(l == r) return ret = 1;
    if(l+1 == r && a[l] == a[r]) return ret = 0;
    int k, mn=INT_MAX, f=0;
    rep(k,l+1,r+1) {
        if(a[l] == a[k]) mn = min(mn, solve(l+1,k-1)+solve(k+1,r));
        else mn = min(mn, 1+solve(l+1,k)+solve(k+1,r));
    }
    return ret = mn;
}

int main() {
    cin>>n;
    int i;
    rep(i,0,n) cin>>a[i];
    memset(dp, -1, sizeof dp);
    cout<<solve(0, n-1)<<endl;
    int j;
    // rep(i,0,n) {rep(j,0,n) cout<<dp[i][j]<<" "; cout<<endl;}
    return 0;
}