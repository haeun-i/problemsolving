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

        string s;
        cin >> s;

        int k;
        cin >> k;

        for (int i = 0; i < k; i++) {
            for (int j = 0; ; j += 2 * k) {
                if (j + i >= s.size()) break;
                cout << s[j + i];
                if (j + 2 * k - i - 1 >= s.size()) break;
                cout << s[j + 2 * k - i - 1];
            }
        }

        cout << '\n';
    }
}