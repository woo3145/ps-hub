#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;
using std::queue;
using std::string;

int L, C;
vector<char> arr;
vector<char> answer;

void backTracking(int cur, int idx, int a, int b){
    if(cur == L){
        if(1 <= a && 2 <= b){
            for(auto& c : answer){
                cout << c;
            }
            cout << '\n';
        }
        return;
    }

    for(int i = idx; i < C; ++i){
        answer[cur] = arr[i];
        if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u'){
            backTracking(cur + 1, i + 1, a + 1, b);
        }else{
            backTracking(cur + 1, i + 1, a, b + 1);
        }
    }
}

void Solve() {
    std::sort(arr.begin(), arr.end());

    backTracking(0, 0, 0, 0);
}

void Input() {
    cin >> L >> C;
    arr.resize(C);
    answer.resize(L, 0);

    for(auto& a : arr){
        cin >> a;
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