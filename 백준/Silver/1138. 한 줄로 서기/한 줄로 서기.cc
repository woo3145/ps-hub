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

int N;
vector<int> info;


void Input() {
    cin >> N;
    info.resize(N);
    for(auto& n : info){
        cin >> n;
    }
}

void Solve() {
    vector<int> answer;
    answer.assign(N, 0);

    for(int i = 0; i < N; ++i){
        int pos = 0;

        while(info[i]){
            if(answer[pos] == 0){
                --info[i];
            }
            ++pos;
        }

        while(answer[pos] != 0){
            ++pos;
        }
        answer[pos] = i + 1;
    }

    for(auto& a : answer){
        cout << a << ' ';
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
