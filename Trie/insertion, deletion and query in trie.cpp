
// https://codeforces.com/contest/706/problem/D
// if xor question - try solving using trie.............

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

int tr[3010000][2];
int cnt[3010000];
int sz=1;

void insert(int n) {
    int i, p=0;
    for(i=29; i>=0; i--) {
        int x = ((n>>i)&1);
        if(!tr[p][x])
            tr[p][x] = sz++;
        p = tr[p][x];
        cnt[p]++;
    }
}

void del(int n) {
    int i, p=0;
    for(i=29; i>=0; i--) {
        int x = ((n>>i)&1);
        p=tr[p][x];
        cnt[p]--;
    }
}

int ans(int n) {
    int i, r=0, p=0;
    for(i=29; i>=0; i--) {
        int x = ((n>>i)&1);
        if(x==0) {
            if(tr[p][1] && cnt[tr[p][1]]) {
                r += (1<<i);
                p = tr[p][1];
            }
            else if(tr[p][0] && cnt[tr[p][0]]) {
                p = tr[p][0];
            }
        }
        else {
            if(tr[p][0] && cnt[tr[p][0]]) {
                p = tr[p][0];
            }
            else if(tr[p][1] && cnt[tr[p][1]]){
                r += (1<<i);
                p = tr[p][1];
            }
        }
    }
    return r;
}

int main(){

    int t=fin;
    insert(0);
    while(t--) {
        char ch;
        cin>>ch;
        int x = fin;
        if(ch == '+') insert(x);
        else if(ch == '-') del(x);
        else cout<<(ans(x)^x)<<endl;

    }
    // int i,j; rep(i,0,100) cout<<cnt[i]<<endl; cout<<endl;
    return 0;
}