#include <iostream>
#include <vector>
using namespace std;

struct node {
	int parent = 0;
	vector<int> child;
	int length = 0;
};

int n;
node* tree;
int* directory;

void treeTraversal(int x) {
	if (x == 1) directory[x] = tree[x].length;
	else {
		directory[x] = directory[tree[x].parent] + 1 + tree[x].length;
	}

	for (int i = 1; i <= tree[x].child.size(); i++) {
		treeTraversal(tree[x].child[i-1]);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin >> t;
	
	while (t--) {
		int n;
		cin >> n;

		tree = new node[n + 1];
		directory = new int[n + 1];

		for (int i = 1; i < n; i++) {
			int a, b;
			cin >> a >> b;

			tree[b].parent = a;
			tree[a].child.push_back(b);	
		}

		for (int i = 1; i <= n; i++) {
			string s;
			cin >> s;
			tree[i].length = s.size();
		}

		treeTraversal(1);

		for (int i = 1; i <= n; i++) {
			cout << directory[i] << endl;
		}
		
		delete[] tree;
		delete[] directory;
	}

}


