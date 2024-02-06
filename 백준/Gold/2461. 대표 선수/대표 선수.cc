#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;
using std::map;
using std::string;
using std::queue;

int N, M;
vector<int> arr[1001];

void Solve() {
    int answer = INT32_MAX;
    vector<int> cur;
    cur.resize(N);
    for(auto& a : cur) a = M - 1;

    while(true) {
        int max = arr[0][cur[0]];
        int maxIdx = 0;
        int min = arr[0][cur[0]];

        for(int i = 1; i < N; ++i){
            if(max < arr[i][cur[i]]){
                max = arr[i][cur[i]];
                maxIdx = i;
            }
            if(min > arr[i][cur[i]]){
                min = arr[i][cur[i]];
            }
        }
        answer = std::min(answer, max - min);
        --cur[maxIdx];
        if(cur[maxIdx] < 0) break;
    }

    cout << answer;
}

void Input() {
    cin >> N >> M;
    for(int i = 0; i < N; ++i){
        arr[i].resize(M);
        for(int j = 0; j < M; ++j){
            cin >> arr[i][j];
        }
        std::sort(arr[i].begin(), arr[i].end());
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
