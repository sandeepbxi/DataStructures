#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n=5;
    vector<vector<pair<int,int>>> g(n);
    g[0].push_back({1,2});
    g[0].push_back({3,6});
    g[1].push_back({0,2});
    g[1].push_back({2,3});
    g[1].push_back({3,8});
    g[1].push_back({4,5});
    g[2].push_back({1,3});
    g[2].push_back({4,7});
    g[3].push_back({0,6});
    g[3].push_back({1,8});
    g[4].push_back({1,5});
    g[4].push_back({2,7});

    vector<int> vis(n,0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0,0});
    int mst=0;

    while(!pq.empty()){
        auto [w,u]=pq.top(); pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        mst+=w;
        for(auto &p:g[u]){
            int v=p.first, wt=p.second;
            if(!vis[v]) pq.push({wt,v});
        }
    }
    cout<<"MST="mst;
  return 0;
}
