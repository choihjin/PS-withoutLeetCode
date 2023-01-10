#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int a, b, c;
    int result;
    vector<int> v(10);

    cin >> a;
    cin >> b;
    cin >> c;
    result = a * b * c;

    string s = to_string(result);
    for(int i=0; i<s.size(); i++) {
        v.at(s[i]-48)++;
    }

    for(int i=0; i<v.size(); i++) {
        cout << v[i] << endl;
    }
}