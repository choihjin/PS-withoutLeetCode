#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n;
int board[102][102];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        vector<int> dir;
        dir.push_back(d);

        for (int gen = 0; gen < g; gen++) {
            int size = dir.size();
            for (int i = size - 1; i >= 0; i--) 
                dir.push_back((dir[i] + 1) % 4);
        }

        board[x][y] = 1;
        for(auto d : dir) {
            x += dx[d];
            y += dy[d];
            if (x >= 0 && x <= 100 && y >= 0 && y <= 100)
                board[x][y] = 1;
        }
    }
    
    // search
    int ans = 0;
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            if(board[i][j] && board[i+1][j] && board[i][j+1] && board[i+1][j+1])
                ans++;  
            
        }
    }

    cout << ans << endl;

    return 0;
}