// In topological sort if there is an edge between u--> v then u must appear before v for all values of u and v :)

#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1001];

void topo_sort(int node,vector<int> &visited,stack<int> &st){
    visited[node] = 1;

    for(auto it: adj[node]){
        if(visited[it]==0){
            topo_sort(it,visited,st); 
        }
    }

    st.push(node); 
    
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
    stack<int> st;

    for(int i=0;i<v;i++){
        if(visited[i]==0){
            topo_sort(i,visited,st); 
        }
    }

    while(!st.empty()){
        cout<<st.top()<<" " ; 
        st.pop(); 
    }

}