#include <bits/stdc++.h> 
using namespace std; 
  
void addEdge(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 
// Driver code 
int main() 
{ 
    srand(time(0));
    int N=rand()%10;
    cout<<N<<endl;
    int V =N, E =N; 
    vector<int> adj1[V + 1]; 
    for(int i=1;i<V;++i){
        addEdge(adj1, i, i+1);     
    }
    addEdge(adj1,V,1);
    
    for(int i=1;i<=V;++i){
        vector<int> temp=adj1[i];
        int len=adj1[i].size();   
        cout<<i<<" (deg="<<len<<")- "     ;
        for(int j=0;j<len;++j){
            cout<<temp[j]<<" ";
        }
        cout<<endl;
    }
    return 0; 
} 