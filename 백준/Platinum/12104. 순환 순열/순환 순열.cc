#include <iostream>
#include <string>
#include <vector>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;

void createPI(const string& str, vector<int>& pi);
int kmp(const string& a, const string& b);

string A, B;

void Input() {
    cin >> A >> B;
}

void Solve() {
    cout << kmp(B + B, A);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    Input();
    Solve(); 
    
    return 0;
}

void createPI(const string& str, vector<int>& pi){
    pi.assign(str.length(), 0);

    int prefix = 0;

    for(int i = 1; i < str.length(); ++i){
        while(0 < prefix && str[i] != str[prefix]){
            prefix = pi[prefix - 1];
        }
        if(str[i] == str[prefix]) ++prefix;
        pi[i] = prefix;
    }
}

int kmp(const string& a, const string& b){
    int result = 0;

    vector<int> pi;
    createPI(b, pi);

    int cur = 0;
    for(int i = 0; i < a.length() - 1; ++i){
        while(0 < cur && a[i] != b[cur]){
            cur = pi[cur - 1];
        }
        if(a[i] == b[cur]) ++cur;

        if(cur == b.length()){
            ++result;
            cur = pi[cur - 1];
        }
    }

    return result;
}