#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;

int N, M;
vector<int> arr;

int check(int gap) {
    int cnt = 1;

    int prev = 0;
    for(int i = 1; i < N; ++i){
        if(gap <= arr[i] - arr[prev]){
            ++cnt;
            prev = i;
        }
    }
    return cnt;
}

void Solve() {
    int answer = 0;
    std::sort(arr.begin(), arr.end());

    int left = 1;
    int right = arr[N - 1] - arr[0];

    while(left <= right){
        int mid = (left + right) / 2;

        int cnt = check(mid);
        if(M <= cnt){
            answer = mid;
            left = mid + 1;
        }else {
            right = mid - 1;
        }
    }

    cout << answer;
}

void Input() {
    cin >> N >> M;
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
