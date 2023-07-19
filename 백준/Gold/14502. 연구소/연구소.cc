#include <bits/stdc++.h>
using namespace std;

int matrix[10][10];
int origin[10][10];
int n, m, res = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void copy(int a[10][10], int b[10][10]){
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            a[i][j] = b[i][j];
} 

void bfs() {
    int spread[10][10];
    copy(spread, matrix);

    queue<pair<int, int>> Q;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(spread[i][j] != 2) continue;
            Q.push({i, j});
        }
    }

    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        for(int k=0; k<4; k++) {
            int nx = cur.first + dx[k];
            int ny = cur.second + dy[k];
            if(nx < 0 || nx >= n || ny <0 || ny >= m) continue;
            if(spread[nx][ny] != 0) continue;
            spread[nx][ny] = 2;
            Q.push({nx, ny});
        }
    }

    int cnt = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(spread[i][j] == 0) cnt++;

    res = max(res, cnt);
}

void wall(int cnt){
    if(cnt == 3){
        bfs();
        return;
    }

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            if(matrix[i][j]==0){
                matrix[i][j] = 1;
                wall(cnt+1);
                //기존의 1을 0으로 바꿔줌
                matrix[i][j] = 0;
            }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> origin[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(origin[i][j] == 0){
                copy(matrix, origin);
                matrix[i][j] = 1;
                wall(1);
                matrix[i][j] = 0;
            }
        }
    }
    
    cout << res << "\n";

    return 0;
}