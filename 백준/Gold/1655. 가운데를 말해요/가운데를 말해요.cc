#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n;
priority_queue<int> max_heap;
priority_queue<int, vector<int>, greater<int>> min_heap;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while (n--) {
		int num;
		cin >> num;

		// Push
		if (max_heap.size() == 0 || max_heap.top() >= num)
			max_heap.push(num);
		else
			min_heap.push(num);

		// Rebalancing
		if (max_heap.size() > min_heap.size() + 1) {
			min_heap.push(max_heap.top());
			max_heap.pop();
		}
		else if (max_heap.size() < min_heap.size()) {
			max_heap.push(min_heap.top());
			min_heap.pop();
		}

		cout << max_heap.top() << endl;
	}

	return 0;
}
