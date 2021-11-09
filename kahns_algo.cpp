//Kahn's algorithm is used to find topological sort using BFS :)

#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1001];

vector<int> topo_sort_bfs(int n){
    vector<int> indegree(n,0); 

    for(int i=0;i<n;i++){
        for(auto it: adj[i]){
            indegree[it]++; 
        }
    }

    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i); 
        }
    }

    vector<int> topo_sort;

    while(!q.empty()){
        int node = q.front();
        q.pop(); 

        topo_sort.push_back(node);

        for(auto it: adj[node]){
            indegree[it]--; 

            if(indegree[it]==0){
                q.push(it); 
            }
        }
    }

    return topo_sort ; 
}

int main(){
    int v,e;
    cin>>v>>e;

    for(int i=0;i<e;i++){
        int v1,v2;
        cin>>v1>>v2;

        adj[v1].push_back(v2); 
    }

    vector<int> topo_sort = topo_sort_bfs(v); 

    for(auto it: topo_sort){
        cout<<it<<" " ; 
    }
}