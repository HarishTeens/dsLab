#include <bits/stdc++.h> 
using namespace std; 
# define INF 0x3f3f3f3f 
// iPair ==>  Integer Pair 
typedef pair<int, int> iPair; 

  
void addEdge(vector<pair<int,int> > adj[], int u, int v,int w) 
{ 
    adj[u].push_back(make_pair(v,w)); 
    adj[v].push_back(make_pair(u,w)); 
} 

void makeRing(vector<pair<int,int> > adj1[],int V,int x){
	for(int i=1;i<V;++i){
        addEdge(adj1, i+x, i+1+x,rand()%10);     
    }
    addEdge(adj1,V+x,1+x,rand()%10);
}

void makeStar(vector<pair<int,int> > adj1[],int V,int x){
	for(int i=2;i<=V;++i){
        addEdge(adj1, 1+x, i+x,rand()%10);     
    }
}

void makeTree(vector<pair<int,int> > adj1[],int V,int deg){
	queue<int> q;
    q.push(1);    
    int popcnt=0;
    for(int i=2;i<=V;++i){
        if(popcnt==deg){
            q.pop();
            popcnt=0;
        }
        addEdge(adj1, q.front(),i,rand()%10); 
        q.push(i);    
        popcnt++;
    }  
}

void printList(vector<pair<int,int> > adj1[],int V){
	for(int i=1;i<=V;++i){
        vector<pair<int,int> > temp=adj1[i];
        int len=adj1[i].size();   
        cout<<i<<" (deg="<<len<<")- "     ;
        for(int j=0;j<len;++j){
            cout<<temp[j].first<<"("<<temp[j].second<<") ";
        }
        cout<<endl;
    }
}

void shortestPath(vector<iPair> adj[],int V,int src) 
{ 
    // Create a priority queue to store vertices that 
    // are being preprocessed. This is weird syntax in C++. 
    // Refer below link for details of this syntax 
    // https://www.geeksforgeeks.org/implement-min-heap-using-stl/ 
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
  
    // Create a vector for distances and initialize all 
    // distances as infinite (INF) 
    vector<int> dist(V, INF); 
  
    // Insert source itself in priority queue and initialize 
    // its distance as 0. 
    pq.push(make_pair(0, src)); 
    dist[src] = 0; 
  
    /* Looping till priority queue becomes empty (or all 
      distances are not finalized) */
    while (!pq.empty()) 
    { 
        // The first vertex in pair is the minimum distance 
        // vertex, extract it from priority queue. 
        // vertex label is stored in second of pair (it 
        // has to be done this way to keep the vertices 
        // sorted distance (distance must be first item 
        // in pair) 
        int u = pq.top().second; 
        pq.pop(); 
  
        // 'i' is used to get all adjacent vertices of a vertex 
        vector< pair<int, int> >::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            // Get vertex label and weight of current adjacent 
            // of u. 
            int v = (*i).first; 
            int weight = (*i).second; 
  
            //  If there is shorted path to v through u. 
            if (dist[v] > dist[u] + weight) 
            { 
                // Updating distance of v 
                dist[v] = dist[u] + weight; 
                pq.push(make_pair(dist[v], v)); 
            } 
        } 
    } 
  
    // Print shortest distances stored in dist[] 
    int dest=rand()%V+1;
    cout<<"Vertex   Distance from Source "<<src<<" to destination "<<dest<<" is "<<dist[dest]<<" \n"; 
} 

int main()
{
	srand(time(0));
    int N1=rand()%10,N2=rand()%10,N3=rand()%10;    
    vector<pair<int,int> > adj1[N1+N2+N3+1]; 
    int deg=2;
	makeTree(adj1,N1,deg);
    makeStar(adj1,N2,N1);
    makeRing(adj1,N3,N1+N2);

    cout<<"N1 "<<N1<<" deg "<<deg<<" N2 "<<N2<<" N3 "<<N3<<endl;
    
    int v1=rand()%N1+1,v2=rand()%N2+1+N1;
    //connecting Tree and Star
    addEdge(adj1,v1,v2,rand()%10);
    int v3=rand()%N2+1+N1,v4=rand()%N3+1+N1+N2;
    //connecting Star and Ring
    addEdge(adj1,v3,v4,rand()%10);

    cout<<" v1 "<<v1<<" v2 "<<v2<<" v3 "<<v3<<" v4 "<<v4<<endl;

    
    printList(adj1,N1+N2+N3);

    shortestPath(adj1,N1+N2+N3+1,rand()%(N1+N2+N3+1)+1);

}
