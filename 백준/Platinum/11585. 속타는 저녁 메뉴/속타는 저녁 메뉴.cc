#include <iostream>
#include <vector>
#include <string>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;

void createPI(const string& str, vector<int>& ret);
int kmp(const string& str, const string& pattern);
int gcd(int a, int b);

int N;
string s1, s2;

void Input() {
    cin >> N;
    s1.reserve(N);
    s2.reserve(N);
    for(int i = 0; i < N; ++i){
        char c;
        cin >> c;
        s1 += c;
    }
    for(int i = 0; i < N; ++i){
        char c;
        cin >> c;
        s2 += c;
    }
}

void Solve() {
    int cnt = kmp(s1 + s1, s2);
    int d = gcd(N, cnt);

    cout << cnt / d << '/' << N / d;
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

int kmp(const string& str, const string& pattern){
    vector<int> pi;
    createPI(pattern, pi);
    
    int cur = 0;

    int count = 0;

    for(int i = 0; i < str.length() - 1; ++i){
        while(cur && str[i] != pattern[cur]){
            cur = pi[cur - 1];
        }
        if(str[i] == pattern[cur]){
            ++cur;
        }
        
        if(cur == pattern.length()){
            ++count;
            cur = pi[cur - 1];
        }
    }
    return count;
}

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}