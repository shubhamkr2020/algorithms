#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define rep(i,j,k) for(i=j; i<k; i++)
#define rrep(i,j,k) for(i=j; i>=k; i--)
#define ZERO(a) memset(a,0,sizeof(a))
#define lowbit(x) (x&(-x))
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end()
inline int sint() {
   int NR=0,sign=1;    char c=gc();
    while( c < 48 || c > 57 ){if(c=='-')sign=0; c=gc();}
    while(c>47 && c< 58)
    {    NR = (NR << 3) + (NR << 1) + (c - 48);    c=gc();    }
    return (sign?NR:(-NR));}
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<string,int> psi; 
typedef pair<int,int> pii;

void update(int tree[],int n,int p,int v) {
    int i;
    for(i=p; i<=n; i+=i&-i)
    tree[i] += v;
}

void rUpdate(int tree[],int n,int l,int r,int v) {
    update(tree,n,l,v);
    update(tree,n,r+1,-v);
}

int query(int tree[],int idx) {
    int i,sum=0;
    for(i=idx; i>0; i-=i&-i)
    sum+=tree[i];
    return sum;
}

int main() {
	
	int t=sint();
	while(t--) {
	    int n=sint(),u=sint();
	    int i;
	    int tree[n+1]={0};
	    rep(i,0,u) {
	        int l=sint(),r=sint(),v=sint();
	        rUpdate(tree,n,l+1,r+1,v);
	    }
	    int q=sint();
	    while(q--) {
	        int idx=sint();
	        cout<<query(tree,idx+1)<<endl;
	    }
	}
	
	return 0;
}