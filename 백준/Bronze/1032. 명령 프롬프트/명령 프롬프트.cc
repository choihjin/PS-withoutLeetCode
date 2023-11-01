#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    n--;

    string res;
    cin >> res;
    while(n--) {
        string buffer;
        cin >> buffer;
        for(int i=0; i<res.length(); i++) 
            if(res[i] != buffer[i]) res[i] = '?';
    }
    cout << res << endl;
}