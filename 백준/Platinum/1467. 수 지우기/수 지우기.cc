#include <iostream>
#include <vector>
#include <string>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;

string N, R;
int nCount[10];
int rCount[10];

void Input() {
    cin >> N >> R;

    for(auto& c : N){
        ++nCount[c - '0'];
    }
    for(auto& c : R){
        ++rCount[c - '0'];
    }
}

// 221231
// 12

void Solve() {
    vector<int> answer;
    answer.reserve(N.length() - R.length());

    for(auto& c : N){
        int cur = c - '0';
        // 현재 숫자를 넣을 빈자리가 없을때
        if(0 < rCount[cur] && nCount[cur] == rCount[cur]) {
            --nCount[cur];
            --rCount[cur];
            continue;
        };

        while(!answer.empty()){
            int answerTop = answer.back();
            // 정답배열의 마지막이 현재 숫자보다 작으면서 해당 수가 지워야되는 수면 pop
            if(!rCount[answerTop]) break;
            if(cur <= answerTop) break;

            --rCount[answerTop];
            answer.pop_back();
        }
        --nCount[cur];
        answer.push_back(cur);
    }

    for(auto& a : answer){
        cout << a ;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    Input();
    Solve();

    return 0;
}
