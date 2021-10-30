#include <iostream>
#include <vector>
using namespace std;

int* visit;
vector<int>* graph;

void dfs(int u) {
	visit[u] = 1;
	for (int i = 0; i < graph[u].size(); i++) {
		int v = graph[u][i];
		if (visit[v] == 0) dfs(v);
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int answer = 0;

		int n, m;
		cin >> n >> m;

		graph = new vector<int>[n + 1];
		visit = new int[n + 1];

		for (int i = 1; i <= m; i++) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				visit[j] = 0;
			}
			dfs(i);
			answer = 0;
			for (int j = 1; j <= n; j++) {
				answer += visit[j];
			}
			cout << answer - 1 << ' ';
		}
		cout << endl;
	}
}