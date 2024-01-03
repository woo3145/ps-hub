#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;

int N, K;
vector<int> points;

void Input() {
    cin >> N >> K;
    points.resize(N);

    for(auto& p : points){
        cin >> p;
    }
}

void Solve() {
    int answer = 0;

    vector<int> cache;
    cache.resize(N - 1);

    // 가장 가까운 지점끼리 거리구하기
    std::sort(points.begin(), points.end());
    for(int i = 0; i < N - 1; ++i){
        cache[i] = points[i+1] - points[i];
    }
    // 오름차순 정렬해서 가장 긴 구간 K-1개 없애기
    std::sort(cache.begin(), cache.end());
    for(int i = 0; i < N - K; ++i){
        answer += cache[i];
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
