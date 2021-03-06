// https://www.hackerrank.com/challenges/littlepandapower/editorial
// This can be done by Extended Euclid Algorithm but Euler Totient Function also.....

// A inverse mod x = A power (phi(x)-1) mod x
// OR use Extended Euclid as given below .........
// modinv can be find by modexpo only if mod is prime number.... otherwise use euclid for coprime numbers.


#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(i=j; i<k; i++)
#define rrep(i,j,k) for(i=j; i>=k; i--)
#define tr(c,it) for(auto it = (c).begin(); it != (c).end(); it++)
#define ZERO(a) memset(a,0,sizeof(a))
#define lastbit(x) (x&(-x)) 
#define pb push_back 
#define all(c) (c).begin(),(c).end()
#define fin scan_int()
#define pd(x) printf("%d",x)
#define newl printf("\n")
#define xx first
#define yy second
#define mod 1000000007
#define FIND(x,y) ((y).find((x))!=(y).end())
#define dbg(a) cerr << #a << endl;
#define dbgv(vari) cerr << #vari<< " = "<< (vari) <<endl;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define compress(s) sort(all(s)); s.resize(unique(s.begin(),s.end())-s.begin());
#define strtoint(s,n) if (!(istringstream(s) >> n) ) n = 0;
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

/*/////////////////////////////////////////////*/////////////////////////////////////////////////////////
#define gc getchar
inline ll scan_int() {
   ll NR=0,sign=1;    char c=gc();
    while( c < 48 || c > 57 ){if(c=='-')sign=0; c=gc();}
    while(c>47 && c< 58)
    {    NR = (NR << 3) + (NR << 1) + (c - 48);    c=gc();    }
    return (sign?NR:(-NR));}
inline void fast_out(ll x){
         register char buffor[35]; register ll i=0;
         do{buffor[i++]=(x%10)+'0';
               x/=10;
            } while(x); i--;
            while(i>=0) putchar(buffor[i--]);
            putchar('\n');
}
////////////////////////////////////////////////////////////////////////////////////////////////////////*/

ll egcd(ll a, ll b, ll &x, ll &y) {
    if(b==0) {
        x=1;
        y=0;
        return a;
    }
    ll g = egcd(b, a%b, x, y);
    ll x1 = (y);
    ll y1 = (x - a/b*y);
    x = x1;
    y=y1;
    return g;
}

ll invr(ll a, ll n) {
    ll g, x, y;
    g = egcd(a, n, x, y);
    return x;
}

int main(){
    ll t=fin;
    while(t--) {
        ll a=fin, b=fin, x=fin;
        
        if(b>=0)
            cout<<modexpo(a,b,x)<<endl;
        else {
            ll i = invr(a,x);
            cout<<(modexpo(i,-b,x)+x)%x<<endl;
        }
        
    }
    
    return 0;
}