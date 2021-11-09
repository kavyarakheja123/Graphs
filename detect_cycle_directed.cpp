#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1001];

bool detect_cycle_directed(int node,vector<int> &visited,vector<int> &dfs_visited){
    visited[node] = 1;
    dfs_visited[node] = 1; 

    for(auto it: adj[node]){
        if(visited[it]==0){
            if(detect_cycle_directed(it,visited,dfs_visited)){
                return true;  
            }
        }

        else if(dfs_visited[it]==1){
            return true; 
        }
    }

    dfs_visited[node] = 0;
    return false; 
}

int main(){
    int v,e;
    cin>>v>>e;

    for(int i=0;i<e;i++){
        int v1,v2;
        cin>>v1>>v2;

        adj[v1].push_back(v2); 
    }

    vector<int> visited(v,0);
    vector<int> dfs_visited(v,0); 

    bool flag = 0; 

    for(int i=0;i<v;i++){
        if(visited[i]==0){
            if(detect_cycle_directed(i,visited,dfs_visited)){
                flag = 1;
                break; 
            }
        }
    }

    if(flag){
        cout<<"CYCLE DETECTED"<<endl; 
    }

    else{
        cout<<"CYCLE NOT DETECTED"<<endl; 
    }
}