#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1001];

bool detect_cycle_BFS(int start,vector<bool> &visited){
    queue<pair<int,int>> q;
    q.push({start,-1});

    visited[start]=1; 

    while(!q.empty()){
        int node = q.front().first;
        int prev = q.front().second;

        q.pop(); 

        for(auto it: adj[node]){
            if(visited[it]==0){
                visited[it]=1;
                q.push({it,node}); 
            }

            else if(it != prev){
                return true ; 
            }
        }
    }

    return false; 
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

    vector<bool> visited(v+1,0);
    bool flag = 0; 

    for(int i=0;i<v;i++){
        if(visited[i]==0){
            if(detect_cycle_BFS(i,visited)){
                cout<<"CYCLE DETECTED"<<endl;
                flag = 1;
                break; 
            }
        }
    }

    if(!flag){
        cout<<"CYCLE NOT DETECTED"<<endl;  
    }
}