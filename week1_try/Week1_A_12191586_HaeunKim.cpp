#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	
	for (int q = 0; q < n; q++) {

		vector<vector<char>> v_arr;

		string s;
		cin >> s;
		int size;
		cin >> size;


		if (s.size() % size != 0) {
			for (int k = 0; k < s.size() % size; k++) {
				s += '.';
			}
		}

		for (int i = 0; i < s.size() / size; i++) {
			vector<char> arr;
			for (int j = 0; j < size; j++) {
				arr.push_back(s[i * size + j]);
			}
			v_arr.push_back(arr);
		}

		vector<vector<char>> z_arr; // 지그재그로 들어갈 문자열

		for (int i = 0; i < s.size() / size; i++) {
			vector<char> arr;
			if (i % 2 != 0) {
				for (int j = 0; j < size; j++) {
					arr.push_back(v_arr[i][size - 1 - j]);
				}
			}
			else {
				for (int j = 0; j < size; j++) {
					arr.push_back(v_arr[i][j]);
				}
			}
			z_arr.push_back(arr);
		}

		for (int i = 0; i < size; i++) { // 출력 지그재그로
			for (int j = 0; j < s.size() / size; j++) {
				if (z_arr[j][i] != '.') {
					cout << z_arr[j][i];
				}
			}
		}
		cout << endl;
	}

}