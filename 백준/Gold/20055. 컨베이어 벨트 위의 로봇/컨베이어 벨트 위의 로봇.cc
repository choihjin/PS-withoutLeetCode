#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define dur first
#define robot second

// 1. 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전
// 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동. 만약 이동할 수 없다면 가만히
// 3. 로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 함
// 4. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올림
// 5. 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료

int n, k;
deque<pair<int, bool>> arr;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i=0; i<2*n; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back({tmp, false});
    }

    int stage = 0;
    int zero = 0;
    while(zero < k) {
        stage++;

        // 1. 벨트 회전
        auto tmp = arr.back();
        arr.pop_back();
        arr.push_front(tmp);

        // 로봇 내림
        arr[n-1].robot = false;

        // 2. 로봇 이동 
        for(int i=n-2; i>=0; i--) {
            // 2-1. 이동하려는 칸에 로봇이 없고 그 칸의 내구도가 1 이상
            if(arr[i].robot && !arr[i+1].robot && arr[i+1].dur) {
                arr[i+1].robot = true;
                arr[i].robot = false;
                arr[i+1].dur--;
            }
        }
        
        // 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 로봇을 올림
        if(arr[0].dur) {
            arr[0].robot = true;
            arr[0].dur--;
        }

        // 4. 내구도가 0인 칸의 개수 카운트
        zero = 0;
        for(int i=0; i<n*2; i++) 
            if(arr[i].dur == 0) zero++;

        // 로봇 내림
        arr[n-1].robot = false;
    }

    cout << stage << endl;

    return 0;
}