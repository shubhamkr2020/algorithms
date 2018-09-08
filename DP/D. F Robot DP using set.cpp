// https://abc082.contest.atcoder.jp/tasks/arc087_b
// solved using dp with sets, deleting the set and inserting the new values at every step................

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
 
set<int> dpx,dpy;
ll fi=1;
 
void movex(ll c) {
    if(fi) {
        dpx.insert(c);
        fi=0;
        return;
    }
    else {
        set<int> temp = dpx;
        dpx.clear();
        tr(temp, it) {
            dpx.insert((*it) + c);
            dpx.insert((*it) - c);
        }
    }
}
 
void movey(ll c) {
    if(!dpy.size()) {
        dpy.insert(c);
        dpy.insert(-c);
    }
    else {
        set<int> temp = dpy;
        dpy.clear();
        tr(temp, it) {
            dpy.insert((*it) + c);
            dpy.insert((*it) - c);
        }
    }
}
 
int main(){
    string s;
    cin>>s;
    ll x=fin, y=fin;
    ll i,j,f=0;
    dpx.insert(0);
    dpy.insert(0);
    
    rep(i,0,s.length()) {
        if(s[i] == 'F' && f==0) {
            ll c=0;
            while(s[i] == 'F' && i<s.length()) {
                c++;
                i++;
            }
            i--;
            movex(c);
        }
        else if(s[i] == 'F' && f==1) {
            ll c=0;
            while(s[i] == 'F' && i<s.length()) {
                c++;
                i++;
            }
            i--;
            movey(c);
        }
        else {
            /*if(f==0) {
                movey(1);
            }
            else if(f==1) {
                movex(1);
            }*/
            f = 1-f;
        }
    }
    
    /*tr(dpx, it) cout<<*it<<" ";cout<<endl;
    tr(dpy, it) cout<<*it<<" ";cout<<endl;*/    
    
    if(dpx.find(x)!=dpx.end() && dpy.find(y)!=dpy.end())
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
    
    return 0;
}