#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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
    queue<int> q;
    q.push(0);
    vis[0]=1;

    while(!q.empty()){
        int u=q.front(); q.pop();
        cout<<u<<" ";
        for(int v:g[u]){
            if(!vis[v]){
                vis[v]=1;
                q.push(v);
            }
        }
    }
  return 0;
}


