// https://www.hackerearth.com/practice/algorithms/sorting/quick-sort/practice-problems/algorithm/noor-and-his-pond-760eabe0/description/

// When pairs are input and sorting is required try to convert into maximum overlapping intervals problems...

#include<bits/stdc++.h>
using namespace std;

#define gc getchar
#define rep(i,j,k) for(i=j; i<k; i++)
#define rrep(i,j,k) for(i=j; i>=k; i--)
#define repmat(i,j,n,m) for(i=0; i<n; i++) for(j=0; j<m; j++)
#define tr(c,it) for(auto it = (c).begin(); it != (c).end(); it++)
#define cinv(v,s,n) ll v_i; rep(v_i,s,n) cin>>v[v_i];
#define coutv(v,s,n) ll v_ii; rep(v_ii,s,n) cout<<v[v_ii]<<" "; cout<<endl;
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
    INOUT;

    ll t=fin;
    while(t--) {
        ll n=fin;
        pii a[n];
        ll i;
        rep(i,0,n) {
            a[i].xx = fin;
            a[i].yy = fin;
        }
        
        map<ll ,ll > mp;
        rep(i,0,n) {
            mp[a[i].yy]++;
            mp[a[i].xx]--;
        }
        
        //tr(mp, it) cout<<it->xx<<" "<<it->yy<<endl;
        
        ll ans=LLONG_MIN;
        ll sm=0;
        tr(mp, it) {
            sm += it->yy;
            ans = max(ans, sm);
        }
        cout<<ans<<endl;
        
    }  
    

    return 0;
}