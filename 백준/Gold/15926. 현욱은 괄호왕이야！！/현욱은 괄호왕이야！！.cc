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
string S;

void Solve() {
    vector<int> st;
    int answer = 0;
    
    st.push_back(-1);

    for(int i = 0; i < S.length(); ++i){
        if(S[i] == '('){
            st.push_back(i);
        }else{
            st.pop_back();
            if(!st.empty()) answer = std::max(answer, i - st.back());
            else st.push_back(i);
        }
    }

    cout << answer;
}

void Input() {
    cin >> N >> S;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input();
    Solve(); 
    
    return 0;
}

