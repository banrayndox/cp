#include <bits/stdc++.h>
using namespace std;
class Node{
  public:
  unordered_map<char, Node*>data;
  bool isEnd;
  Node(){
      isEnd = false;
  }
};
class Trie{
    private:
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(string key){
        Node* temp = root;
        for(auto ch: key){
            if(temp->data.count(ch)==0){
                temp->data[ch] = new Node();
            }
                temp = temp->data[ch];
            
        }
        temp->isEnd = true;
    }
    bool search(string key){
        Node* temp = root;
        for(auto ch: key){
            if(temp->data.count(ch)==0) return false;
            temp = temp->data[ch];
        }
        return temp->isEnd;
    }
};

int main(){
    vector<string> array = { "Leet", "Code", "Rakib" } ;
    Trie banx;
    for(auto s: array){
        banx.insert(s);
    }
    cout << banx.search("Code") << endl;
    
    
    
    return 0;
}
