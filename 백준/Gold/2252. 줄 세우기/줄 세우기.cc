#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n, m;
vector<int> front[32002];
bool visited[32002] = { false, };
stack<int> s;

void DFS(int node) {
	visited[node] = true;
	for (int i = 0; i < front[node].size(); i++) {
		if(visited[front[node][i]] == false) // 앞에 있는 노드 중 방문되지 않은 노드
			DFS(front[node][i]);
	}
	cout << node << " ";
}

int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        front[b].push_back(a);
    }

    for(int i=1; i<=n; i++) 
        if(visited[i] == false) DFS(i);

    cout << endl;

    return 0;
}