#include <iostream>
using namespace std;
 
int N, M, Q, p[509][509];
int main() {
	cin >> N >> M >> Q;
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) cin>>p[i][j];
	for (int i = 1; i <= N; i++) { for (int j = 1; j <= N; j++) p[i][j] += p[i][j - 1]; }
	for (int i = 1; i <= N; i++) { for (int j = 1; j <= N; j++) p[i][j] += p[i - 1][j]; }
 	
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			cout<<p[i][j]<<" ";
		}
		cout<<endl;
	}

	// for (int i = 1; i <= Q; i++) {
	// 	int L, R; cin >> L >> R;
	// 	cout << p[R][R] + p[L - 1][L - 1] - p[L - 1][R] - p[R][L - 1] << endl;
	// }
	return 0;
}