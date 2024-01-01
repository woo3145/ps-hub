#include <iostream>
#include <vector>
#include <string>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;

void createPI(const string& str, vector<int>& ret);
bool kmp(const string& str, const string& pattern);

int N;
vector<int> P1, P2;
string s1, s2;

void Input() {
    cin >> N;
    s1.assign(360000, ' ');
    s2.assign(360000, ' ');
    
    for(int i = 0; i < N; ++i){
        int idx;
        cin >> idx;
        s1[idx] = '1';
    }
    for(int i = 0; i < N; ++i){
        int idx;
        cin >> idx;
        s2[idx] = '1';
    }
}

void Solve() {
    if(kmp(s1 + s1, s2)){
        cout << "possible";
    }else {
        cout << "impossible";
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


void createPI(const string& str, vector<int>& ret){
    ret.assign(str.length(), 0);

    int prefix = 0;
    for(int i = 1; i < str.length(); ++i){
        while(prefix && str[i] != str[prefix]){
            prefix = ret[prefix - 1];
        }
        if(str[i] == str[prefix]){
            ++prefix;
        }
        ret[i] = prefix;
    }
}

bool kmp(const string& str, const string& pattern){
    vector<int> pi;
    createPI(pattern, pi);
    
    int cur = 0;

    for(int i = 0; i < str.length(); ++i){
        while(cur && str[i] != pattern[cur]){
            cur = pi[cur - 1];
        }
        if(str[i] == pattern[cur]){
            ++cur;
        }
        
        if(cur == pattern.length()){
            return true;
        }
    }
    return false;
}