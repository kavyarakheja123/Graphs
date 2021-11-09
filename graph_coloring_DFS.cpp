#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1001];

bool bipartite(int node,vector<int> &coloring){
    if(coloring[node]==-1){
        coloring[node] = 0; 
    }

    for(auto it: adj[node]){
        if(coloring[it]==-1){
            coloring[it] = !coloring[node];
            if(bipartite(it,coloring)==false){
                return false; 
            }
        }

        else if(coloring[it]==coloring[node]){
            return false; 
        }
    }

    return true; 
}

int main(){
    int v,e;
    cin>>v>>e;

    for(int i=0;i<e;i++){
        int v1,v2;
        cin>>v1>>v2;

        adj[v1].push_back(v2); 
        adj[v2].push_back(v1); 
    }
    
    vector<int> coloring(v,-1);
    for(int i=0;i<v;i++){
        if(coloring[i]==-1){
            if(bipartite(i,coloring)==false){
                return false; 
            }
        }
    }

}