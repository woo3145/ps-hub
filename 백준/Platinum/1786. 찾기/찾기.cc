#include <iostream>
#include <vector>
#include <string>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;

void createLPS(vector<int>& lps, string str);
void kmp(const string& str, const string& pattern, vector<int>& result);

string T, P;


void Input() {
    // cin >> T >> P;
    getline(cin, T);
    getline(cin, P);
}

void Solve() {
    vector<int> answer;
    kmp(T, P, answer);

    cout << answer.size() << '\n';
    for(const auto& a : answer){
        cout << a+1 << ' ';
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

void createLPS(vector<int>& lps, string str){
    int prefix = 0;
    lps.assign(str.length(), 0);
    for(int i = 1; i < str.length(); ++i){
        while(prefix && str[i] != str[prefix]){
            prefix = lps[prefix-1];
        }
        if(str[i] == str[prefix]){
            ++prefix;
        }
        lps[i] = prefix;
    }
}

void kmp(const string& str, const string& pattern, vector<int>& result){
    int curIdx = 0;
    vector<int> lps;
    createLPS(lps, pattern);

    for(int i = 0; i < str.length(); ++i){
        while(curIdx && str[i] != pattern[curIdx]){
            curIdx = lps[curIdx - 1];
        }
        if(str[i] == pattern[curIdx]){
            ++curIdx;
        }

        if(curIdx == pattern.length()){
            result.push_back(i-(curIdx-1));
            curIdx = lps[curIdx - 1];
        }
    }
}