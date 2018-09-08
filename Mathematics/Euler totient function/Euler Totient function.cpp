//	Spoj - ETF
//  Phi(n) = Number of positive integers upto n which are relatively prime to n
//	Similar to finding Prime factors........
//	Do "res = res - res/p" for every prime factor p..........

#include <iostream>
using namespace std;

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

int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    cout<<phi(n)<<endl;
	}
	//code
	return 0;
}