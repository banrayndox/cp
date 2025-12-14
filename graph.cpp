#include <bits/stdc++.h>
using namespace std;

class Graph{
  private:
  int V;
  list<int>* l;
  public: 
  Graph(int V){
      this->V = V;
      l = new list<int> [V];
  }
  void insert_edge(int u, int v){
      l[u].push_back(v);
      l[v].push_back(u);
  }
  void display(){
    for(int u=0; u<V; u++){
      list<int> temp = l[u];
      cout << u << " : ";
      for(auto x: temp){
          cout << x << " ";
      }
      cout << endl;
      
  }
}
void BFS(int src){
    vector<bool> visited (V, false);
    queue<int> vertex;
    vertex.push(src);
    visited[src] = true;
    while(!vertex.empty()){
     int top = vertex.front(); vertex.pop();
     cout << top << " ";
     for(auto x: l[top]){
         if(visited[x]) continue;
         vertex.push(x);
         visited[x] = true;
     }
    }
}
int sizeofV(){
    return V;
}

void DFS_helper(int src, vector<bool> &vis){
    vis[src] = true;
    cout << src << " ";
    for(int x: l[src]){
        if(!vis[x]) DFS_helper(x, vis);
    }
    
}
void DFS(int src){
 vector<bool> vis (V, false);
 DFS_helper(src, vis);
 cout << endl;
}
};



int main(){
    Graph graph(5);
    graph.insert_edge(0,1);
    graph.insert_edge(1,2);
    graph.insert_edge(1,3);
    graph.insert_edge(2,3);
    graph.insert_edge(2,4);
    graph.display();
    cout << endl;
    graph.BFS(0);
    cout << endl;
    graph.DFS(0);
    return 0;
}
