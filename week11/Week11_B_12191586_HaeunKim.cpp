#include <iostream>
#include <vector>
using namespace std;

char paper[1025][1025];

struct paperInfo {
	int redNum, redSize, blueNum, blueSize;
};

paperInfo solution(int x, int y, int size) {
	paperInfo ret = { 0, 0, 0, 0 };

	if (size == 1) {
		if (paper[x][y] == 'R') {
			ret.redNum = 1;
			ret.redSize = 1;
		}
		else {
			ret.blueNum = 1;
			ret.blueSize = 1;
		}

		return ret;
	}

	paperInfo status[5];
	status[1] = solution(x, y, size / 2);
	status[2] = solution(x + size/ 2, y, size / 2);
	status[3] = solution(x, y + size / 2, size / 2);
	status[4] = solution(x + size / 2, y + size / 2, size / 2);

	for (int i = 1; i <= 4; i++) {
		ret.redNum += status[i].redNum;
		ret.redSize += status[i].redSize;
		ret.blueNum += status[i].blueNum;
		ret.blueSize += status[i].blueSize;
	}

	if (ret.redNum == 0) ret.blueNum = 1;
	if (ret.blueNum == 0) ret.redNum = 1;

	return ret;
}


int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> paper[i][j];
			}
		}

		paperInfo answer = solution(0, 0, n);
		cout << answer.redNum << " " << answer.redSize << " " << answer.blueNum << " " << answer.blueSize << '\n';
	
	}
}