#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define ull unsigned long long

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;

int N;
vector<pair<ull, ull>> info; 


void Input() {
    cin >> N;
    info.resize(N);
    
    for(auto& a : info) cin >> a.first;
    for(auto& a : info) cin >> a.second;
}

void Solve() {
    ull answer = 0;

    // 사용일이 얼마 안남은거 부터 정렬 (같으면 연장일 적은거)
    std::sort(info.begin(), info.end(), [](const pair<ull, ull>& a, const pair<ull,ull>& b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second < b.second;
    });


    ull prevMax = info[0].first;
    ull curSection = info[0].second;
    for(int i = 0; i < N; ++i){
        if(curSection > info[i].first){
            // 이전 구간의 최댓값보다 현재 쿠폰의 사용일이 더 많이남음
            if(prevMax < info[i].second) {
                curSection = info[i].second;
            }

            ull tmp = (curSection - info[i].first + 29) / 30;
            info[i].first += (30 * tmp);
            answer += tmp;
        }

        prevMax = prevMax < info[i].first ? info[i].first : prevMax;
        if(i != N - 1 && info[i].second != info[i + 1].second){
            curSection = prevMax;
        }
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
