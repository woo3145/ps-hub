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
using std::deque;
using std::queue;


int N, K;
vector<int> arr;
void Solve() {
    std::sort(arr.begin(), arr.end());

    int left = 0;
    int right = arr[N - 1];
    int answer = 0;

    while(left <= right){
        int sum = 0;
        int mid = (left + right) / 2;

        for(int i = 0; i < N; ++i){
            sum += mid < arr[i] ? mid : arr[i];
        }

        if(sum <= K){
            answer = mid;
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }

    cout << answer;
}

void Input() {
    cin >> N;
    arr.resize(N);

    for(auto& n : arr){
        cin >> n;
    }
    cin >> K;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input();
    Solve();
    
    return 0;
}
