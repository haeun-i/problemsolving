#include <iostream>
#include <vector>
using namespace std;

int cards[27] = { 0 };

int main() {
	for (int i = 1; i <= 26; i++) {
		int num;
		cin >> num;
		cards[i] = num;
	}

	int M;
	cin >> M;

	vector<pair<string, int>> score;
	while (M--) {
		string W;
		int S;
		cin >> W >> S;

		score.push_back(make_pair(W, S));
	}
	
}