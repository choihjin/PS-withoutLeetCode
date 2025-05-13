#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

vector<int> team[502];
int indeg[502];
int T, n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--) {
        // input
        int tmp[502];
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> tmp[i];
        
        for(int from = 1; from <= n - 1; from++) {
            for(int to = from + 1; to <= n; to++) {
                team[tmp[from]].push_back(tmp[to]);
                indeg[tmp[to]]++;
            }
        }

        // change
        int from, to;
        cin >> m;
        for(int i = 0; i < m; i++) {
            cin >> from >> to;

            if (find(team[to].begin(), team[to].end(), from) != team[to].end()) {
                // to -> from => from -> to
                team[to].erase(find(team[to].begin(), team[to].end(), from));
                indeg[from]--;
                team[from].push_back(to);
                indeg[to]++;
            } else {
                // from -> to => to -> from
                team[from].erase(find(team[from].begin(), team[from].end(), to));
                indeg[to]--;
                team[to].push_back(from);
                indeg[from]++;
            }
        }

        // topological sort
        queue<int> Q;
        vector<int> ans;
        for(int i = 1; i <= n; i++) 
            if(indeg[i] == 0) Q.push(i);
        while(!Q.empty()) {
            if(Q.size() > 1) {
                cout << "?" << endl;
                goto RESET;
            }

            int cur = Q.front(); Q.pop();
            ans.push_back(cur);
            for(int nxt : team[cur]) 
                if(--indeg[nxt] == 0) Q.push(nxt);
        }
        
        // print result
        if(ans.size() == n) {
            for(auto a : ans) cout << a << " ";
            cout << endl;
        }
        else cout << "IMPOSSIBLE" << endl;

        // reset
        RESET:
            for (int i = 1; i <= n; i++) team[i].clear();
            memset(indeg, 0, sizeof(indeg));
    }

    return 0;
}