#include<bits/stdc++.h>
using namespace std;

static vector<vector<int>> graph; 

void Floyd_Warshall(int n,vector<vector<int>> &dist){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j] = min(dist[i][j],(dist[i][k]+dist[k][j])); 
            }
        }
    }
}

int main(){
    int n;  //n denotes the number of vertices 
    cin>>n;

    int m;  //m denotest the number of edges 
    cin>>m;

    for(int i=0;i<m;i++){
        int e1,e2,wt;    //e1,e2 denotes the edges which are connected :) 
        cin>>e1>>e2>>wt;

        graph[e1][e2] = wt;  //for undirected graph both graph[i][j] and graph[j][i] = 1 :) 
    }
    
    vector<vector<int>> dist ;  

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                dist[i][j] = 0; 
            }

            else if(graph[i][j] != 0){
                dist[i][j] = graph[i][j]; 
            }

            else{
                dist[i][j] = INT_MAX; 
            }
        }
    }

    Floyd_Warshall(n,dist);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dist[i][j]<<" " ; 
        }
        cout<<endl; 
    }

}