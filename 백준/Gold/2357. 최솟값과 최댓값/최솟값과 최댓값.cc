#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> arr;
vector<int> minTree, maxTree;

// 트리 초기화
int initMin(int node, int start, int end) {
    if (start == end) return minTree[node] = arr[start];
    int mid = (start + end) / 2;
    return minTree[node] = min(initMin(node*2, start, mid), initMin(node*2+1, mid+1, end));
}

int initMax(int node, int start, int end) {
    if (start == end) return maxTree[node] = arr[start];
    int mid = (start + end) / 2;
    return maxTree[node] = max(initMax(node*2, start, mid), initMax(node*2+1, mid+1, end));
}

// 최솟값 쿼리
int queryMin(int node, int start, int end, int left, int right) {
    if (right < start || end < left) return INT_MAX;
    if (left <= start && end <= right) return minTree[node];
    int mid = (start + end) / 2;
    return min(queryMin(node*2, start, mid, left, right),
               queryMin(node*2+1, mid+1, end, left, right));
}

// 최댓값 쿼리
int queryMax(int node, int start, int end, int left, int right) {
    if (right < start || end < left) return INT_MIN;
    if (left <= start && end <= right) return maxTree[node];
    int mid = (start + end) / 2;
    return max(queryMax(node*2, start, mid, left, right),
               queryMax(node*2+1, mid+1, end, left, right));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    arr.resize(N);
    minTree.resize(4*N);
    maxTree.resize(4*N);

    for (int i = 0; i < N; ++i) cin >> arr[i];

    initMin(1, 0, N-1);
    initMax(1, 0, N-1);

    while (M--) {
        int a, b;
        cin >> a >> b;
        // 문제는 1-indexed, 벡터는 0-indexed라서 보정 필요
        cout << queryMin(1, 0, N-1, a-1, b-1) << " ";
        cout << queryMax(1, 0, N-1, a-1, b-1) << "\n";
    }

    return 0;
}
