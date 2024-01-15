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
    vector<ll> left(N, 0);
    vector<ll> right(N, 0);
    vector<pair<ll, ll>> st;

    for(int i = 0; i < N; ++i){
        while(!st.empty() && arr[i] <= st.back().first) st.pop_back();

        if(st.empty()) left[i] = -1;
        else left[i] = st.back().second;

        st.push_back({arr[i], i});
    }
    st.clear();
    for(int i = N - 1; 0 <= i; --i){
        while(!st.empty() && arr[i] <= st.back().first) st.pop_back();

        if(st.empty()) right[i] = N;
        else right[i] = st.back().second;

        st.push_back({arr[i], i});
    }

    ll answer = 0;
    for(int i = 0; i < N; ++i){
        ll tmp = arr[i] * (right[i] - left[i] - 1);
        answer = std::max(answer, tmp);
    }

    cout << answer << '\n';
}

void Input() {
    cin >> N;
    if(N == 0) return;
    arr.clear();
    arr.resize(N);
    for(auto& n : arr){
        cin >> n;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while(true){
        Input();
        if(N == 0) break;
        Solve(); 
    }   
    
    return 0;
}

