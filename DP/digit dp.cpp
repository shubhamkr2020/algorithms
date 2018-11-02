
// Objective - It is used to solve problems for counting number of numbers between l and r with certain properties.

// https://discuss.codechef.com/questions/83102/workchef-unofficial-editorial  -------  good one

// https://tasnimsprogramming.wordpress.com/2017/07/26/digit-dp-tutorial/

// https://www.hackerrank.com/topics/digit-dp

// https://codeforces.com/blog/entry/53960

// https://www.geeksforgeeks.org/digit-dp-introduction/

// Questions

// 1. https://www.hackerearth.com/problem/algorithm/sum-of-digits-8/description/
// 2. http://codeforces.com/contest/1036/problem/C



// http://codeforces.com/contest/1036/problem/C
// can be solved by permutation also

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

// const ll maxn = 20;                                // correctt answer with recursion also
// ll a[maxn];
// long long dp[maxn][2][2][5];

// long long calc(ll pos, ll fa, ll fz, ll cn) {
//     if (pos == maxn) return fz;
//     long long& res = dp[pos][fa][fz][cn];
//     if (~res) return res; 
//     res = 0;
//     ll hi = 9, i;
//     if (!fa) hi = a[pos];
//     rep(i, 0, hi + 1) {
//         ll nfa = fa | (i < a[pos]);
//         ll nfz = fz | (i > 0);
//         ll ncn = cn + (i > 0);
//         if (ncn <= 3) {
//             res += calc(pos + 1, nfa, nfz, ncn);
//         }
//     }
//     return dp[pos][fa][fz][cn] = res;
// }

// long long solve(long long n) {
//     ll i;
//     rep(i, 0, maxn) {
//         a[maxn - i - 1] = n % 10;
//         n /= 10;
//     }
//     memset(dp, -1, sizeof dp);
//     return calc(0, 0, 0, 0);
// }


ll a, b, s;
ll POW10[20];
ll dp[20][5];
// ll min_solution = -1;

ll solve(ll prefix, ll digits, ll sum ) {
   if( sum < 0 ) return 0;
   ll mini = prefix;
   ll maxi = prefix + POW10[digits]-1;
   // cout<<mini<<" "<<maxi<<endl;
   if( mini > b || maxi < a ) return 0;
   if( digits == 0 ) {
      if( sum > 0 ) return 1;      
      // if( min_solution == -1 ) min_solution = prefix;              // min correct solution can be found
      return 1;
   }
   bool memoize = (mini >= a && maxi <= b);
   if( memoize && dp[digits][sum] != -1 ) return dp[digits][sum];
   ll ret = 0;
   for( ll dig = 0; dig < 10; ++dig ) 
      ret += solve( prefix + dig*POW10[digits-1], digits-1, sum-(dig==0 ? 0:1) ); // change here for every question  
   if( memoize ) dp[digits][sum] = ret;
   return ret;
}

int main(){

    ll t=fin;
    while(t--) {
        a=fin;
        b=fin;
        ll f=0;
        if(a == ll(1e18)) {                     // cannot make 19 digit number
            cout<<1<<endl;
            continue;
        }
        else if(b == ll(1e18)) {
            f=1;
            b--;
        }
        s=3;
        ll i;
        POW10[0]=1;
        rep(i,1,20) POW10[i] = POW10[i-1]*10;
        memset(dp, -1, sizeof dp);

        cout<<solve(0,18,s)+f<<endl;
        // cout<<min_solution<<endl;
    }
    return 0;
}