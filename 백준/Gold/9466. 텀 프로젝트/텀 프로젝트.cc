#include <bits/stdc++.h>
using namespace std;

int arr[100005];
int n;
int state[100005]; 

const int NOT_VISTED = 0;
const int CYCLE_IN = 1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        for(int i=1; i<=n; i++) cin >> arr[i];
        fill(state+1, state+n+1, 0);

        // BFS
        for(int i=1; i<=n; i++) {
            if(state[i] == NOT_VISTED) {
                int cur = i;
                while(1) {
                    state[cur] = i;
                    cur = arr[cur];

                    // cycle in
                    if(state[cur] == i) {
                        while(state[cur] != -1) {
                            state[cur] = -1;
                            cur = arr[cur];
                        }
                        break;
                    }
                    // 이전에 방문한 기록이 있는 노드를 방문했을 때 = not cycle
                    else if(state[cur] != 0) break;
                }
            }
        }

        // count not cycle node
        int count = 0;
        for(int i=1; i<=n; i++) {
            if(state[i] != -1) count++;
        }
        cout << count << "\n";
    }
}