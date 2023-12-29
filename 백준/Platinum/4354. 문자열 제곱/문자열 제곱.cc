#include <iostream>
#include <vector>
#include <string>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;

void createPI (vector<int>& pi, string& str);
bool kmp(string& str, string& pattern);

vector<string> strings;

void Input() {
    string a;
    while(true){
        cin >> a;
        if(a == ".") break;
        strings.push_back(a);
    }
}
void Solve() {
    vector<int> answer;
    for(auto& s : strings){
        string tmp = "";
        bool flag = false;
        for(int i = 0; i < s.length(); ++i){
            tmp += s[i];

            if(s.length() % tmp.length() != 0) continue;

            if(kmp(s, tmp)){
                answer.push_back(s.length() / tmp.length());
                flag = true;
                break;
            }
            if(flag){
                break;
            }
        }
    }
    for(auto& a : answer){
        cout << a << '\n';
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

bool kmp(string& str, string& pattern){
    int curIdx = 0;
    vector<int> pi;
    pi.assign(pattern.length(), 0);
    createPI(pi, pattern);

    int flag = 0;
    for(int i = 0; i < str.length(); ++i){
        while(curIdx && str[i] != pattern[curIdx]){
            curIdx = pi[curIdx - 1];
        }
        if(str[i] == pattern[curIdx]){
            ++curIdx;
        }

        // 찾음
        if(curIdx == pattern.length()){
            int findIdx = i - (pattern.length() - 1);
            if(findIdx != flag) return false; // 실패
            flag += pattern.length();
            curIdx = pi[curIdx-1];
        }
    }

    // 다돌면 성공
    return flag == str.length();
}