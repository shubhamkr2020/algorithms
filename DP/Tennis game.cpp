// https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/help-raj-play-table-tennis/
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
#define mod 1000000009
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

ll dp[35][35];
ll x1,y,x2,y2;

ll solve(ll a, ll b) {

    if(a==x1 && b==y) return 1;
    if(a<x1 || b<y || a<0 || b<0) return 0;
    ll &r = dp[a][b];
    if(r != -1) return r;
    if(a<11 && b<11) {
        return r = (solve(a-1,b) + solve(a,b-1))%mod;
    }
    else if(a<11 && b>=11) {
        return r = solve(a,10);
    }
    else if(a>=11 && b<11) {
        return r = solve(10,b);
    }
    else if(a>=11 && b>=11) {
        if(a==b) return r = (solve(a-1,b)+solve(a,b-1))%mod;
        if(a+1==b || b+1==a) return r = solve(min(a,b), min(a,b));
        if(a+2==b) return r = solve(a,b-1);
        if(b+2==a) return r = solve(a-1,b);
    }
}

int main(){

    ll t=fin,q;
    rep(q,1,t+1) {
        cout<<"Case "<<q<<": ";
        cin>>x1>>y>>x2>>y2;
        if((x2<11 && y2<11) || ((x2>=11 || y2>=11) && abs(x2-y2)!=2) || ((x1>=11 || y>=11) && abs(x1-y)>1) || x2<x1 || y2<y) {
            cout<<"-1"<<endl;
            continue;
        }
        memset(dp, -1, sizeof dp);
        cout<<(solve(x2, y2)+mod)%mod<<endl;
    }

    return 0;
}