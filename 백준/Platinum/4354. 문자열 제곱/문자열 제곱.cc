#include <iostream>
#include <vector>
#include <string>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;

void createPI (vector<int>& pi, string& str);

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
        vector<int> pi;
        createPI(pi, s);

        int len = s.length();
        if(pi[len - 1] != 0 && len % (len - pi[len - 1]) == 0){
            answer.push_back(len / (len - pi[len - 1]));
        }else{
            answer.push_back(1);
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
    pi.assign(str.length(), 0);
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
