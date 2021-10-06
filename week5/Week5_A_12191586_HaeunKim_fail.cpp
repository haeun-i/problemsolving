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

		for (int i = 1; i <= problem.size(); i++) {

			answer.assign(problem.begin(), problem.begin()+i);
			int cnt = 0;
			for (int j = 0; j < problem.size(); j++) {
				if (answer[j % answer.size()] != problem[j]) {
					answer.clear();
					break;
				}				
			}
			
			if (!answer.empty()) {
				break;
			}
		}

		for (int p = 0; p < answer.size(); p++) {
			cout << answer[p] << " ";
		}
		cout << '\n';
		
	}
}