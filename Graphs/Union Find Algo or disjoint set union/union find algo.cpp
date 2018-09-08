
// www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/permutation-swaps

#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define rep(i,j,k) for(i=j; i<k; i++)
#define rrep(i,j,k) for(i=j; i>=k; i--)
#define repm(i,j,n,m) for(i=0; i<n; i++) for(j=0; j<m; j++)
#define tr(c,it) for(auto it = (c).begin(); it != (c).end(); it++)
#define pb push_back 
#define all(c) (c).begin(),(c).end()
#define fin scan_int()
#define newl printf("\n")
#define xx first
#define yy second
#define mod 1000000007
#define dbg(a) cerr << #a << endl;
#define dbgv(vari) cerr << #vari<< " = "<< (vari) <<endl;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define compress(s) sort(all(s)); s.resize(unique(s.begin(),s.end())-s.begin());
#define strtoint(s,n) if (!(istringstream(s) >> n) ) n = 0;
typedef long long ll;
typedef vector<int > vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<string,int > psi; 
typedef pair<int ,int > pii;
string inttostr(int str){stringstream stream;stream << str;return stream.str();}
ll modexpo(ll a,ll b,ll n){ll d=1;while(b){if(b&1)d=(d*a)%n;b>>=1;a=(a*a)%n;}return d;}
ll expo(ll a,ll b){ll d=1;while(b){if(b&1)d=d*a;b>>1;a=a*a;}return d;}
inline ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
inline ll lcm(ll a,ll b) {return (a*b)/gcd(a,b);}
ll inv(ll a,ll m){return modexpo(a,m-2,m);}
inline int scan_int() {
   int NR=0,sign=1;    char c=gc();
    while( c < 48 || c > 57 ){if(c=='-')sign=0; c=gc();}
    while(c>47 && c< 58) {
        NR = (NR << 3) + (NR << 1) + (c - 48);
        c=gc();
    }
    return (sign?NR:(-NR));
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
int p[1111111], sze[1111111];
 
 // Do not forget to init(n);
void init(int n) {
    int i;
    rep(i,0,n+1) {
        sze[i] = 1;
        p[i] = i;
    }
}
 
int root(int x) {                       // there may be path compression by using
    while(p[x] != x)                    // p[x]=p[p[x]]
    x = p[x];                           // x = p[x]
    return x;                           // O(log*n) - maximum value 5 in real world......
}
 
void Union(int a, int b) {              // weighted Union of a and b...........
    int ra = root(a);
    int rb = root(b);
    if(ra == rb) return;
    if(sze[ra] < sze[rb]) {
        p[ra] = rb;
        sze[rb] += sze[ra];
    }
    else {
        p[rb] = ra;
        sze[ra] += sze[rb];
    }
}
 
bool Find(int a, int b) {                // returns true if a and b are connected....
    int ra = root(a);
    int rb = root(b);
    if(ra == rb) return true;
    return false;
}
 
 
int main() {
    int t=fin;
    while(t--) {
        int n=fin, m=fin;
        init(n);
        int a[n], b[n], i;
        rep(i,0,n) a[i]=fin;
        rep(i,0,n) b[i]=fin;
        while(m--) {
            int x=fin, y=fin;
            x--;
            y--;
            Union(a[x],a[y]);
        }
        //rep(i,0,n+1) cout<<p[i]<<" ";cout<<endl;
        
        int f=0;
        rep(i,0,n) {
            if(!Find(a[i], b[i])) {
                //cout<<i<<" ";
                cout<<"NO"<<endl;
                f=1;
                break;
            }
        }
        if(!f)
            cout<<"YES"<<endl;
 
    }
 
    return 0;
}