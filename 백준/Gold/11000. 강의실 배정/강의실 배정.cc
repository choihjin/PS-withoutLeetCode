#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n;
vector<pair<int, int>> v(200'002);
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

	sort(v.begin(), v.begin() + n);

	for (int i = 0; i < n; i++) {
		int start = v[i].first;
		int end = v[i].second;

		if (!pq.empty() && pq.top() <= start) 
			pq.pop();
		
		pq.push(end);
	}

	cout << pq.size() << endl;

	return 0;
}
