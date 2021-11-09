#include<bits/stdc++.h>
using namespace std;

static int graph[1001][1001]; 

int main(){
    int n;  //n denotes the number of vertices 
    cin>>n;

    int m;  //m denotest the number of edges 
    cin>>m;

    for(int i=0;i<m;i++){
        int e1,e2;    //e1,e2 denotes the edges which are connected :) 
        cin>>e1>>e2;

        graph[e1][e2] = 1;  //for undirected graph both graph[i][j] and graph[j][i] = 1 :) 
        graph[e2][e1] = 1; 
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cout<<graph[i][j]<<" "; 
        }
        cout<<"\n"; 
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