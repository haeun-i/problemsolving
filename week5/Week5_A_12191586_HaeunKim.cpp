#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {

		vector<int> problem;
		vector<int> answer;
		int n;
		cin >> n;
		while (n--) {
			int num;
			cin >> num;
			problem.push_back(num);
		}

		answer.push_back(problem[0]);

		for (int i = 1; i < problem.size(); i++) {
			if (problem[i] == problem[0]) {
				for (int j = 1; j < answer.size(); j++) {
					if (problem[i + j] == answer[j]) break;
					else answer.push_back(problem[i]);
				}
			}
			else answer.push_back(problem[i]);
		}

		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << " ";
		}
		cout << '\n';
	}

}