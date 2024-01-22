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

int N, M;
vector<int> schedules;
vector<int> multitab;
 
void Solve() {
    int answer = 0;
    for(int i = 0; i < M; ++i){
        bool check = false;
        // 이미 꼽은 상태
        for(int m = 0; m < N; ++m){
            if(multitab[m] == schedules[i]) {
                check = true;
                break;
            }
        }
        if(check) continue;

        // 빈자리 존재

        for(int m = 0; m < N; ++m){
            if(!multitab[m]) {
                multitab[m] = schedules[i];
                check = true;
                break;
            }
        }
        if(check) continue;

        // 빈자리 없음

        int idx = -1;
        int maxGap = -1;
        for(int m = 0; m < N; ++m){
            int gap = 0;
            for(int next = i + 1; next < M; ++next){
                if(schedules[next] == multitab[m]){
                    break;
                }
                ++gap;
            }

            if(maxGap < gap){
                idx = m;
                maxGap = gap;
            }
        }
        multitab[idx] = schedules[i];
        ++answer;
    }

    cout << answer;
}

void Input() {
    cin >> N >> M;
    schedules.resize(M);
    multitab.resize(N, 0);
    for(auto& a : schedules){
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