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

typedef long long ll;

int N;
vector<ll> arr;
vector<ll> result;
void Solve() {
    ll answer = INT64_MAX;
    result.resize(3, 0);

    std::sort(arr.begin(), arr.end());
    for(int i = 0; i < N - 2; ++i){
        int curL = i + 1;
        int curR = N -1;

        while(curL < curR){
            ll sum = arr[i] + arr[curL] + arr[curR];

            if(std::abs(sum) < answer){
                answer = std::abs(sum);
                result[0] = arr[i];
                result[1] = arr[curL];
                result[2] = arr[curR];
            }
            if(sum < 0){
                ++curL;
            }else{
                --curR;
            }
        }
    }

    for(auto& a : result){
        cout << a << ' ';
    }
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
