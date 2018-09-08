
// https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/prison-break-5/


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
#define sc(x) scanf("%d",&x)
#define sc2(x,y) scanf("%d%d",&x,&y)
#define sc3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define scl(x) scanf("%lld",&x)
#define scl2(x,y) scanf("%lld%lld",&x,&y)
#define scl3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define scstr(x) scanf("%s",x)
#define pd(x) printf("%d ",x)
#define pd2(x,y) printf("%d %d",x,y)
#define pll(x) printf("%lld",x)
#define pll2(x,y) printf("%lld %lld",x,y)
#define pstr(x) printf("%s",x)
#define newl printf("\n")
#define xx first
#define yy second
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define compress(s) sort(all(s)); s.resize(unique(s.begin(),s.end())-s.begin());
#define strtoint(s,n) if (!(istringstream(s) >> n) ) n = 0;
#define mod 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<string,int> psi; 
typedef pair<int,int> pii;

string inttostr(int str){stringstream stream;stream << str;return stream.str();}
ll modexpo(ll a,ll b,ll n){ll d=1;while(b){if(b&1)d=(d*a)%n;b>>=1;a=(a*a)%n;}return d;}
ll expo(ll a,ll b){ll d=1;while(b){if(b&1)d=d*a;b>>=1;a=a*a;}return d;}
inline ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
inline ll lcm(ll a,ll b) {return (a*b)/gcd(a,b);}
ll inv(ll a,ll m){return modexpo(a,m-2,m);}
void parr(int a[],int n){int i;rep(i,0,n)cout<<a[i]<<" ";cout<<endl;}

inline int scan_int() {
    int NR=0,sign=1;
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

int a[21][21], n, vis[21][21], ans;
pii mv[] = {{-1,0}, {0,-1}, {1,0}, {0,1}};

bool ok(int i, int j) {
    if(i>=0 && j>=0 && i<n && j<n)
        return true;
    return false;
}

void dfs(int i, int j) {
    if(i==n-1 && j==n-1) {
        ans++;
        return;
    }

    vis[i][j] = 1;
    int k;
    rep(k,0,4) {
        int x=i+mv[k].xx, y=j+mv[k].yy;
        if(ok(x,y) && !vis[x][y] && a[x][y] == 0)
        dfs(x,y);
    }
    vis[i][j] = 0;
}

int main(){

    int t=fin;
    while(t--) {
        n=fin;
        ans=0;
        int i,j;
        rep(i,0,n) rep(j,0,n) a[i][j] = fin;
        rep(i,0,n) rep(j,0,n) vis[i][j]=0;

        //cout<<ans<<" ";

        if(a[n-1][n-1] == 1) {
            cout<<0<<endl;
            continue;
        }

        dfs(0,0);
        cout<<ans<<endl;
    }
    
    return 0;
}