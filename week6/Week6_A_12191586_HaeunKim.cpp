#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct customerInfo {
	int useTime;
	int cost;
};

struct counterInfo {
	int endTime;
	int number;

	bool operator<(const counterInfo& c)const {
		if (endTime == c.endTime) return c.number < number;
		else return c.endTime < endTime;
	}

};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, timeAnswer;
	cin >> n >> m;

	int* costAnswer = new int[n + 1]{};
	customerInfo* customer = new customerInfo[m + 1];
	priority_queue<counterInfo> counterPQ;

	for (int i = 1; i <= m; i++) {
		cin >> customer[i].useTime >> customer[i].cost;
	}
	for (int i = 1; i <= n; i++) {
		counterPQ.push({ customer[i].useTime, i });
		costAnswer[i] += customer[i].cost;
		timeAnswer = max(timeAnswer, customer[i].useTime);
	}
	for (int i = n + 1; i <= m; i++) {
		counterInfo counterTemp = counterPQ.top();
		counterPQ.pop();
		counterTemp.endTime += customer[i].useTime;
		costAnswer[counterTemp.number] += customer[i].cost;
		timeAnswer = max(timeAnswer, counterTemp.endTime);
		counterPQ.push(counterTemp);
	}
	cout << timeAnswer << '\n';
	for (int i = 1; i <= n; i++) {
		cout << costAnswer[i] << '\n';
	}
}