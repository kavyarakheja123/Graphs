#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1001];

vector<int> BFS(int v,vector<int> adj[]){
    vector<int> bfs;
    vector<bool> visited(v+1,0);

    for(int i=1;i<=v;i++){
        if(visited[i]==0){

            queue<int> q;
            q.push(i);

            visited[i] = 1;

            while(!q.empty()){
                int node = q.front();
                q.pop(); 

                bfs.push_back(node); 
                
                for(auto it:adj[node]){
                    if(visited[it]==0){
                        q.push(it);
                        visited[it] = 1; 
                    }
                }

            }
        }

    }

    return bfs; 
}

int main(){
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=m;i++){
        int v1,v2;
        cin>>v1>>v2;

        adj[v1].push_back(v2);
        adj[v2].push_back(v1); 
    }

    vector<int> bfs = BFS(n,adj);

    for(auto it: bfs){
        cout<<it<<" "; 
    }

    /* 
    1    2
    | \ /|
    |  3 |
    |  | |
    |  4 |
    |   \|
    5----6 

    */  
}