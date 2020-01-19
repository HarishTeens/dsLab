#include <bits/stdc++.h> 
using namespace std; 

void addEdge(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 

vector<vector<int> > makeIdentityMatrix(int deg){
	vector<vector<int> > id;
	int s=pow(2,deg);
	vector<int> temp;
	for(int i=0;i<s;++i){		
		for(int j=0;j<s;++j){

			if(i==j)
				temp.push_back(1);
			else
				temp.push_back(0);
		}
		id.push_back(temp);
		temp.clear();
	}
	return id;
}

void makeHypercube(int deg)
{
	makeIdentityMatrix(deg);
	for(int i=1;i<=deg;++i){

		int matrix[pow(2,i)][pow(2,i)];

	}
}

int main()
{
	int deg;
	cin>>deg;
	int V=pow(2,deg);
	cout<<V<<endl;	
	vector<vector<int> > adj1;
	
	for(int i=0;i<V;++i){
		for(int j=0;j<V;++j)
			cout<<adj1[i][j];
		cout<<endl;
	}
	// makeHypercube(deg);
	return 0;
}