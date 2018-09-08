
// to find F[i] when F[i] = 3*(F[i-1] + F[i-2]) and F[1]=4 & f[2]=15 .......

// Fibonacci for large numbers ..... https://www.hackerearth.com/practice/notes/fast-matrix-exponentiation-2/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007

void matmult(ll c[][2],ll a[][2],ll b[][2]){
	ll i,j,k;
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			c[i][j]=0;
			for(k=0;k<2;k++){
				c[i][j] += (a[i][k]*b[k][j]);
			}
		}
	}
	return;
}

void matmod(ll c[][2]){
	ll i,j;
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			c[i][j]=c[i][j]%MOD;
		}
	}
	return;
}

void copy(ll a[][2],ll b[][2]){
	ll i,j;
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			a[i][j]=b[i][j];
		}
	}
	return;
}

void power(ll ans[][2],ll a[][2],ll b){
	ll temp[2][2];
	while(b){
		if(b&1){
			matmult(temp,ans,a);
			matmod(temp);
			copy(ans,temp);
		}
		b>>=1;
		matmult(temp,a,a);
		matmod(temp);
		copy(a,temp);
	}
	return;
}

int main(){
	ll n,t;
	cin>>t;
	while(t--) {
		cin>>n;
        if(n==1)    
        	cout<<4<<"\n";
        else if(n==2)   
        	cout<<15<<"\n";
        else {
            ll ans[][2]={{1,0},
            			 {0,1}};
            ll a[][2]={{3,3},
            		   {1,0}};
            power(ans,a,n-2);
            ll A=(15*ans[0][0]+4*ans[0][1])%MOD;
            cout<<A<<endl;
        }
	}
	return 0;
}