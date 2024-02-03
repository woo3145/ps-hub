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
vector<int> arr;

void Solve() {
    long long answer = 0;
    std::sort(arr.begin(), arr.end());

    for(int i = 0; i < N - 2; ++i){
        for(int j = i + 1; j < N - 1; ++j){
            int tmp = (arr[i] + arr[j]) * -1;
            int left = std::lower_bound(arr.begin() + j + 1, arr.end(), tmp) - arr.begin();
            int right = std::upper_bound(arr.begin() + j + 1, arr.end(), tmp) - arr.begin();

            answer += right - left;
        }
    }

    cout << answer;
    return;
}

void Input() {
    cin >> N;
    arr.resize(N);
    for(auto& n : arr){
        cin >> n;
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
