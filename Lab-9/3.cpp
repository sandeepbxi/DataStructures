#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DSU{
public:
    vector<int> p, r;
    DSU(int n){ p.resize(n); r.resize(n); for(int i=0;i<n;i++) p[i]=i; }
    int find(int x){ if(p[x]==x) return x; return p[x]=find(p[x]); }
    void unite(int a,int b){
        a=find(a); b=find(b);
        if(a!=b){
            if(r[a]<r[b]) swap(a,b);
            p[b]=a;
            if(r[a]==r[b]) r[a]++;
        }
    }
};

int main(){
    int n=4;
    vector<vector<int>> edges={{0,1,10},{0,2,6},{0,3,5},{1,3,15},{2,3,4}};
    sort(edges.begin(), edges.end(), [](auto &a, auto &b){ return a[2] < b[2]; });

    DSU d(n);
    int mst=0;

    for(auto &e:edges){
        int u=e[0], v=e[1], w=e[2];
        if(d.find(u)!=d.find(v)){
            d.unite(u,v);
            mst+=w;
            cout<<u<<" "<<v<<" "<<w<<endl;
        }
    }
    cout<<"Mst="<<mst;
  return 0;
}
