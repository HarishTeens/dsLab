#include <bits/stdc++.h> 
using namespace std; 
# define INF 9999
# define N 10

  
void addEdge(int adj[N][N], int u, int v) 
{ 
    adj[u][v]=1;    
} 


void printMatrix(int adj1[N][N]){
	for(int i=0;i<N;++i){
        int deg=0;
        cout<<i<<" - ";
        for(int j=0;j<N;++j){
            if (adj1[i][j] == INF)  
                cout<<"INF"<<"     ";  
            else
                cout<<adj1[i][j]<<"     ";  
            if(adj1[i][j]!=INF)
                deg+=adj1[i][j];
        }
        cout<<"(deg="<<deg<<")";
        cout<<endl;
    }
}

void makeTopology(int adj[N][N])
{
    for(int i=0;i<N;++i){
        int deg=rand()%2+2;
        while(deg){
            int node=rand()%10;
            if(node!=i&&adj[i][node]==INF){            
                addEdge(adj,i,node);
                --deg;
            }
        }
    }
}
/* A utility function to print solution */
void printSolution(int dist[][N])  
{  
    cout<<"The following matrix shows the shortest distances"
            " between every pair of Vertices \n";  
    for (int i = 0; i < N; i++)  
    {  
        for (int j = 0; j < N; j++)  
        {  
             if (dist[i][j] == INF)  
                cout<<"INF"<<"     ";  
            else
                cout<<dist[i][j]<<"     ";  
        }  
        cout<<endl;  
    }  
}
void floydWarshall (int graph[N][N])  
{  
    /* dist[][] will be the output matrix  
    that will finally have the shortest  
    distances between every pair of vertices */
    int dist[N][N], i, j, k;  
  
    /* Initialize the solution matrix same  
    as input graph matrix. Or we can say  
    the initial Nalues of shortest distances 
    are based on shortest paths considering  
    no intermediate Nertex. */
    for (i = 0; i < N; i++)  
        for (j = 0; j < N; j++)  
            dist[i][j] = graph[i][j];  
    
    /* Add all Nertices one by one to  
    the set of intermediate Nertices.  
    ---> Before start of an iteration,  
    we haNe shortest distances between all  
    pairs of Nertices such that the  
    shortest distances consider only the  
    Nertices in set {0, 1, 2, .. k-1} as 
    intermediate Nertices.  
    ----> After the end of an iteration,  
    Nertex no. k is added to the set of  
    intermediate Nertices and the set becomes {0, 1, 2, .. k} */
    for (k = 0; k < N; k++)  
    {  
        // Pick all Nertices as source one by one  
        for (i = 0; i < N; i++)  
        {  
            // Pick all Nertices as destination for the  
            // aboNe picked source  
            for (j = 0; j < N; j++)  
            {  
                // If Nertex k is on the shortest path from  
                // i to j, then update the Nalue of dist[i][j]  
                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
            }  
        }  
    }  
  
    // Print the shortest distance matrix  
    printSolution(dist);  
}  
  

int main()
{
	srand(time(0));
    //the Adjacency matrix
    int adj1[N][N]; 
    //initialising matrix with 0
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            adj1[i][j]=INF;
    // printMatrix(adj1);
    makeTopology(adj1);

    printMatrix(adj1);

    floydWarshall(adj1);
    

}
