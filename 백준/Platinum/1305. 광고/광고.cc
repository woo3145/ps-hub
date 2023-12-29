#include <iostream>
#include <vector>
#include <string>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;

void createPI (vector<int>& pi, string& str);

int L;
string S;

void Input() {
    cin >> L >> S;
}
void Solve() {
    vector<int> pi;
    pi.assign(S.length(), 0);
    createPI(pi, S);

    int answer = 0;

    cout << S.length() - pi[S.length()-1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    Input();
    Solve();
    
    return 0;
}

void createPI (vector<int>& pi, string& str){
    int prefix = 0;

    for(int i = 1; i < str.length(); ++i){
        while(prefix && str[i] != str[prefix]){
            prefix = pi[prefix - 1];
        }
        if(str[i] == str[prefix]){
            ++prefix;
        }
        pi[i] = prefix;
    }
}
