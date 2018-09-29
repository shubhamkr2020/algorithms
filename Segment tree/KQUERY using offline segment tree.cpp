// USE THIS WHEN POINT UPDATE AND RANGE QUERY IS TO BE DONE with offline data...........................
// SIMILAR APPROACH CAN BE TAKEN WITH OFFLINE BIT....................

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
#define compress(s) sort(all(s)); s.resize(unique(s.begin(),s.end())-s.begin());
#define strtoint(s,n) if (!(istringstream(s) >> n) ) n = 0;
#define mod 1000000007
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
inline void fast_out(ll x){
	register char buffor[35]; register ll i=0;
	do{buffor[i++]=(x%10)+'0';
	   x/=10;
	} while(x); i--;
	while(i>=0) putchar(buffor[i--]);
	putchar('\n');}

struct node {
    ll v;
};

struct nod {
    int l,r,v,ind;
};

bool comp(nod l, nod r) {
    if(l.v == r.v) return l.r > r.r;
    return l.v > r.v;
}

node tr[4111111];
ll arr[1111111];
vector<nod> a;

void assignNode(node &nd, ll val) {
    //cout<<"assigning leaf...........";
    nd.v = val;
    //cout<<"leaf assigned with value "<<val<<endl;
}

void merge(node &nd, node lt, node &rt) {
    //cout<<"merging....";
    nd.v = lt.v + rt.v;
    //cout<<"merging complete "<<endl;
}

node query(ll l, ll r, ll s, ll e, ll n) {
    
    //cout<<"querying...."<<n<<endl;
    if(l>e || r<s)
        return node{0};
        
    if(l<=s && r>=e)
    return tr[n];
    
    ll m = (s+e)>>1;
    ll lt = n<<1;
    ll rt = lt+1;
    
    node left = query(l,r,s,m,lt);
    node right = query(l,r,m+1,e,rt);
    node ans;
    merge(ans, left, right);
    //cout<<"query complete"<<n<<endl;
    return ans;
    
}

void build(ll s, ll e, ll n) {
    
    //cout<<"building......"<<endl;
    if(s == e) {
    assignNode(tr[n], arr[s]);
    return;
    }
    
    ll m = (s+e)/2;
    ll lt = n*2, rt = n*2+1;
    build(s, m, lt);
    build(m+1, e, rt);
    merge(tr[n], tr[lt], tr[rt]);
    //cout<<"building complete "<<n<<endl;
}

void update(ll p, ll val, ll s, ll e, ll n) {
    
    //cout<<"updating...."<<endl;
    if(s == e) {
        assignNode(tr[n],val);
        return;
    }
    
    ll m = (s+e)>>1;
    ll lt = n<<1, rt = lt+1;
    
    if(p<=m) {
        update(p,val,s,m,lt);
    }
    else {
        update(p,val,m+1,e,rt);
    }
    
    merge(tr[n],tr[lt],tr[rt]);
    //cout<<"update complete"<<endl;
}

int main() {
    //FAST
    int n=fin;
    //build(1,n,1);
    int i;
    rep(i,0,n) {
        nod x;
        x.v=fin;
        x.l=0;
        x.r=-1;
        x.ind = i;
        a.pb(x);
    }
    
    int m=fin;
    rep(i,0,m) {
        int l=fin, r=fin, k=fin;
        nod x;
        x.v = k;
        x.l = l;
        x.r = r;
        x.ind = i;
        a.pb(x);
    }
    
    sort(all(a),comp);
    
    vi ansv(m+1);
    
    rep(i,0,a.size()) {
        if(a[i].r == -1) {
            //cout<<"hi"<<endl;
            update(a[i].ind+1,1,1,n,1);
        }
        else {
            //cout<<"hiq"<<endl;
            node ans = query(a[i].l, a[i].r, 1,n,1);
            ansv[a[i].ind] = ans.v;
        }
    }
    
    rep(i,0,m)
    printf("%d\n", ansv[i]);
    
    /*int n=fin;
	int i;
	rep(i,1,n+1)
	a[i] = fin;
	
	build(1,n,1);
	
	int m=fin;
	while(m--) {
	    int p=fin,x=fin,y=fin;
	    
	    if(!p) {
	        update(x,y,1,n,1);
	    }
	    
	    if(p) {
	        node ans = query(x,y,1,n,1);
	        cout<<ans.ms;
	        newl;
	    }
	    
	}*/
	
	return 0;
}











