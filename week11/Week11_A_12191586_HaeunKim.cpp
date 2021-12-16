#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int score[24];
bool t_f[8388610];
int needAlphabet[24][27];
int restAlphabet[8388609][27];
int m, answer;
string word;
int getScore[8388609];

void solution() {

	getScore[0] = 0;

	for (int i = 1; i <= m; i++) {
		int status = 1 << (i - 1);

		for (int j = 0; j < status; j++) {
			bool flag = false;

			for (int k = 1; k <= 26; k++) {
				if (restAlphabet[j][k] < needAlphabet[i][k]) {
					flag = true;
				}
			}

			if (flag == true) continue;

			for (int k = 1; k <= 26; k++) {
				restAlphabet[j + status][k] = restAlphabet[j][k] - needAlphabet[i][k];
			}
			getScore[j + status] = getScore[j] + score[i];
			answer = max(answer, getScore[j + status]);
		}
	}

}

int main() {

	for (int i = 1; i <= 26; i++) {
		cin >> restAlphabet[0][i];
	}
	
	cin >> m;

	for (int i = 1; i <= m; i++) {
		cin >> word >> score[i];

		for (int j = 0; j < word.length(); j++) {
			needAlphabet[i][word[j] - 'a' + 1] += 1;
		}
	}

	solution();

	cout << answer;
}