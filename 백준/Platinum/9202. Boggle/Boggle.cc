#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::map;
using std::pair;
using std::set;

struct TrieNode {
    bool isEnd;
    map<char, TrieNode*> children;

    TrieNode():isEnd(false){}
    ~TrieNode(){}
};

class Trie {
private:
    TrieNode* root;
public:
    Trie(){
        root = new TrieNode();
    }
    ~Trie(){}

    void insert(string& str) {
        TrieNode* current = root;

        for(const char& c : str){
            if(current->children.find(c) == current->children.end()){
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->isEnd = true;
    }

    // {결과, 끝까지 도달}
    pair<bool, bool> search(const string& str){ 
        TrieNode* current = root;
        for(const char& c : str){
            if(current->children.find(c) == current->children.end()){
                return {false, false};
            }
            current = current->children[c];
        }
        return {current->isEnd, true};
    }
};

int N, B;
Trie trie;
vector<string> strings;
vector<int> scores = {0, 0, 0, 1, 1, 2, 3, 5, 11};

const int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1}; 

int score;
int cnt;
set<string> answer;
vector<string> board;
vector<vector<bool>> visited;

void Input() {
    cin >> N;
    string s;
    for(int i = 0; i < N; ++i){
        cin >> s;
        trie.insert(s);
    }

    cin  >> B;
}

void recursive (int y, int x, string str) {
    pair<bool, bool> result = trie.search(str);
    if(!result.second) return;
    if(result.first){
        answer.insert(str);
    }
    for(int i = 0; i < 8; ++i){
        int ny = dy[i] + y;
        int nx = dx[i] + x;

        if(ny < 0 || 4 <= ny || nx < 0 || 4 <= nx) continue;
        if(visited[ny][nx]) continue;
        visited[ny][nx] = true;
        recursive(ny, nx, str + board[ny][nx]);
        visited[ny][nx] = false;
    }
}

void Solve() {
    for(int i = 0; i < 4; ++i){
        string s;
        cin >> s;
        board.push_back(s);
        visited.push_back({0, 0, 0, 0});
    }

    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            visited[i][j] = true;
            string tmp;
            tmp += board[i][j];
            recursive(i,j, tmp);
            visited[i][j] = false;
        }
    }
    
    string longestStr = "";
    for(const auto& s : answer){
        int len = s.length();
        if(longestStr.length() < len) longestStr = s;
        score += scores[len];
    }

    cout << score << ' ' << longestStr << ' ' << answer.size() << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    Input();
    for(int i = 0; i < B; ++i){
        score = 0;
        cnt = 0;
        answer.clear();
        visited.clear();
        board.clear();
        Solve();
    }
    
    return 0;
}
