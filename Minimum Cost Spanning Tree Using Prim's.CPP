#define infinity 9999
#define MAX 20
#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
class graph
{ int G[MAX][MAX];
  int n;
  public:
      graph()
	{ n=0; }
      void readgraph();
      void printgraph();
      int  prims(graph &);
};


void graph:: readgraph()
{
	int i,j,vi,vj,no_of_edges,weight;
	cout<<"\nEnter no. of vertices :";
	cin>>n;
	cout<<"\nEnter no of edges :";
	cin>>no_of_edges;
	for(i=0;i<n;i++) //Initialize the adjacency matrix
		for(j=0;j<n;j++)
			G[i][j]=0;
	cout<<"\nEnter the list of edges : ";
	for(i=0;i<no_of_edges;i++)
	{
		cout<<"\nEnter an edge (u,v,wight)  :";
		cin>>vi>>vj>>weight;
		G[vi][vj]=G[vj][vi]=weight;
	}
}

void  graph:: printgraph()
 {
	int i,j;
	cout<<"\nList of edges in the spanning tree: ";
	for(i=0;i<n-1;i++)//Scan the upper triangle of the adjacency matrix
		for(j=i+1;j<n;j++)
		    if(G[i][j]!=0)
			cout<<"\n(u,v,wight)= ("<<i<<","<<j<<","<<G[i][j]<<")";
 }

int  graph::prims(graph&g2)
{
	int cost[MAX][MAX];
	int u,v,min_distance,distance[MAX],from[MAX];
	int visited[MAX],no_of_edges,i,min_cost,j;

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(G[i][j]==0)
				cost[i][j]=infinity;
			else
				cost[i][j]=G[i][j];
		       spanning.G[i][j]=0;
		}
        distance[0]=0;visited[0]=1;
	for(i=1;i<n;i++)
	  {
		distance[i]=cost[0][i];
		from[i]=0;
		visited[i]=0;
	  }
	min_cost=0;            //cost of spanning tree
	no_of_edges=n-1;       //no.of edges to be added
	while(no_of_edges>0)
	  {

		min_distance=infinity;
		for(i=1;i<n;i++)
			if(visited[i]==0 && distance[i] < min_distance)
			  {
				v=i;
				min_distance=distance[i];
			  }
		u=from[v];

		g2.G[u][v]=distance[v];
		g2.G[v][u]=distance[v];
		no_of_edges--;
		visited[v]=1;

		for(i=1;i<n;i++)
			if(visited[i]==0 && cost[i][v] < distance[i])
			   {
				distance[i]=cost[i][v];
				from[i]=v;
			   }
		min_cost=min_cost+cost[u][v];
	}
	g2.n=n;
	return(min_cost);
}

void main()
{
	graph g1,g2;
	g1.readgraph();
	int total_cost=g1.prims(g2);
	cout<<"\nspanning tree matrix : \n";
	g2.printgraph();
	cout <<"\nTotal cost of spanning tree= "<<total_cost;
	getch();
}
