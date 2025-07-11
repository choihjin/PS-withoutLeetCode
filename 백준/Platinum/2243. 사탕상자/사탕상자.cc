#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int MAX = 1'000'000;
int n;
vector<int> seg(MAX * 4 + 4);

void update(int node, int start, int end, int idx, int val) {
	if (idx < start || end < idx) return;

	if (start == end) {
		seg[node] += val;
		return;
	}

	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, val);
	update(node * 2 + 1, mid + 1, end, idx, val);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

int query(int node, int start, int end, int k) {
	if (start == end) return start;
	int left = seg[node * 2];
	int mid = (start + end) / 2;
	if (k <= left) return query(node * 2, start, mid, k);
	return query(node * 2 + 1, mid + 1, end, k - left);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	while (n--) {
		int cmd;
		cin >> cmd;

		if (cmd == 1) {
			int k;
			cin >> k;

			int pos = query(1, 1, MAX, k);
			cout << pos << endl;
			update(1, 1, MAX, pos, -1);
		}
		else if (cmd == 2) {
			int idx, val;
			cin >> idx >> val;
			update(1, 1, MAX, idx, val);
		}
	}

	return 0;
}
