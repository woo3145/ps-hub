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

int N, M;
vector<int> arr;

void Solve() {
    int left = 0;
    int right = 0;
    int sum = arr[right];
    int answer = 0;
    while(left <= N && right < N){
        if(sum == M) ++answer;
        if(sum < M){
            sum += arr[++right];
        }else{
            sum -= arr[left++];
        }
    }
    cout << answer;
}

void Input() {
    cin >> N >> M;
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
