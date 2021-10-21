#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

struct point {
	int x;
	int y;
};

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int** check = new int* [n + 1];
		bool** visited = new bool* [n + 1];
		for (int i = 0; i <= n; i++) {
			check[i] = new int[n + 1];
			memset(check[i], 0, sizeof(int)*(n + 1));
		}
		for (int i = 0; i <= n; i++) {
			visited[i] = new bool[n + 1];
			memset(visited[i], false, sizeof(bool) * (n + 1));
		}
		int dx[9] = { 0, 0, 0, 1, 1, 1, -1, -1, -1 };
		int dy[9] = { 0, 1, -1, 0, -1, 1, 0, -1, 1 };

		point inha, safe, knight, gunner;
		cin >> inha.x >> inha.y >> safe.x >> safe.y >> knight.x >> knight.y >> gunner.x >> gunner.y;

		for (int i = 1; i <= 8; i++) {
			for (int j = 1; j <= n; j++) {
				if (gunner.x + dx[i] * j == 0 || gunner.x + dx[i] * j == n + 1
					|| gunner.y + dy[i] * j == 0 || gunner.y + dy[i] * j == n + 1) break;
				if (gunner.x + dx[i] * j == knight.x && gunner.y + dy[i] * j == knight.y) break;
				check[gunner.x + dx[i] * j][gunner.y + dy[i] * j] = -1;
			}
		}
		for (int i = 1; i <= 8; i++) {
			if (knight.x + dx[i] == 0 || knight.x + dx[i] == n + 1
				|| knight.y + dy[i] == 0 || knight.y + dy[i] == n + 1) continue;
			check[knight.x + dx[i]][knight.y + dy[i]] = -1;
		}

		queue<point> que;
		que.push({ inha.x, inha.y });
		while (que.empty() == false) {
			point now = que.front();
			que.pop();
			visited[now.x][now.y] = true;
			for (int i = 1; i <= 8; i++) {
				if (now.x + dx[i] == 0 || now.x + dx[i] == n + 1
					|| now.y + dy[i] == 0 || now.y + dy[i] == n + 1) {
					continue;
				}
				if (check[now.x + dx[i]][now.y + dy[i]] != 0 || visited[now.x + dx[i]][now.y + dy[i]]) {
					continue;
				}

				check[now.x + dx[i]][now.y + dy[i]] = check[now.x][now.y] + 1;
				que.push({ now.x + dx[i], now.y + dy[i] });
			}
		}
		cout << check[safe.x][safe.y] << '\n';

		for (int i = 0; i <= n; i++) {
			delete[] check[i];
		}
		delete[] check;
		for (int i = 0; i <= n; i++) {
			delete[] visited[i];
		}
		delete[] visited;
	}
}