#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int arr[26] = {0,};
    cin >> s;

    for(int i=0; i<s.size(); i++) {
        int index = s[i] - 'a';
        arr[index]++;
    }

    for(int i : arr) cout << i << " ";
}