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
vector<int> arr[4];

vector<int> cache[2];

void Solve() {
    long long answer = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            cache[0].push_back(arr[0][i] + arr[1][j]);
            cache[1].push_back(arr[2][i] + arr[3][j]);
        }
    }

    std::sort(cache[0].begin(), cache[0].end());
    std::sort(cache[1].begin(), cache[1].end());

    for(int i = 0; i < N * N; ++i){
        int target = cache[0][i] * -1;

        int left = std::lower_bound(cache[1].begin(), cache[1].end(), target) - cache[1].begin();
        int right = std::upper_bound(cache[1].begin(), cache[1].end(), target) - cache[1].begin();

        answer += right - left;
    }

    cout << answer;
    return;
}

void Input() {
    cin >> N;
    for(int i = 0; i < 4; ++i){
        arr[i].resize(N);
    }
    cache[0].reserve(N * N);
    cache[1].reserve(N * N);
    
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < 4; ++j){
            cin >> arr[j][i];
        }
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
