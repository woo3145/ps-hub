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

struct Egg {
    int h, w;
};

int N;
vector<Egg> eggs;
vector<bool> visited;

int answer = 0;

void dfs(int cur) {
    if(cur == N) {
        int cnt = 0;
        for(auto& e : eggs){
            if(e.h <= 0) {
                ++cnt;
            }
        }
        answer = std::max(answer, cnt);
        return;
    }

    for(int i = 0; i < N; ++i){
        if(cur == i) continue;
        if(eggs[cur].h <= 0 || eggs[i].h <= 0) {
            dfs(cur + 1);
        }else{
            eggs[cur].h -= eggs[i].w;
            eggs[i].h -= eggs[cur].w;
            dfs(cur + 1);
            eggs[cur].h += eggs[i].w;
            eggs[i].h += eggs[cur].w;
        }
    }
}

void Solve() {
    dfs(0);

    cout << answer;
}

void Input() {
    cin >> N;
    eggs.resize(N);
    visited.assign(N, false);

    for(auto& e : eggs){
        cin >> e.h >> e.w;
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