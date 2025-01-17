#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n, m;
vector<int> adj[1002];
int deg[1002];
vector<string> name;
map<string, int> name_to_index; // 이름을 인덱스로 매핑

int main() {
    cin >> n;
    name.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> name[i];
    }
    sort(name.begin(), name.end());

    // 이름을 인덱스로 매핑
    for (int i = 0; i < n; i++) {
        name_to_index[name[i]] = i;
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;
        adj[name_to_index[b]].push_back(name_to_index[a]);
        deg[name_to_index[a]]++;
    }

    queue<int> q;
    int cnt = 0;
    vector<int> ancestor;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            q.push(i);
            cnt++;
            ancestor.push_back(i);
        }
    }

    cout << cnt << endl;
    for (auto a : ancestor) cout << name[a] << " ";
    cout << endl;

    vector<int> ans[1002];
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int nxt : adj[cur]) {
            if (--deg[nxt] == 0) {
                q.push(nxt);
                ans[cur].push_back(nxt);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        sort(ans[i].begin(), ans[i].end()); // 자식 노드 정렬
        cout << name[i] << " " << ans[i].size() << " ";
        for (int j = 0; j < ans[i].size(); j++) cout << name[ans[i][j]] << " ";
        cout << endl;
    }

    return 0;
}
