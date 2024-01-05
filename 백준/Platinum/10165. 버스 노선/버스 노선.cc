#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using std::ios;
using std::cout;
using std::cin;
using std::vector;

struct Line {
    int from, to, idx;
    Line(){};
    ~Line(){};
};

int N, M;
vector<Line> lines;

void Input() {
    cin >> N >> M;
    lines.resize(M);

    int idx = 1;
    for(auto& l : lines){
        cin >> l.from >> l.to;
        l.idx = idx++;
    }
}

void Solve() {
    int circleMax = 0;

    for(auto& l : lines){
        if(l.to < l.from) {
            circleMax = std::max(circleMax, l.to);
            l.to += N;
        }
    }

    std::sort(lines.begin(), lines.end(), [](Line& a, Line& b){
        if(a.from == b.from){
            return a.to > b.to;
        }
        return a.from < b.from;
    });

    vector<Line> result;
    for(auto& l : lines){
        // 음수부터 진행된 노선과 겹침
        if(l.to <= circleMax) {
            continue;
        }

        if(result.empty() || result.back().to < l.to){
            result.push_back(l);
        }
    }

    std::sort(result.begin(), result.end(), [](Line& a, Line& b){
        return a.idx < b.idx;
    });

    for(auto& r : result){
        cout << r.idx << ' ';
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
