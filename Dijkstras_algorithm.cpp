#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[1001];

vector<int> dijkstras(int source,int n){
    vector<int> shortest_distance(n,INT_MAX);
    vector<int> predecessor(n); 

    shortest_distance[source] = 0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    pq.push({0,source}); 

    while(!pq.empty()){
        int parent = pq.top().second;

        pq.pop(); 

        for(auto it: adj[parent]){
            int node = it.first;
            int edge_weight = it.second;

            if(shortest_distance[parent]+edge_weight<shortest_distance[node]){
                shortest_distance[node] = shortest_distance[parent] + edge_weight;
                pq.push({shortest_distance[node],node}); 

                predecessor[node] = parent; 
            }

        }
    }

    for(auto it:predecessor){
        cout<<it<<" " ; 
    }

    return shortest_distance; 
}

int main(){
    int v,e;
    cin>>v>>e;

    for(int i=0;i<e;i++){
        int v1,v2,w;
        cin>>v1>>v2>>w;

        adj[v1].push_back({v2,w}); 
    }

    vector<int> ans = dijkstras(0,v); 

    for(auto it: ans){
        cout<<it<<" " ; 
    }
}