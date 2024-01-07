#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;


vector<int> createPI (const vector<int>& virus);
bool kmp(const vector<int>& program, const vector<int>& virus);

int N, K;
vector<vector<int>> programs;

void Input() {
    cin >> N >> K;
    programs.resize(N);
    int M;
    for(auto& program : programs){
        cin >> M;
        program.resize(M);
        for(auto& c : program){
            cin >> c;
        }
    }    
}

void Solve() {
    std::sort(programs.begin(), programs.end(), [](auto& a, auto& b){
        return a.size() < b.size();
    });

    if(programs[0].size() < K) {
        cout << "NO";
        return;
    }

    int cur = 0;
    while(cur + K - 1< programs[0].size()){
        vector<int> virus_1;
        vector<int> virus_2;
        virus_1.assign(programs[0].begin() + cur, programs[0].begin() + cur + K);
        virus_2.assign(virus_1.rbegin(), virus_1.rend());

        bool flag = true;
        for(int i = 1; i < N; ++i){
            if(!kmp(programs[i], virus_1) && !kmp(programs[i], virus_2)){
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << "YES";
            return;
        }
        ++cur;
    }

    cout << "NO";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    Input();
    Solve(); 
    
    return 0;
}

vector<int> createPI (const vector<int>& virus){
    vector<int> pi;
    pi.assign(virus.size(), 0);

    int prefix = 0;

    for(int i = 1; i < virus.size(); ++i){
        while(0 < prefix && virus[prefix] != virus[i]){
            prefix = pi[prefix - 1];
        }
        if(virus[prefix] == virus[i]) ++prefix;
        pi[i] = prefix;
    }

    return pi;
}

bool kmp(const vector<int>& program, const vector<int>& virus){
    vector<int> pi = createPI(virus);

    int cur = 0;
    for(int i = 0; i < program.size(); ++i){
        while(0 < cur && program[i] != virus[cur]){
            cur = pi[cur - 1];
        }
        if(program[i] == virus[cur]) ++cur;

        if(cur == virus.size()) {
            return true;
        }
    }
    return false;
}