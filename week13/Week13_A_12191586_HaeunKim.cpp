#include <iostream>
#include <vector>
using namespace std;

string puzzle[3001];
int f[3001];

void FailureFunction(string P) {
	f[0] = 0;
	int i = 1;
	int j = 0;
	
	while (i < P.size()) {
		if (P[i] == P[j]) {
			f[i] = j + 1;
			i++;
			j++;
		}
		else if (j > 0) {
			j = f[j - 1];
		}
		else {
			f[i] = 0;
			i++;
		}
	}
}

bool KMPMatch(string T, string P) {
	int i = 0;
	int j = 0;
	while (i < T.size()) {
		if (T[i] == P[j]) {
			if (j == P.size() - 1) return true;
			i++;
			j++;
		}
		else if (j > 0) {
			j = f[j - 1];
		}
		else i++;
	}
	return false;
}

int main() {

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> puzzle[i];
	}
	
	string text, word;
	for (int i = 0; i < n; i++) {
		text += puzzle[i];
		text += "$";
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			text += puzzle[j][i];
		}
		text += "$";
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-i; j++) {
			text += puzzle[j][i+j];
		}
		text += "$";
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			text += puzzle[i + j][j];
		}
		text += "$";
	}

	while (m--) {
		cin >> word;
		FailureFunction(word);
		if (KMPMatch(text, word)) cout << 1 << '\n';
		else cout << 0 << '\n';
	}

}