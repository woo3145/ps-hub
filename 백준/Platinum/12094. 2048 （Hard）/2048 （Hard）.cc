#include <iostream>
#include <queue>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;
using std::ios;

using std::queue;

using std::memcpy;
using std::memset;

int N;
int answer;
int map[20][20];
int cut[11];

void Input () {
    cin >> N;

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            cin >> map[i][j];
        }
    }
}
void up () {
    queue<int> queue;
    int temp[20][20];
    memset(temp,0,sizeof(temp));

    for(int j = 0; j < N; ++j){
        int idx = 0;
        for(int i = 0; i < N; ++i){
            if(0 == map[i][j]) {
                continue;
            };

            if(!queue.empty() && queue.back() == map[i][j]) {
                while(!queue.empty()) {
                    int value = queue.front();
                    if(queue.size() == 1) {
                        value *= 2;
                    };
                    queue.pop();
                    temp[idx][j] = value;
                    ++idx;
                }
            } else {
                queue.push(map[i][j]);
            }
        }

        while(!queue.empty()){
            temp[idx][j] = queue.front();

            queue.pop();
            ++idx;
        }
    }

    memcpy(map, temp, sizeof(map));
    return;
}

void down () {
    queue<int> queue;
    int temp[20][20];
    memset(temp,0,sizeof(temp));

    for(int j = 0; j < N; ++j){
        int idx = N-1;
        for(int i = N-1; 0 <= i; --i){
            if(0 == map[i][j]) {
                continue;
            };

            if(!queue.empty() && queue.back() == map[i][j]) {
                while(!queue.empty()) {
                    int value = queue.front();
                    if(queue.size() == 1) {
                        value *= 2;
                    };
                    queue.pop();
                    temp[idx][j] = value;
                    --idx;
                }
            } else {
                queue.push(map[i][j]);
            }
        }

        while(!queue.empty()){
            temp[idx][j] = queue.front();

            queue.pop();
            --idx;
        }
    }

    memcpy(map, temp, sizeof(map));
    return;
}

void right () {
    queue<int> queue;
    int temp[20][20];
    memset(temp,0,sizeof(temp));

    for(int i = 0; i < N; ++i){
        int idx = N-1;
        for(int j = N-1; 0 <= j; --j){
            if(0 == map[i][j]) {
                continue;
            };

            if(!queue.empty() && queue.back() == map[i][j]) {
                while(!queue.empty()) {
                    int value = queue.front();
                    if(queue.size() == 1) {
                        value *= 2;
                    };
                    queue.pop();
                    temp[i][idx] = value;
                    --idx;
                }
            } else {
                queue.push(map[i][j]);
            }
        }

        while(!queue.empty()){
            temp[i][idx] = queue.front();

            queue.pop();
            --idx;
        }
    }

    memcpy(map, temp, sizeof(map));
    return;
}

void left () {
    queue<int> queue;
    int temp[20][20];
    memset(temp,0,sizeof(temp));
    
    for(int i = 0; i < N; ++i){
        int idx = 0;
        for(int j = 0; j < N; ++j){
            if(0 == map[i][j]) {
                continue;
            };

            if(!queue.empty() && queue.back() == map[i][j]) {
                while(!queue.empty()) {
                    int value = queue.front();
                    if(queue.size() == 1) {
                        value *= 2;
                    };
                    queue.pop();
                    temp[i][idx] = value;
                    ++idx;
                }
            } else {
                queue.push(map[i][j]);
            }
        }

        while(!queue.empty()){
            temp[i][idx] = queue.front();

            queue.pop();
            ++idx;
        }
    }

    memcpy(map, temp, sizeof(map));
    return;
}

bool checkSame (int arr[20][20]){
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(map[i][j] != arr[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void dfs(int count) {
    int max = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(max < map[i][j]){
                max = map[i][j];
            }
        }
    }

    if(count == 10) {
        if(answer < max){
            answer = max;

            int temp = answer;
            for(int i = 10; 0 < i; --i){
                cut[i] = temp;
                temp /= 2;
            }
        }
        return;
    }
    if(max <= cut[count]) {
        return;
    }

    // 이전상태 유지
    int origin[20][20];
    memcpy(origin, map, sizeof(origin));

    up();
    if(!checkSame(origin)) {
        dfs(count + 1);
        memcpy(map, origin, sizeof(origin));
    };

    down();
    if(!checkSame(origin)) {
        dfs(count + 1);
        memcpy(map, origin, sizeof(origin));
    }

    left();
    if(!checkSame(origin)) {
        dfs(count + 1);
        memcpy(map, origin, sizeof(origin));
    }

    right();
    if(!checkSame(origin)) {
        dfs(count + 1);
        memcpy(map, origin, sizeof(origin));
    };
}

void Solve() {
    int max = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(max < map[i][j]){
                max = map[i][j];
            }
        }
    }
    answer = max;
    
    dfs(0);

    cout << answer;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();
    
    return 0;
}


