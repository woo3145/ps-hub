#include <iostream>
#include <vector>
#include <string>
#include <map>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::map;

struct TrieNode {
    bool isEnd;
    map<string, TrieNode*> children;

    TrieNode():isEnd(false){}
    ~TrieNode(){}
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    ~Trie(){};

    void insert(vector<string>& items){
        TrieNode* current = root;

        for(const string& s : items){
            if(current->children.find(s) == current->children.end()){
                current->children[s] = new TrieNode();
            }
            current = current->children[s];
        }
        current->isEnd = true;
    }

    void print(TrieNode* node, int depth){
        for(auto& item : node->children){
            for(int i = 0; i < depth * 2; ++i){
                cout << '-';
            }
            cout << item.first << '\n';
            print(item.second, depth + 1);
        }
    }
};



int N;
vector<vector<string>> info;

void Input() {
    cin >> N;
    int K;
    info.reserve(N);
    for(int i = 0; i < N; ++i){
        string s;
        vector<string> tmp;

        cin >> K;
        tmp.reserve(K);
        for(int j = 0; j < K; ++j){
            cin >> s;
            tmp.push_back(s);
        }

        info.push_back(tmp);
    }
}
void Solve() {
    Trie trie;

    for(auto& s : info){
        trie.insert(s);
    }
    trie.print(trie.root, 0);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    Input();
    Solve();   
    
    return 0;
}
