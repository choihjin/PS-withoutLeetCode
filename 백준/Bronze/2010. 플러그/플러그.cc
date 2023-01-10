#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    int num = 0;
    int plug = 0;
    int result = 0;

    cin >> num;
    for(int i=0; i<num; i++) {
        cin >> plug;
        if(i==num-1) result += plug;
        else result += plug-1;
    }

    cout << result << endl;
    return 0;
}