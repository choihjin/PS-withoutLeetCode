#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define TOP 0
#define EAST 1
#define WEST 2
#define NORTH 3
#define SOUTH 4
#define BOTTOM 5

int n, m, x, y, k;
int dice[6] = {1, 3, 4, 2, 5, 6};
int board[22][22];
int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};
int rot[5] = {0, SOUTH, NORTH, EAST, WEST}; // rotate
int rev_rot[5] = {0, NORTH, SOUTH, WEST, EAST}; // revere rotate

void roll(int dir) {
    int east, west, south, north, top, bottom;
    east = dice[EAST];
    west = dice[WEST];
    south = dice[SOUTH];
    north = dice[NORTH];
    top = dice[TOP];
    bottom = dice[BOTTOM];

    if(dir == EAST) {
        dice[EAST] = top;
        dice[WEST] = bottom;
        dice[TOP] = west;
        dice[BOTTOM] = east;
    }
    else if(dir == WEST) {
        dice[EAST] = bottom;
        dice[WEST] = top;
        dice[TOP] = east;
        dice[BOTTOM] = west;
    }
    else if(dir == SOUTH) {
        dice[NORTH] = bottom;
        dice[TOP] = north;
        dice[SOUTH] = top;
        dice[BOTTOM] = south;
    }
    else {
        dice[NORTH] = top;
        dice[TOP] = south;
        dice[SOUTH] = bottom;
        dice[BOTTOM] = north;
    }
}

int bfs() {
    int num = board[x][y];
    int visited[22][22] = {0};
    queue<pair<int, int>> Q;
    
    Q.push({x, y});
    visited[x][y] = 1;

    int cnt = 0;
    while(!Q.empty()) {
        int cx, cy;
        tie(cx, cy) = Q.front(); Q.pop();
        cnt++;

        for(int d = 1; d < 5; d++) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(board[nx][ny] != num || visited[nx][ny]) continue;

            Q.push({nx, ny});
            visited[nx][ny] = 1;
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i=0; i<n; i++) 
        for(int j=0; j<m; j++)
            cin >> board[j][i];

    int dir = EAST;
    int score = 0;
    while(k--) {
        int nx, ny;
        nx = x + dx[dir];
        ny = y + dy[dir];
        
        if(nx < 0 || nx >= m || ny < 0 || ny >= n) {
            dir % 2 == 0 ? dir-- : dir++;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }

        roll(dir);
        x = nx;
        y = ny;

        // get score
        score += bfs() * board[x][y];
        
        if(dice[BOTTOM] > board[x][y]) dir = rot[dir];
        else if(dice[BOTTOM] < board[x][y]) dir = rev_rot[dir];
    }

    // cout << dir << endl;
    // cout << "\t" << dice[3] << endl;
    // cout << dice[2] << "\t" << dice[0] << "\t" << dice[1] << endl;
    // cout << "\t" << dice[4] << endl;
    // cout << "\t" << dice[5] << endl; 
    cout << score << endl;

    return 0;
}