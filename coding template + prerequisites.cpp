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
#define pd(x) printf("%d ",x)
#define newl printf("\n")
#define xx first
#define yy second
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define strtoint(s,n) if (!(istringstream(s) >> n) ) n = 0;
#define mod 1000000007
typedef long long ll;
typedef vector<int > vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<string,int > psi; 
typedef pair<int ,int > pii;

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


template<int MOD>
struct ModInt {
    static const int Mod = MOD;
    unsigned x;
    ModInt(): x(0) { }
    ModInt(signed sig) { int sigt = sig % MOD; if(sigt < 0) sigt += MOD; x = sigt; }
    ModInt(signed long long sig) { int sigt = sig % MOD; if(sigt < 0) sigt += MOD; x = sigt; }
    int get() const { return (int)x; }
    ModInt &operator+=(ModInt that) { if((x += that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(ModInt that) { if((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
    ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
    ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
    ModInt inverse() const {
        long long a = x, b = MOD, u = 1, v = 0;
        while(b) {
            long long t = a / b;
            a -= t * b; std::swap(a, b);
            u -= t * v; std::swap(u, v);
        }
        return ModInt(u);
    }
};
typedef ModInt<1000000007> mint;
// Now define vector<mint> ans do simple calculations + - * ans /


int main(){
    
    
    return 0;
}


///***********************************************************************************///

#define present(c,x) ((c).find(x) != (c).end())				// used in set and map...... 
#define cpresent(c,x) (find(all(c),x) != (c).end())			// used in vectors......

bool operator < (const fraction& f) const					// used to overload '<' operator in a struct...........

	// comp class for set.........................................
    // now declare the set as set<int,classcomp> st; ...............
struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs<rhs;}
};


 	// use power up stl on topcoders for stl references......................



    // to convert into string for any type..........................
template<class T>
string to_string(T s){
  stringstream tin;
  tin<<s;
  string res;
  getline(tin,res);
  return(res);
}

    // constant time number of bit counting in an integer algo ..................
unsigned numbits(unsigned i) {
    const unsigned MASK1  = 0x55555555;
    const unsigned MASK2  = 0x33333333;
    const unsigned MASK4  = 0x0f0f0f0f;
    const unsigned MASK8  = 0x00ff00ff;
    const unsigned MASK16 = 0x0000ffff;
    i = (i&MASK1 ) + (i>>1 &MASK1 );
    i = (i&MASK2 ) + (i>>2 &MASK2 );
    i = (i&MASK4 ) + (i>>4 &MASK4 );
    i = (i&MASK8 ) + (i>>8 &MASK8 );
    i = (i&MASK16) + (i>>16&MASK16);
    return i;

    // or

    return __builtin_popcount(i);           // library function for number of bits count
}


	// convert into binary form......
string binary(int n) {
    string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}


    // convert decimal number x (base 10) into base y................
int toBasey(int x, int y) {
    int res = 0;
    if ( x < y ) return x;
    int rem = x%y;
    res = 10*toBasey(x/y, y) + rem;
    return res;
}

    //Compression of vector in relative order.........................
vi compress(vi v) {
    int n=v.size(), i;
    vi u = v, res(n);
    sort(all(u));
    unique(all(u));
    rep(i,0,n) res[i] = lower_bound(all(u), v[i]) - u.begin();
    return res;
}


    //swap using bitwise operator.....................
void swap(char *a,char *b) {
    if( *a == *b )
        return;
    *a^=*b;
    *b^=*a;
    *a^=*b;
}

    // SUM of two large numbers in C++ as strings...............................
string Sum(string str1, string str2) {
    if (str1.length() > str2.length())
        swap(str1, str2);
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
    for (int i=0; i<n1; i++) {
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    for (int i=n1; i<n2; i++) {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    if (carry)
        str.push_back(carry+'0');
    reverse(str.begin(), str.end());
    return str;
}


    // Large Numbers Multiplication in C++ as strings..................
string multiply(string num1, string num2) {
    int n1 = num1.size();
    int n2 = num2.size();
    if (n1 == 0 || n2 == 0)
       return "0";
    vector<int> result(n1 + n2, 0);
    int i_n1 = 0; 
    int i_n2 = 0; 
    for (int i=n1-1; i>=0; i--) {
        int carry = 0;
        int n1 = num1[i] - '0';
        i_n2 = 0;
        for (int j=n2-1; j>=0; j--) {
            int n2 = num2[j] - '0';
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;
            carry = sum/10;
            result[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }
        if (carry > 0)
            result[i_n1 + i_n2] += carry;
        i_n1++;
    }
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
       i--;
    if (i == -1)
       return "0";string s = "";
    while (i >= 0)
        s += std::to_string(result[i--]);
    return s;
}

    //simpleSieve --- Use vector to store primes upto 10^7 only else use segmentedSieve..........................
void simpleSieve(int limit, vector<int> &prime) {
    bool mark[limit+1];
    memset(mark, true, sizeof(mark));
    for (int p=2; p*p<limit; p++) {
        if (mark[p] == true) {
            for (int i=p*2; i<limit; i+=p)
                mark[i] = false;
        }
    }
    for (int p=2; p<limit; p++) {
        if (mark[p] == true) {
            prime.push_back(p);
            cout << p << "  ";
        }
    }
}

    //segmentedSieve ---- Directly prints the primes upto n using "simpleSieve"..........................
void segmentedSieve(int n) {
    int limit = floor(sqrt(n))+1;
    vector<int> prime;  
    simpleSieve(limit, prime); 
    int low  = limit;
    int high = 2*limit;
    while (low < n) {
        if (high >= n) high = n; 
        bool mark[limit+1];
        memset(mark, true, sizeof(mark));
        for (int i = 0; i < prime.size(); i++) {
            int loLim = floor(low/prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];
            for (int j=loLim; j<high; j+=prime[i])
                mark[j-low] = false;
        }
        for (int i = low; i<high; i++)
            if (mark[i - low] == true)
                cout << i << "  ";
        low  = low + limit;
        high = high + limit;
    }
}

    // Find Prime Numbers upto 10^7 in vector<int > pr
    // it also calculates the factorization of numbers in O(n) using lp array
 
vi primes(int N) {
    int lp[N+1] = {0};              // contains lowest prime factor of index
    vi pr;                          // this will contain prime numbers - 2,3,5,7,.......
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }   
    return pr;
}
    


    //ifPrime(int n).....................................
bool ifPrime(long long n)
{
	if(n==1)
        return false;
    for(int i=2; i*i<n+1; i++)
        if(n%i == 0)
        return false;
    return true;
}



	// euler totient function phi for number of relative primes (coprimes) ..............
	// phi(n) = n(1-1/p1)(1-1/p2).........
    // similar to finding prime factors.........
int phi(int n) {    
    int result = n;
    for (int p=2; p*p<=n; ++p) {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    if (n > 1) 
        result -= result / n;
    return result;
}

	// nCr = c[n][r].........................................
long long c[1001][1001];
void comb(int n,int r) {
    rep(i,0,1111) c[i][0] = 1;
    rep(i,0,1111) c[i][i] = 1;
    rep(i,1,1111) {
        rep(j,1,1111) {
            if(i!=j)
            c[i][j] = (c[i-1][j] + c[i-1][j-1]);
        }
    }
}
    // OR ...............
    
long long ncr(int n, int r) {
    if(r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;
    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }
    return ans;
}

    // Compression of an array into n elements.................
void compres(int arr[], int n) {
    int temp[n];
    for (int i=0; i<n; i++)
        temp[i] = arr[i];
    sort(temp, temp+n);
    for (int i=0; i<n; i++)
        arr[i] = lower_bound(temp, temp+n, arr[i]) - temp + 1;
}


	// matrix rotation of mata 90 deg clockwise..................
int mata[2000][2000],matb[2000][2000];
void rotate(int n) {
    int i,j;
    for(i=1; i<n+1; i++)		// take transpose.....
        for(j=1; j<n+1; j++)
            matb[j][i] = mata[i][j];
    for(i=1; i<n+1; i++)		// reverse column wise......
        for(j=1; j<n+1; j++)
            mata[i][j] = matb[i][n-j+1];
}
