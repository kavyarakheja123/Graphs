#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[1001];

void Prims_algo(int n){
    
    vector<int> parent(n,-1); 
    vector<int> key(n,INT_MAX);
    vector<bool> mst(n,false);

    parent[0] = -1; 
    key[0] = 0; 

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});

    for(int i=0;i<n-1;i++){
        
        int min_node = pq.top().second;
        pq.pop(); 

        mst[min_node] = true; 

        for(auto it: adj[min_node]){
            int node = it.first;
            int edge_weight = it.second;

            if(mst[node]==false and edge_weight<key[node]){
                parent[node] = min_node;
                pq.push({key[node],node}); 
                key[node] = edge_weight; 
            }
        }
    }

    for(auto it: parent){
        cout<<it<<" " ; 
    }

    cout<<endl; 

    for(auto itt: key){
        cout<<itt<<" " ; 
    }
}

int main(){
    int v,e;
    cin>>v>>e;

    for(int i=0;i<e;i++){
        int v1,v2,w;
        cin>>v1>>v2>>w;

        adj[v1].push_back({v2,w}); 
        adj[v2].push_back({v1,w});  
    }
    
    Prims_algo(v);  
    
}