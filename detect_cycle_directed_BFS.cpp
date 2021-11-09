#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1001];

bool detect_cycle(int n){
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
    
    int count = 0; 
    while(!q.empty()){
        int node = q.front();
        q.pop();

        count++; 

        for(auto it: adj[node]){
            indegree[it]--; 

            if(indegree[it]==0){
                q.push(it);
            }
        }
    }

    if(count==n){ // This means we have generated the topological sort of the graph so it does not contain a cycle :) 
        return false; 
    } 

    return true ; 
}

int main(){
    int v,e;
    cin>>v>>e;

    for(int i=0;i<e;i++){
        int v1,v2;
        cin>>v1>>v2;

        adj[v1].push_back(v2); 
    }

    if(detect_cycle(v)){
        cout<<"CYCLE DETECTED"<<endl; 
    }

    else{
        cout<<"CYCLE NOT DETECTED"<<endl; 
    }
}