#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    int num;
    cin >> num;

    string s;
    getline(cin, s);
    stringstream ss;
    int student;
    int buffer;
    vector<int> score;
    vector<float> per;
    for(int i=0; i<num; i++) {
        getline(cin, s);
        ss.str(s);
        ss >> student;
    
        float avg = 0.0;
        while(ss >> buffer) {
            score.push_back(buffer);
            avg += float(buffer);
        }
        
        int student_upper = 0;
        avg = float(avg / student);
        for(int j=0; j<student; j++) {
            if(score[j] > avg) student_upper++;
        }
        
        per.push_back((float(student_upper) / float(student)));
        score.clear();
        ss.clear();
    }

    for(int i=0; i<per.size(); i++) {
        cout << fixed;
        cout.precision(3);
        cout << per[i] * 100 << "%" << endl;
    }
}