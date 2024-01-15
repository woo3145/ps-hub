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

int N;
vector<int> arr;

void Solve() {
    vector<int> answer;
    vector<int> st;
    for(auto cur = arr.rbegin(); cur != arr.rend(); ++cur){
        while(!st.empty()){
            if(*cur < st.back()){
                break;
            }
            st.pop_back();
        }
        if(st.empty()) {
            answer.push_back(-1);
        }else{
            answer.push_back(st.back());
        }
        st.push_back(*cur);
    }

    while(!answer.empty()){
        cout << answer.back() << ' ';
        answer.pop_back();
    }
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