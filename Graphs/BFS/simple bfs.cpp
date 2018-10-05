
int N = 100000;
vi g[N];

void bfs(int start) {
	queue<int> q;
	q.push(start);
	int vis[N]={0};
	// cout<<start<<" ";
	vis[start] = 1;

	while(!q.empty()) {
		int ff = q.front(), i;
		q.pop();
		rep(i,0,g[ff]) {
			int v = g[ff][i];
			if(!vis[v]) {
				// DO SOMETHING
					// cout<<v<<" ";
				vis[v] = 1;
				q.push(v);
			}
		}
	}

}