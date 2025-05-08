#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define REMAIN first
#define MOVE second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;
pair<int, int> ans = {0x7f7f7f7f, 0x7f7f7f7f};
vector<string> board(5);

void dfs(int pinCount, int moveCount) {
    bool moved = false;

    for(int x = 0; x < 5; x++) {
        for(int y = 0; y < 9; y++) {
            if(board[x][y] != 'o') continue;

            for(int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int jx = x + dx[dir] * 2;
                int ny = y + dy[dir];
                int jy = y + dy[dir] * 2;

                if (nx < 0 || nx >= 5 || ny < 0 || ny >= 9 ||
                    jx < 0 || jx >= 5 || jy < 0 || jy >= 9) continue;
                
                if(board[nx][ny] == 'o' && board[jx][jy] == '.') {
                    board[x][y] = '.';
                    board[nx][ny]  = '.';
                    board[jx][jy] = 'o';

                    dfs(pinCount-1, moveCount+1);

                    board[x][y] = 'o';
                    board[nx][ny]  = 'o';
                    board[jx][jy] = '.';

                    moved = true;
                }
            }
        }
    }

    if(!moved) {
        if (pinCount < ans.REMAIN) {
            ans.REMAIN = pinCount;
            ans.MOVE = moveCount;
        }
        else if (pinCount == ans.REMAIN) {
            ans.MOVE = min(ans.MOVE, moveCount);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--) {
        int cnt = 0;
        ans = {0x7f7f7f7f, 0x7f7f7f7f};

        for(int i = 0; i < 5; i++) {
            cin >> board[i];
            for(auto c : board[i]) 
                if(c == 'o') cnt++;
        }

        dfs(cnt, 0);
        cout << ans.REMAIN << " " << ans.MOVE << endl;
    }

    return 0;
}