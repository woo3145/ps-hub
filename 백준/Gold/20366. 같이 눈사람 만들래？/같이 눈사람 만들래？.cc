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

int N;
vector<int> arr;

void Solve() {
    int answer = INT32_MAX;
    std::sort(arr.begin(), arr.end());

    for(int i = 0; i < N; ++i){
        for(int j = i + 1; j < N; ++j){
            int aSum = arr[i] + arr[j];
            int left = 0;
            int right = N - 1;

            while(left < right){
                if(left == i || left == j) {
                    ++left;
                    continue;
                }
                if(right == i || right == j){
                    --right;
                    continue;
                }

                int bSum = arr[left] + arr[right];
                int gap = aSum - bSum;
                if(gap == 0) {
                    cout << 0;
                    return;
                }
                if(gap < 0) --right;
                if(0 < gap) ++left;

                answer = std::min(answer, std::abs(gap));
            }
        }
    }
    cout << answer;
}

void Input() {
    cin >> N;
    arr.resize(N);
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
