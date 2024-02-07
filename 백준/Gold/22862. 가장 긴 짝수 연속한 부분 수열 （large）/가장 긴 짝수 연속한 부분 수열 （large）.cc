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

int N, K;
vector<int> arr;

void Solve() {
    int answer = 0;

    int left = 0;
    int right = 0;
    int cnt = 0;

    while(right < N){
        if(K < cnt){
            if(arr[left] % 2 == 1) {
                --cnt;
            }
            ++left;
        }else {
            if(arr[right] % 2 == 1) {
                ++cnt;
            }
            ++right;
        }
        answer = std::max(answer, right - left - cnt);
    }
    
    cout << answer;
}

void Input() {
    cin >> N >> K;
    arr.resize(N);
    for(auto& a : arr) {
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
