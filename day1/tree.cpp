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
    int N=7;
    cout<<N<<endl;
    int V =N;
    queue<int> q;
    q.push(1);
    vector<int> adj1[V + 1]; 
    int popcnt=0;
    for(int i=2;i<=V;++i){
        if(popcnt==2){
            q.pop();
            popcnt=0;
        }
        addEdge(adj1, q.front(),i); 
        q.push(i);    
        popcnt++;
    }    
    
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