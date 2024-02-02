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
    std::sort(arr.begin(), arr.end());

    int answer = INT32_MAX;
    int left = 0;
    int right = 1;

    while(left < N && right < N){
        int result = arr[right] - arr[left];
        if(M <= result){
            answer = std::min(answer, result);
            ++left;
        }else {
            ++right;
        }
    }

    cout << answer;
    return;
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
