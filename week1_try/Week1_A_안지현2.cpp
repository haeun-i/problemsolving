#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        stack<int> stk;
        stack<int> min;
        stack<int> max;
        while (N--) {
            int cmd;
            cin >> cmd;
            if (cmd == 1) {
                int num;
                cin >> num;
                if (min.empty() || min.top() >= num) min.push(num);
                if (max.empty() || max.top() <= num) max.push(num);
                stk.push(num);
                cout << min.top() << " " << max.top() << "\n";
            }
            else if (cmd == 2) {
                if (!stk.empty()) {
                    if (!min.empty() && (min.top() == stk.top())) {
                        min.pop();
                    }
                    if (!max.empty() && (max.top() == stk.top())) {
                        max.pop();
                    }
                }
                stk.pop();
            }
        }
    }
    return 0;
}