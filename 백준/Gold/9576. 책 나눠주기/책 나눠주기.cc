#include <iostream>
#include <algorithm>
#include <vector>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;

int T;
int N, M;
vector<pair<int,int>> students;

void Input() {
    cin >> N >> M;
    students.resize(M);

    for(auto& s : students){
        cin >> s.first >> s.second;
    }
}

void Solve() {
    std::sort(students.begin(), students.end(), [](const auto& a, const auto& b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second < b.second;
    });

    int answer = 0;
    vector<bool> usedBook;
    usedBook.assign(N + 1, false);

    for(const auto& s : students){
        for(int i = s.first; i <= s.second; ++i){
            if(usedBook[i]) continue;
            usedBook[i] = true;
            ++answer;
            break;
        }
    }

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;

    for(int i = 0; i < T; ++i){
        Input();
        Solve();   
    }
    
    return 0;
}
