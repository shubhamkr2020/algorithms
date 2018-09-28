
// https://codeforces.com/contest/271/problem/D
// 2D array Implementation of trie.....................

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

// struct Node {
//     map<char, Node*> child;
// };
// Node *root;

// void insert(string s) {
//     int i;
//     Node *t = root;
//     rep(i,0,s.length()) {
//         if(t->child[s[i]] == NULL) t->child[s[i]] = new Node;
//         t = t->child[s[i]];
//     }
// }

// int c;

// void dfs(Node *node) {
//     if(node == NULL) return;
//     int i;
//     tr(node->child, it) {
//         dfs(it->yy);
//     }
//     c++;
// }


int tr[3000111][27];
int sz=1;

void insert(string s) {
    int i, p=0, n=s.length();
    rep(i,0,n) {
        int x = s[i]-'a';
        if(!tr[p][x])
            tr[p][x] = sz++;
        p = tr[p][x];
    }
}

int main(){

    string s;
    cin>>s;
    string gb;
    cin>>gb;
    int good[27]={0};
    int i,j;
    rep(i,0,26) if(gb[i] == '1') good[i] = 1;

    int k=fin;
    int n=s.length();
    int a[n];
    rep(i,0,n) {
        int c=0;
        rep(j,i,n) {
            if(!good[s[j]-'a']) c++;
            if(c>k) break;
        }
        a[i] = j;
    }

    rep(i,0,n) {
        string x="";
        int j;
        rep(j,i,a[i]) x += s[j];
        // cout<<x<<endl;
        insert(x);
    }
    cout<<sz-1<<endl;
    return 0;
}