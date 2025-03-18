#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

typedef long long ll;
int n;
int arr[1000002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<int> tail;
    for(int i = 0; i < n; i++) {
        auto iter = lower_bound(tail.begin(), tail.end(), arr[i]);

        if(iter == tail.end()) 
            tail.push_back(arr[i]);
        else
            *iter = arr[i];
    }

    cout << tail.size() << endl;

    return 0;
}