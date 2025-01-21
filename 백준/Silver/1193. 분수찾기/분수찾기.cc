#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main() {
    int x;
    cin >> x;

    int i = 1;
    while(x > i) {
        x -= i++;
    }

    if(i % 2 == 0)  {
        cout << x << "/" << i + 1 - x << endl;
    }
    else {
        cout << i+1-x << "/" << x << endl;
    }
}