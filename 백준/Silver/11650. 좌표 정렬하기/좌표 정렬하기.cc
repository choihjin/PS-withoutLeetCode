#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> arr[1000002];
pair<int, int> tmp[1000002];

// mid = (st+en)/2라고 할 때 arr[st:mid], arr[mid:en]은 이미 정렬이 되어있는 상태일 때 arr[st:mid]와 arr[mid:en]을 합친다.
void merge(int st, int en){
    int mid = (st+en)/2;
    int lidx = st;
    int ridx = mid;
    for(int i=st; i<en; i++) {
        if(lidx == mid) {
            tmp[i].first = arr[ridx].first;
            tmp[i].second = arr[ridx].second;
            ridx++;
        }     
        else if(ridx == en) {
            tmp[i].first = arr[lidx].first;
            tmp[i].second = arr[lidx].second;
            lidx++;
        }
        else if(arr[lidx].first > arr[ridx].first) {
            tmp[i].first = arr[ridx].first;
            tmp[i].second = arr[ridx].second;
            ridx++;
        }
        else if(arr[lidx].first < arr[ridx].first) {
            tmp[i].first = arr[lidx].first;
            tmp[i].second = arr[lidx].second;
            lidx++;
        }
        else {
            if(arr[lidx].second >= arr[ridx].second) {
                tmp[i].first = arr[ridx].first;
                tmp[i].second = arr[ridx].second;
                ridx++;
            }
            else {
                tmp[i].first = arr[lidx].first;
                tmp[i].second = arr[lidx].second;
                lidx++;
            }
        }
    }

    for(int i=st; i<en; i++) {
        arr[i].first = tmp[i].first;
        arr[i].second = tmp[i].second;
    }
}

// arr[st:en]을 정렬하고 싶다.
void merge_sort(int st, int en){
    if(en-st == 1) return; // 길이 1인 경우
    int mid = (st+en)/2;
    merge_sort(st, mid); // arr[st:mid]을 정렬한다.
    merge_sort(mid, en); // arr[mid:en]을 정렬한다.
    merge(st, en); // arr[st:mid]와 arr[mid:en]을 합친다.
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int a, b;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        arr[i] = {a, b};
    }
    merge_sort(0, n);
    for(int i = 0; i < n; i++) cout << arr[i].first << " " << arr[i].second << "\n";
}