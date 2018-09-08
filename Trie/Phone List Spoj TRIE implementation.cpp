#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define rep(i,j,k) for(i=j; i<k; i++)
#define rrep(i,j,k) for(i=j; i>=k; i--)
#define tr(c,it) for(auto it = (c).begin(); it != (c).end(); it++)
#define ZERO(a) memset(a,0,sizeof(a))
#define lowbit(x) (x&(-x))
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end()
#define fin scan_int()
#define fout(x) fast_out(x)
#define mp make_pair
#define sc(x) scanf("%d",&x)
#define sc2(x,y) scanf("%d%d",&x,&y)
#define sc3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define scl(x) scanf("%lld",&x)
#define scl2(x,y) scanf("%lld%lld",&x,&y)
#define scl3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define scstr(x) scanf("%s",x)
#define pd(x) printf("%d",x)
#define pd2(x,y) printf("%d %d",x,y)
#define pll(x) printf("%lld",x)
#define pll2(x,y) printf("%lld %lld",x,y)
#define pstr(x) printf("%s",x)
#define newl printf("\n")
#define xx first
#define yy second
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<string,int> psi; 
typedef pair<int,int> pii;
inline int scan_int() {
   int NR=0,sign=1;    char c=gc();
    while( c < 48 || c > 57 ){if(c=='-')sign=0; c=gc();}
    while(c>47 && c< 58)
    {    NR = (NR << 3) + (NR << 1) + (c - 48);    c=gc();    }
    return (sign?NR:(-NR));}
inline void fast_out(int x){
         register char buffor[35]; register int i=0;
         do{buffor[i++]=(x%10)+'0';
               x/=10;
            } while(x); i--;
            while(i>=0) putchar(buffor[i--]);
            putchar('\n');
}

struct node {
    bool end;
    node *child[10];
};

bool dfs(node *n) {
    
    if(n == NULL) return true;
    
    if(n->end) {
        int i;
        rep(i,0,10)
        if(n->child[i] != NULL)
        return false;
        return true;
    }
    
    int i;
    bool ans=true;
    rep(i,0,10)
    ans = ans && dfs(n->child[i]);
    
    return ans;
}
 
int main(){
    FAST
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        
        node *root = new node;
        while(n--) {
            string s;
            cin>>s;
            int i;
            node *temp = root;
            rep(i,0,s.length()) {                       // insert.....
                if(temp->child[s[i]-'0'] == NULL)
                temp->child[s[i]-'0'] = new node;
                temp = temp->child[s[i]-'0'];
                if(i == s.length()-1)
                temp->end = true;
            }
        }
        
        
        if(dfs(root))                                   // traverse.....
        cout<<"YES";
        else cout<<"NO";
        cout<<endl;
        
    }
    
    
    return 0;
}