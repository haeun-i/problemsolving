#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		int answer = 0;
		cin >> n >> m;

		vector<string> sentence;
		vector<queue<string>> word;
		queue<string> q;
		string s;

		for(int q=0; q<m; q++) {
			cin >> s;
			sentence.push_back(s);
		}
		
		for(int i=0; i<n; i++){
			cin >> k;
			word.push_back(q);
			for (int j = 0; j < k; j++) {
				cin >> s;
				word[i].push(s);
			}
		}


		for (int i = 0; i < m; i++) {
			answer = 0;
			for (int j = 0; j < n; j++) {
				if (sentence[i] == word[j].front()) {
					word[j].pop();
					answer = 1;
					break;
				}
			}
			if (answer == 0) break;
		}

		cout << answer << '\n';

		sentence.clear();
		word.clear();
	}

}