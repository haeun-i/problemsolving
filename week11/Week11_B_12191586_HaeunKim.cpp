#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		vector<vector<bool>> paper;

		for (int j = 0; j < t; j++) {
			vector<bool> v;
			for (int q = 0; q < t; q++) {
				string s;
				cin >> s;

				if (s == "R") v.push_back(1);
				else if (s == "B") v.push_back(0);
			}
			paper.push_back(v);
		}

	}
}