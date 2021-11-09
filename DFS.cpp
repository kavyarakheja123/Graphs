#include<bits/stdc++.h>
using namespace std;

int graph[1001][1001];

vector<int> adj[1001];

void DFS(int node,vector<int> &visited,vector<int> &dfs){

    dfs.push_back(node); 
    visited[node] = 1;

    for(auto it: adj[node]){
        if(visited[it]==0){
            dfs.push_back(it);
            DFS(it,visited,dfs); 
        }
    }
     
}

int main(){
    int v,e;
    cin>>v>>e;

    for(int i=0;i<v;i++){
        int v1,v2;
        cin>>v1>>v2;

        adj[v1].push_back(v2);
        adj[v2].push_back(v1); 
    }
    
    vector<int> visited(v,0); 
    vector<int> dfs;

    for(int i=0;i<v;i++){
        if(visited[i]==0){
            DFS(i,visited,dfs);  
        }
    }

}