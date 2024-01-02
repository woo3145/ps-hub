#include <iostream>
#include <vector>
#include <string>
#include <queue>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::priority_queue;

int N;
vector<string> strings;

void Input() {
    cin >> N;
    strings.reserve(N);

    for(int i = 0; i < N; ++i){
        string s;
        cin >> s;
        strings.push_back(s);
    }
}

// 첫글자가 같은 문자열들의 우선순위를 비교하기 위함
struct Compare {
    bool operator() (const string& a, const string& b){
        return (a + b > b + a);
    }
};

void Solve() {
    priority_queue<string, vector<string>, Compare> pq;

    for(const auto& s : strings){
        pq.push(s);
    }
    
    while(!pq.empty()){
        string a = pq.top();
        pq.pop();
        cout << a[0];
        if(1 < a.length()){
            pq.push(a.substr(1, a.length() - 1));
        }
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
