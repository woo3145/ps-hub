#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;
using std::queue;
using std::string;
using std::priority_queue;

int N;
vector<pair<int,int>> arr;
 
void Solve() {
    int answer = 0;
    std::sort(arr.begin(), arr.end());

    int start = arr[0].first;
    int end = arr[0].second;

    for(int i = 1; i < arr.size(); ++i){
        if(end < arr[i].first){
            answer += (end - start);
            start = arr[i].first;
            end = arr[i].second;
            continue;
        }

        if(end < arr[i].second) end = arr[i].second;
    }
    answer += (end - start);
    
    cout << answer;
}

void Input() {
    cin >> N;
    arr.resize(N);
    for(auto& a : arr){
        cin >> a.first >> a.second;
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