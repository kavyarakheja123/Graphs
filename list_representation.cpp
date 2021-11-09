#include<bits/stdc++.h>
using namespace std;

vector<int> graph2[1001]; 

void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex "
             << v << "\n head ";
        for (auto x : adj[v])
           cout << "-> " << x;
        printf("\n");
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int v1,v2;
        cin>>v1>>v2; 

        graph2[v1].push_back(v2);
        graph2[v2].push_back(v1); 
    }

    printGraph(graph2,5); 
}