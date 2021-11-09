#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1001];

bool bipartite(int start,vector<int> &coloring){
    coloring[start] = 0;

    queue<int> q;
    q.push(start); 

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it: adj[node]){
            if(coloring[it]==-1){
                coloring[it] = !coloring[node]; 
                q.push(it); 
            }

            else if(coloring[it]==coloring[node]){
                return false; 
            }
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
    bool flag = 1; 

    for(int i=0;i<v;i++){
        if(coloring[i]==-1){
            if(bipartite(i,coloring)==false){
                flag = 0 ;
                break; 
            }
        }
    }

    if(flag){
        cout<<"IT IS A BIPARTITE GRAPH"<<endl; 
    }

    else{
        cout<<"NOT A BIPARTITE GRAPH"<<endl; 
    }
}