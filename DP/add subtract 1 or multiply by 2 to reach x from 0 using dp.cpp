#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(i=j;i<k;i++)

#define N 1001000
int dp[N];

int main() {
	int i,j;
	int a;					// cost when +1 or -1
	int b;					// cost when *2
	cin>>a>>b;
	dp[0] = 0;
	rep(i,1,N) {
		dp[i] = min(dp[i-1], dp[i+1])+a;
		if(2*i < N) dp[2*i] = dp[i]+b;
	}

	rep(i,0,20) cout<<dp[i]<<" "; cout<<endl;

	return 0;
}
