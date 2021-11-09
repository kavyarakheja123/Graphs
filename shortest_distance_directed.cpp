#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[1001];

void topo_sort(int node,vector<int> &visited,stack<int> &st){
    visited[node] = 1;

    for(auto it:adj[node]){
        if(visited[it.first]==0){
            topo_sort(it.first,visited,st); 
        }
    }

    st.push(node); 
}

vector<int> shortest_distance(int source,int n,stack<int> &st){
    vector<int> dist(n,INT_MAX); 

    dist[source] = 0;

    while(!st.empty()){
        int node = st.top(); 
        st.pop(); 

        if(dist[node] != INT_MAX){
            for(auto it: adj[node]){
                if(dist[node]+it.second<dist[it.first]){
                    dist[it.first] = dist[node] + it.second; 
                }
            }
        }
    }

    return dist; 
}

int main(){
    int v,e;
    cin>>v>>e;

    for(int i=0;i<e;i++){
        int v1,v2,weight;
        cin>>v1>>v2>>weight;

        adj[v1].push_back({v2,weight}); 
    }

    stack<int> st;

    vector<int> visited(v,0); 

    for(int i=0;i<v;i++){
        if(visited[i]==0){
            topo_sort(i,visited,st); 
        }
    }
    
    vector<int> ans = shortest_distance(0,v,st); 

    for(auto it : ans){
        cout<<it<<" " ; 
    }
    
}