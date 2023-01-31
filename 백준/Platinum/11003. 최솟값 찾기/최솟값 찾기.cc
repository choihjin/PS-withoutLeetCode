#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    deque<pair<int, int> > D;
    int n, l;

    cin >> n >> l;
    for(int i=0; i<n; i++) {
        int buffer;
        cin >> buffer;
        
        // 새로운 숫자가 deque내에서 가장 큰 값의 숫자이고 마지막에 위치하도록
        // deque안의의 숫자들은 오름차순 상태를 유지하게 되고, 구간내 가장 작은값은 항상 맨앞(front)에 있는 상태
        while(!D.empty() && D.back().second >= buffer) D.pop_back();

        // 새로운 숫자는 항상 삽입
        pair<int, int> p;
        p.first = i;
        p.second = buffer;
        D.push_back(p);

        // 주어진 구간을 벗어나는 outdate된 숫자들은 제거
        if(D.front().first <= i - l) D.pop_front();

        cout << D.front().second << " ";
    }
}