#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct roadInfo {
	int neighbor, distance;
};

int answer;
vector<roadInfo>* house;
bool* visitedhouse;

int treeSearch(int u) {
	int maxDistance = 0, secondMaxDistance = 0, tempDistance = 0;

	visitedhouse[u] = true;
	for (int i = 1; i <= house[u].size(); i++) {
		if (visitedhouse[house[u][i-1].neighbor] == false) {
			tempDistance = treeSearch(house[u][i-1].neighbor) + house[u][i-1].distance;
			if (tempDistance > maxDistance) swap(tempDistance, maxDistance);
			if (tempDistance > secondMaxDistance) swap(tempDistance, secondMaxDistance);
		}
	}
	answer = max(answer, maxDistance + secondMaxDistance);
	return maxDistance;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		house = new vector<roadInfo>[n + 1];
		visitedhouse = new bool[n + 1];
		fill_n(visitedhouse, n + 1, false);

		for(int i = 1; i < n; i++) {
			int u, v, d;
			cin >> u >> v >> d;
			house[u].push_back({ v, d });
			house[v].push_back({ u, d });
		}
		
		answer = 0;
		treeSearch(1);
		cout << answer << '\n';

		delete[] house;
		delete[] visitedhouse;
	}

}