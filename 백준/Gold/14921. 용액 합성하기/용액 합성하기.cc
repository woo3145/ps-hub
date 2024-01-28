#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <list>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;
using std::deque;
using std::string;
using std::deque;
using std::list;

int N;
vector<int> arr;

void Solve() {

    int left = 0;
    int right = N - 1;

    int answer = INT32_MAX;
    while(left < right){
        int result = arr[left] + arr[right];

        if(std::abs(answer) > std::abs(result)){
            answer = result;
        }

        if(0 < result){
            --right;
        }else{
            ++left;
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
