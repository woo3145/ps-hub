#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;

int N;
string A, W, S;

void createPI(vector<int>& ret, string s){
    ret.resize(s.length(), 0);

    int prefix = 0;
    for(int i = 1; i < s.length(); ++i){
        while(0 < prefix && s[i] != s[prefix]){
            prefix = ret[prefix-1];
        }
        if(s[i] == s[prefix]) {
            ++prefix;
        } 
        ret[i] = prefix;
    }
}

vector<int> kmp(string str, string pattern){
    vector<int> position;
    vector<int> pi;
    createPI(pi, pattern);
    
    int prefix = 0;
    for(int i = 0; i < str.length(); ++i){
        
        while(0 < prefix && str[i] != pattern[prefix]) {
            prefix = pi[prefix - 1];
        }
        if(str[i] == pattern[prefix]){
            ++prefix;
        }
        if(prefix == pattern.length()){
            position.push_back(i - prefix + 1);
            prefix = pi[prefix - 1];
        }
    }
    return position;
}

void Solve() {
    vector<int> answer;
    // 알파벳 수만큼 반복(시프트한 횟수)
    for(int i = 0; i < A.length(); ++i) {
        vector<int> result = kmp(S, W);
        if(result.size() == 1) answer.push_back(i);
        
        
        for(int w = 0; w < W.length(); ++w) {
            for(int a = 0; a < A.length(); ++a){
                if(W[w] == A[a]) {
                    W[w] = A[(a + 1) % A.length()];
                    break;
                }
            }
        }
    }

    if(answer.size() == 0) {
        cout << "no solution";
    }else if(answer.size() == 1) {
        cout << "unique: " << answer.front();
    }else{
        cout << "ambiguous: ";
        for(auto& a : answer){
            cout << a << ' ';
        }
    }
    cout << '\n';
}

void Input() {
    cin >> A >> W >> S;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int T;
    cin >> T;
    for(int i = 0; i < T; ++i){
        Input();
        Solve();
    }
    
    return 0;
}
