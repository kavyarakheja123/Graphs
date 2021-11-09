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

void Bellman_Ford(int n,int source,vector<node> &edges){
    vector<int> dist(n,INT_MAX);

    dist[source] = 0; 

    for(int i=0;i<n-1;i++){
        for(auto it: edges){
            if(dist[it.u]+it.wt < dist[it.v]){
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }

    bool flag = false;

    for(auto it: edges){
        if(dist[it.u]+it.wt < dist[it.v]){
            cout<<"THERE IS A NEGATIVE CYCLE"<<endl;
            flag = true; 
            break; 
        }
    }

    if(!flag){
        for(auto it: dist){
            cout<<it<<" " ; 
        }
    }
}

int main(){
    int v,e;
    cin>>v>>e;

    vector<node> edges;

    for(int i=0;i<e;i++){
        int u,v,wt;
        cin>>u>>v>>wt;

        edges.push_back(node(u,v,wt)); 
    }

    Bellman_Ford(v,0,edges); 
}