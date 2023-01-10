#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> num;

    int buffer;
    for(int i=0; i<10; i++) {
        cin >> buffer;
        buffer %= 42;

        bool add = true;
        for(int j=0; j<num.size(); j++) {
            if(buffer == num[j]) {
                add = false;
                break;
            }
        }
        if(add) num.push_back(buffer);
    }

    cout << num.size() << endl;
    return 0;
}