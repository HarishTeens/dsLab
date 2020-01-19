#include <bits/stdc++.h> 
using namespace std; 
  
void addEdge(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 

void makeRing(vector<int> adj1[],int V,int x){
	for(int i=1;i<V;++i){
        addEdge(adj1, i+x, i+1+x);     
    }
    addEdge(adj1,V+x,1+x);
}

void makeStar(vector<int> adj1[],int V,int x){
	for(int i=2;i<=V;++i){
        addEdge(adj1, 1+x, i+x);     
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
    int N1=rand()%10,N2=rand()%10,N3=rand()%10;    
    vector<int> adj1[N1+N2+N3+1]; 
    int deg=rand()%4+1;
	makeTree(adj1,N1,deg);
    makeStar(adj1,N2,N1);
    makeRing(adj1,N3,N1+N2);

    cout<<"N1 "<<N1<<" deg "<<deg<<" N2 "<<N2<<" N3 "<<N3<<endl;
    
  int v1=rand()%N1+1,v2=rand()%N2+1+N1;
    //connecting Tree and Star
    addEdge(adj1,v1,v2);
    int v3=rand()%N2+1+N1,v4=rand()%N3+1+N1+N2;
    //connecting Star and Ring
    addEdge(adj1,v3,v4);

    cout<<" v1 "<<v1<<" v2 "<<v2<<" v3 "<<v3<<" v4 "<<v4<<endl;

    
    printList(adj1,N1+N2+N3);

}
