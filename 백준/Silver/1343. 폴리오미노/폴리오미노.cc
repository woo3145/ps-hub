#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;

string str;
vector<int> xCnt;


void Input() {
   cin >> str;
}

void Solve() {
    int cnt = 0;
    char prev;
    for(auto& c : str){
        if(c == 'X'){
            ++cnt;
        }else if(prev == 'X' && c == '.') {
            xCnt.push_back(cnt);
            cnt = 0;
        }
        prev = c;
    }
    if(0 < cnt){
        xCnt.push_back(cnt);
    }

    int xIdx = 0;
    string answer = "";
    for(int i = 0; i < str.length(); ++i){
        if(str[i] == '.'){
            answer += str[i];
            continue;
        }
        if(xCnt[xIdx] & 1){
            cout << -1;
            return;
        }
        i += xCnt[xIdx] - 1;
        while(xCnt[xIdx]){
            if(2 < xCnt[xIdx]){
                answer += "AAAA";
                xCnt[xIdx] -= 4;
            }else{
                answer += "BB";
                xCnt[xIdx] = 0;
            }
        }
        ++xIdx;
    }

    cout << answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    Input();
    Solve(); 
    
    return 0;
}
