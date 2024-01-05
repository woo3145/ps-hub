#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using std::ios;
using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::unordered_map;

struct TrieNode {
    bool isEnd;
    unordered_map<char, TrieNode*> children;
    TrieNode():isEnd(false){};
    ~TrieNode(){};
};

class Trie {
private:
    TrieNode* root;
public:
    Trie(){
        root = new TrieNode();
    }

    void insert(string& str){
        TrieNode* cur = root;

        for(const char& c : str){
            if(cur->children.find(c) == cur->children.end()){
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->isEnd = true;
    }

    void find(string& str, vector<int>& result){
        TrieNode* cur = root;

        int curIdx = 0;
        for(char& c : str){
            if(cur->children.find(c) == cur->children.end()){
                return;
            }
            
            cur = cur->children[c];
            if(cur->isEnd) {
                result.push_back(curIdx);
            }
            ++curIdx;
        }
    }
};


int C, N, Q;
Trie colorTree;
unordered_map<string, bool> nameMap;

void Input() {
    cin >> C >> N;
    string str;

    for(int i = 0; i < C; ++i){
        cin >> str;
        colorTree.insert(str);
    }
    for(int i = 0; i < N; ++i){
        cin >> str;
        nameMap.insert({str, true});
    }
    cin >> Q;
}

void Solve() {
    for(int i = 0; i < Q; ++i){
        string str;
        cin >> str;
        vector<int> result;
        colorTree.find(str, result);

        bool flag = true;
        for(auto& r : result){
            string substr = str.substr(r + 1);
            if(nameMap.find(substr) != nameMap.end()){
                flag = false;
                cout << "Yes\n";
                break;
            }
        }
        if(flag) {
            cout << "No\n";
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
