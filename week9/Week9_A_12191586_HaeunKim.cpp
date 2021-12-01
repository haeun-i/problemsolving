#include <iostream>
using namespace std;

long long x, n, m;

pair<long long, long long> geoseries(long long x,long long n) {
	if (n == 1) return { x % m, x % m };

	pair<long long, long long> half = geoseries(x, n / 2);
	long long exp = half.first;
	long long sum = half.second;

	if (n % 2 == 0) {
		return { (exp * exp) % m, ((1 + exp) * sum) % m };
	}
	else
		return { (x * exp * exp) % m, (x + x * (1 + exp) * sum) % m };
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		
		cin >> x >> n >> m;

		pair<long long, long long> answer = geoseries(x, n);

		cout << answer.second << endl;
	}
}