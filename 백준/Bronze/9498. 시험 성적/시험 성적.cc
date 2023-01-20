#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    //90 ~ 100점은 A, 80 ~ 89점은 B, 70 ~ 79점은 C, 60 ~ 69점은 D, 나머지 점수는 F
    if(n >= 90) cout << "A";
    else if(n >= 80) cout << "B";
    else if(n >= 70) cout << "C";
    else if(n >= 60) cout << "D";
    else cout << "F";
}