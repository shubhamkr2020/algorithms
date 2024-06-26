
// https://codeforces.com/contest/1070/problem/A
// Solution:

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
#define N 5555
ll d,s;
vector<string> v;
queue<pii> Q;
int sumTrace[N][N], mulTrace[N][N];

void print(int sum, int mul) {
    if (sumTrace[sum][mul] == 42) return;
    print(sum-sumTrace[sum][mul], mulTrace[sum][mul]);
    printf("%d",sumTrace[sum][mul]);
}

void solve() {   
    Q.push({0,0});
    ll k=0;
    ll f=0;
    sumTrace[0][0]=42;
    while(1) {
        int sum = Q.front().xx;
        int mul = Q.front().yy;
        if (sum==s && mul==0) {
            f=1;
            break;
        }
        // cout<<sum<<" "<<mul<<endl;
        Q.pop();
        for (int i=0; i<10; i++) {
            int nsum = sum+i;
            if (nsum > s) break;
            int nmul = (mul*10+i)%d;
            if(nsum<0 || nmul<0 || nsum>N || nmul > 5555) break;
            if (sumTrace[nsum][nmul] == -1) {
                Q.push({nsum, nmul});
                sumTrace[nsum][nmul] = i;
                mulTrace[nsum][nmul] = mul;
            }
        }
        if(Q.size() > 10000000) break;
    }
    if(!f) cout<<-1<<endl;
    else print(s,0);
    cout<<endl;
}

int main() {
    d=fin;
    s=fin;
    ll i;
    memset(sumTrace, -1, sizeof sumTrace);
    solve();
    return 0;
}