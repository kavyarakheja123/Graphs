#include<bits/stdc++.h>
using namespace std;

struct node{
    int u;
    int v;
    int wt;

    node(int first,int second,int weight){
        u = first;
        v = second;
        wt = weight; 
    }
};

bool comp(node a, node b){
    return a.wt<b.wt; 
}

int find_parent(int u,vector<int> &parent){
    if(u==parent[u]){
        return u; 
    }

    return parent[u] = find_parent(parent[u],parent); 
}

void unionn(int u,int v,vector<int> &parent,vector<int> &rank){
    u = find_parent(u,parent);
    v = find_parent(v,parent);
    
    if(rank[u]<rank[v]){
        parent[u] = v; 
    }

    else if(rank[v]<rank[u]){
        parent[v] = u; 
    }

    else{
        parent[v] = u;
        rank[u]++;
    }
}

int main(){
    int v,e;
    cin>>v>>e;

    vector<node> edges;

    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;

        edges.push_back(node(u,v,w)); 
    }

    sort(edges.begin(),edges.end(),comp); 

    vector<int> parent(v);

    for(int i=0;i<v;i++){
        parent[i]=i; 
    }

    vector<int> rank(v);

    vector<pair<int,int>> mst;
    int cost = 0; 

    for(auto it: edges){
        if(find_parent(it.v,parent) != find_parent(it.u,parent)){
            cost += it.wt;
            mst.push_back({it.u,it.v});

            unionn(it.u,it.v,parent,rank); 
        }
    }

    cout<<cost<<endl;  

    for(auto it: mst){
        cout<<it.first<<" "<<it.second<<endl; 
    }

}