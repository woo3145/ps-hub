#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;

struct Flower {
    int start, end;
};

int N;
vector<Flower> flowers;

void Solve() {
    std::sort(flowers.begin(), flowers.end(), [](auto& a, auto& b){
        return a.start < b.start;
    });
    int curTime = 301;
    int curIdx = 0;
    int answer = 0;

    while(curTime < 1201){
        int nextTime = curTime;

        for(int i = curIdx; i < N; ++i){
            if(curTime < flowers[i].start) break;

            if(flowers[i].start <= curTime && nextTime < flowers[i].end){
                nextTime = flowers[i].end;
                curIdx = i;
            }
        }

        if(curTime == nextTime) {
            cout << 0;
            return;
        }
        ++answer;
        curTime = nextTime;
    }

    cout << answer;
}

void Input() {
    cin >> N;
    flowers.resize(N);
    int s1, e1, s2, e2;
    for(auto& n : flowers){
        cin >> s1 >> s2 >> e1 >> e2;
        n.start = s1 * 100 + s2;
        n.end = e1 * 100 + e2;
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
