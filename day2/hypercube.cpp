#include<bits/stdc++.h> 
using namespace std; 

void addEdge(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v);  
} 

void printGraph(vector<int> adj[], int V) 
{ 
    for (int v = 0; v < V; ++v) 
    { 
        cout<<"\n Adjacency list of vertex "<<v<< "\nhead";
        vector<int>::iterator ptr; 
        	for (ptr=adj[v].begin(); ptr<adj[v].end(); ptr++){
        		cout<<"->"<<*ptr;  
        	}
    } 
}

int main(){
	cout<<"-------------This is HyperCube topology Program-------------"<<endl;
	cout<<endl;
	cout<<"Enter the degree of nodes in hypercube topology: ";
	int n;
	cin>>n;
	int deg[100]={0};
	int nodes=pow(2,n);
	vector<int>lis[100];
	for(int i=0;i<nodes;i++){
		for(int j=0;j<nodes;j++){
			int ans=i^j;
			if(__builtin_popcount(ans)==1){
				addEdge(lis,i,j);
				deg[i]++;
			}
		}
	}
	printGraph(lis,nodes);
	cout<<endl;
	for(int k=0;k<nodes;k++){
		cout<<"Degree of node "<<k<<" is: "<<deg[k]<<endl;
	}
}


