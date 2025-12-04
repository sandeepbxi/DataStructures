#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, vector<vector<int>>& g, vector<int>& vis){
    vis[u]=1;
    cout<<u<<" ";
    for(int v:g[u]){
        if(!vis[v]) dfs(v,g,vis);
    }
}

int main(){
    int n=6;
    vector<vector<int>> g(n);
    g[0]={1,2};
    g[1]={0,3,4};
    g[2]={0,4};
    g[3]={1,5};
    g[4]={1,2,5};
    g[5]={3,4};

    vector<int> vis(n,0);
    dfs(0,g,vis);
  return 0;
}
