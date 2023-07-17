#include <bits/stdc++.h>
using namespace std;

int matrix[27][27];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int n, buffer;
    string tmp;
    stringstream ss;

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> tmp;
        for(int j=0; j<n; j++) {
            if(tmp[j] == '1') matrix[i][j] = -1;
            else matrix[i][j] = 0;
        }
    }
    
    int cnt = 0;
    vector<int> nums;
    stack<pair<int, int>> S;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(matrix[i][j] != -1) continue;
            S.push({i, j});
            matrix[i][j] = ++cnt;
            buffer = 1;
            while(!S.empty()) {
                pair<int, int> cur = S.top(); S.pop();
                for(int k=0; k<4; k++) {
                    int nx = dx[k] + cur.first;
                    int ny = dy[k] + cur.second;

                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(matrix[nx][ny] != -1) continue;
                    matrix[nx][ny] = cnt;
                    S.push({nx, ny});
                    buffer++;
                }
            }
            nums.push_back(buffer);
        }
    }

    cout << cnt << "\n";
    sort(nums.begin(), nums.end());
    for(auto a : nums)
        cout << a << "\n";
}