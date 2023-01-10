#include <iostream>

using namespace std;

int main() {
    string input;
    cin >> input;

    string buffer = "";
    for(int i=0; i<input.size(); i++) {
        if(i != 0 && i%10 == 0) {
            cout << buffer << endl;
            buffer = input[i];
        } else {
            buffer += input[i];
        }
    }
    if(buffer != "") cout << buffer << endl;

    return 0;
}