#include <iostream>
#include <vector>
#include <string>

#define lint long long

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;

string S;

int getMaxPrefix(string& str){
    int maxPrefix = 0;
    int prefix = 0;
    vector<int> lps;
    lps.assign(str.length(), 0);

    for(int i = 1; i < str.length(); ++i){
        while(prefix && str[i] != str[prefix]){
            prefix = lps[prefix-1];
        }
        if(str[prefix] == str[i]){
            ++prefix;
        }
        if(maxPrefix < prefix) maxPrefix = prefix;
        lps[i] = prefix;
    }

    return maxPrefix;
}

void Input() {
    cin >> S;
}
void Solve() {
    int answer = 0;
    
    for(int i = 0; i < S.length(); ++i){
        string str = S.substr(i, S.length());
        int result = getMaxPrefix(str);
        if(answer < result) answer = result;
    }

    cout << answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    Input();
    Solve();
    
    return 0;
}
