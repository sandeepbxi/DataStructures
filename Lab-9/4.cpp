#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n=5;
    vector<vector<pair<int,int>>> g(n);
    g[0]={{1,10},{4,5}};
    g[1]={{2,1},{4,2}};
    g[2]={{3,4}};
    g[3]={{2,6}};
    g[4]={{1,3},{2,9},{3,2}};

    vector<int> dist(n,1e9);
    dist[0]=0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,0});

    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop();
        if(d!=dist[u]) continue;
        for(auto &p:g[u]){
            int v=p.first, w=p.second;
            if(dist[u]+w < dist[v]){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }

    for(int i=0;i<n;i++) cout<<i<<" "<<dist[i]<<endl;
  return 0;
}
