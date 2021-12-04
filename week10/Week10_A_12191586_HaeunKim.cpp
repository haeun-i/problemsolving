#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int t, a, b;
vector<int> road[10000];
int check[10000];
queue<int> que;

int main() {

	for (int i = 0; i <= 9999; i++) {
		if (i != 0)road[i].push_back(i - 1);
		if (i != 9999) road[i].push_back(i + 1);
		int num = 0;
		int temp = i;
		for (int j = 0; j <= 3; j++) {
			num = num * 10 + temp % 10;
			temp = temp / 10;
		}
		road[i].push_back(num);
	}


	cin >> t;

	while (t--) {
		for (int i = 0; i <= 9999; i++) check[i] = 10000;

		cin >> a >> b;
		check[a] = 0;
		que.push(a);

		while (que.empty() == false) {
			int now = que.front();
			que.pop();

			for (int i = 0; i < road[now].size(); i++) {
				if (check[road[now][i]] > check[now] + 1) {
					que.push(road[now][i]);
					check[road[now][i]] = check[now] + 1;
				}
			}
		}

		cout << check[b] << endl;
	}
}