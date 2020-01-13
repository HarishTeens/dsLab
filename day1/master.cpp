#include <bits/stdc++.h> 
using namespace std; 
  
void addEdge(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 

void makeRing(vector<int> adj1[],int V){
	for(int i=1;i<V;++i){
        addEdge(adj1, i, i+1);     
    }
    addEdge(adj1,V,1);
}

void makeStar(vector<int> adj1[],int V){
	for(int i=2;i<=V;++i){
        addEdge(adj1, 1, i);     
    }
}

void makeTree(vector<int> adj1[],int V,int deg){
	queue<int> q;
    q.push(1);    
    int popcnt=0;
    for(int i=2;i<=V;++i){
        if(popcnt==deg){
            q.pop();
            popcnt=0;
        }
        addEdge(adj1, q.front(),i); 
        q.push(i);    
        popcnt++;
    }  
}

void printList(vector<int> adj1[],int V){
	for(int i=1;i<=V;++i){
        vector<int> temp=adj1[i];
        int len=adj1[i].size();   
        cout<<i<<" (deg="<<len<<")- "     ;
        for(int j=0;j<len;++j){
            cout<<temp[j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
	srand(time(0));
    int N=10;

    
    int V =N; 
    vector<int> adj1[V + 1]; 
    cout<<"1.Ring 2.Star 3.Tree \n";    
    int ch;cin>>ch;
    cout<<"Number of Nodes "<<N<<endl;
    switch(ch){
    	case 1:
    		makeRing(adj1,V);
    	break;
    	case 2:
    		makeStar(adj1,V);
    	break;
    	case 3:
    		cout<<"Enter degree of the tree\n";
    		cin>>ch;
    		makeTree(adj1,V,ch);
    	break;
    	default:
    	cout<<"Invalid Input\n";
    }
    printList(adj1,V);

}