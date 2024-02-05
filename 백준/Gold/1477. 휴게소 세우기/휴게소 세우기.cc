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

int N, M, L;
vector<int> arr;


bool check(int gap) {
    int cnt = 0;

    for(int i = 1; i < arr.size(); ++i) {
        int dist = arr[i] - arr[i-1];
        cnt += dist / gap;
        if(dist % gap == 0) --cnt;
    }

    return M < cnt;
}

void Solve() {
    int answer = INT32_MAX;
    std::sort(arr.begin(), arr.end());

    int left = 1;
    int right = L;

    while(left <= right){
        int mid = (left + right) / 2;

        if(check(mid)){
            left = mid + 1;
        }else{
            answer = mid;
            right = mid - 1;
        }
    }
    cout << answer;
}

void Input() {
    cin >> N >> M >> L;
    arr.resize(N);
    for(auto& a : arr){
        cin >> a;
    }
    arr.push_back(0);
    arr.push_back(L);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input();
    Solve();
    
    return 0;
}
