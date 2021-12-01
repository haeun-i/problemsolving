#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<vector<int>> grid;
struct point_info{
	int x;
	int y;
};
set<point_info> candidate;
vector<vector<vector<int>>> check[2];
int dx[9] = { 0, 0, 0, 1, 1, 1, -1, -1, -1 };
int dy[9] = { 0, 1, -1, 0, 1, -1, 0, 1, -1 };
int n, q, t;

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> q;
		grid[n / 2][n / 2] = grid[(n / 2) + 1][(n / 2) + 1] = 1;
		grid[(n / 2) + 1][n / 2] = grid[n / 2][(n / 2) + 1] = 2;
		for (int i = 0; i <= 1; i++) {
			for (int j = 0; j <= 1; j++) {
				aroundCandidateFunc(n / 2 + i, n / 2 + j);
			}
		}
		int turn = 1;
		while (q--) {
			int x, y;
			cin >> x >> y;

			int flag = candidateCheckFunc();
			if (flag & turn == 0){
				turn = flag;
			}
			if (grid[x][y] != 0) continue;
			if (check[x][y][turn].empty() == true) continue;
			for
		}
	}
}