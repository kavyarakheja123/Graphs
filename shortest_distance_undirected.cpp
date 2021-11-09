#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1001];

vector<int> shortest_distance(int start,int n){
    vector<int> dist(n,INT_MAX); 

    dist[start] = 0;

    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it:adj[node]){
            if(dist[node]+1<dist[it]){
                dist[it] = dist[node]+1;
                q.push(it); 
            }
        }
    }

    return dist; 
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

    vector<int> ans = shortest_distance(0,v);

    for(auto it: ans){
        cout<<it<<" " ; 
    }
}