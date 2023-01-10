#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    int first;

    cin >> N >> first;
    if(N > 5) cout << "Love is open door" << endl;
    else {
        for(int i=1; i<N; i++) {
            if(i%2 == 0) cout << first << endl;
            else cout << !first << endl;
        }
    }

    return 0;
}