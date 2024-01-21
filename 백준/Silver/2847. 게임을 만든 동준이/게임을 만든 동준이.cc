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

int N;
vector<int> levels;
 
void Solve() {
    int answer = 0;
    int cur = levels[N - 1] - 1;
    for(int i = N - 2; 0 <= i; --i){
        if(cur < levels[i]){
            answer += levels[i] - cur;
            --cur;
        }else {
            cur = levels[i] - 1;
        }
    }

    cout << answer;
}

void Input() {
    cin >> N;
    levels.resize(N);
    for(auto& l : levels){
        cin >> l;
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
