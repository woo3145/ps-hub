#include <iostream>
#include <string>

using std::ios;
using std::cout;
using std::cin;
using std::string;

string a_str, b_str;

void Input() {
    cin >> a_str >> b_str;
}


void Solve() {
    const int A_LENGTH = a_str.size();
    const int B_LENGTH = b_str.size();
    int answer = 0;
    for(int i = 0; i < B_LENGTH - A_LENGTH + 1; ++i){
        int cnt = 0;
        for(int j = 0; j < A_LENGTH; ++j){
            if(a_str[j] == b_str[i + j]) ++cnt;
        }
        if(answer < cnt) answer = cnt;
    }

    cout << A_LENGTH - answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    Input();
    Solve();
    
    return 0;
}