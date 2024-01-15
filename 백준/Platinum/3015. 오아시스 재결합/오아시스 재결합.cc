#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::pair;

typedef long long ll;

int N;
vector<ll> arr;

void Solve() {
    ll answer = 0;
    vector<pair<ll, ll>> st;
    
    for(int i = 0; i < N; ++i){
        int cnt = 1; // 키가 같은 사람

        while(!st.empty() && st.back().first <= arr[i]){

            answer += st.back().second;

            if(st.back().first == arr[i]){
                cnt = st.back().second + 1;
            }else {
                cnt = 1;
            }

            st.pop_back();
        }
        if(!st.empty()) {
            answer += 1;
        }
        st.push_back({arr[i], cnt});
    }

    cout << answer;
}

void Input() {
    cin >> N;
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

