#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int num;
    string name;
    vector<char> ch;
    vector<int> count;
    cin >> num;
    
    for(int i=0; i<num; i++) {
        cin >> name;

        bool check = false;
        for(int j=0; j<ch.size(); j++) {
        if(ch[j] == name[0]) {
            check = true;
            count[j]++;
            break;
        }
        }

        if(!check) {
        ch.push_back(name[0]);
        count.push_back(1);
        }
    }

    string result = "";
    int index;
    for(int i=0; i<count.size(); i++) {
        if(count[i] >= 5) {
        string buffer(1, ch[i]);

        index = -1;
        for(int j=0; j<result.size(); j++) {
            if(result[j] > ch[i]) {
                index = j;
                break;
            }
        }

        if(index == -1) result += buffer;
        else {
            string buffer;
            buffer += ch[i];
            result.insert(index, buffer);
        }
        }
    }
    
    if(result == "") {
        cout << "PREDAJA" << endl;
    } else {
        cout << result << endl;
    }
}