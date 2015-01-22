#define infinity 9999
#define MAX 20
#include<conio.h>
#include<iostream.h>
#include<stdlib.h>

class Q
{
	int data[30];
	int R,F;
	public:
	Q()
	  {
		R=F=-1;
	  }

	void init()
	  {
		R=F=-1;
	  }

	int empty()
	  {
		if(R==-1)
			return 1;
		return 0;
	  }
	void insert(int x)
	  {
		if(empty())
			R=F=0;
		else
			R=R+1;
		data[R]=x;
	  }

	int Delete()
	  {
		int x=data[F];
		if(R==F)
			R=F=-1;
		else
			F=F+1;
		return(x);
	  }
 };

struct node
  {
	node *next;
	int vertex;
  };

class graph
{
	int visited[MAX];
	node *G[20];  		//heads of the linked list
	int n;          	// no of nodes
	void insert(int vi,int vj);   //insert an edge (vi,vj)in adj.list
	void DFS1(int);//recursive counterpart of DFS
	public:
		graph()
		  {
			n=0;
		  }
	void readgraph();
	void BFS(int);
	void DFS(int);
};
void graph::DFS(int start)
  {
	for(int i=0;i<n;i++)
		visited[i]=0;
	DFS1(start);
  }
void graph::BFS(int v)
{
	int i,w;
	Q q;
	node *p;
	for(i=0;i<n;i++)
		visited[i]=0;
	q.insert(v);
	cout<<"\n Visit  "<<v;
	visited[v]=1;
	while(!q.empty())
	   {
		v=q.Delete();
		//insert all unvisited,adjacent vertices of v into queue
		for(p=G[v];p!=NULL;p=p->next)
		   {
			w=p->vertex;
			if(visited[w]==0)
			  {
				q.insert(w);
				visited[w]=1;
				cout<<"\nvisit  "<<w;
			  }
		   }
	   }
}

void graph::DFS1(int i)
{
	node *p;
	cout<<"\n"<<i;
	p=G[i];
	visited[i]=1;
	while(p!=NULL)
	{
		i=p->vertex;
		if(!visited[i])
			DFS1(i);
		p=p->next;
	}
}


void graph::readgraph()
{
	int i,vi,vj,no_of_edges;
	cout<<"\nEnter no. of vertices :";
	cin>>n;
	//initialise G[] with NULL
	for(i=0;i<n;i++)
		G[i]=NULL;
	//read edges and insert them in G[]
	cout<<"\nEnter no of edges :";
	cin>>no_of_edges;
	for(i=0;i<no_of_edges;i++)
	{
		cout<<"\nEnter an edge (u,v)  :";
		cin>>vi>>vj;
		insert(vi,vj);
		insert(vj,vi);
	}
}
void graph::insert(int vi,int vj)
{
	node *p,*q;
	//acquire memory for the new node
	q=new node ;
	q->vertex=vj;
	q->next=NULL;
	//insert the node in the linked list for the vertex no. vi
	if(G[vi]==NULL)
		G[vi]=q;
	else
	{
		// go to the end of linked list
		p=G[vi];
		while(p->next!=NULL)
			p=p->next;
		p->next=q;
	}
}


void main()
{       int op,start,n;
	graph g1;
	clrscr();
	do {
		cout<<"\n\n1)Create a graph \n2)BFS\n3)DFS\n4)Quit";
		cout<<"\nEnter Your Choice : ";
		cin >> op;
		switch(op)
		   {
			case 1:	g1.readgraph();break;
			case 2: cout<<"\nEnter starting node : ";
				cin>>start;
				g1.BFS(start); break;
			case 3: cout<<"\nEnter starting node : ";
				cin>>start;
				g1.DFS(start);break;
		    }

	    }while(op != 4);

}

/*

OUTPUT:

1)Create a graph
2)BFS
3)DFS
4)Quit
Enter Your Choice : 1

Enter no. of vertices :8

Enter no of edges :10

Enter an edge (u,v)  :0 1

Enter an edge (u,v)  :0 2

Enter an edge (u,v)  :1 3

Enter an edge (u,v)  :1 4

Enter an edge (u,v)  :2 5

Enter an edge (u,v)  :2 6

Enter an edge (u,v)  :3 7

Enter an edge (u,v)  : 4 7

Enter an edge (u,v)  :5 7

Enter an edge (u,v)  :6 7
1)Create a graph
2)BFS
3)DFS
4)Quit
Enter Your Choice : 2

Enter starting node : 1

 Visit  1
visit  0
visit  3
visit  4
visit  2
visit  7
visit  5
visit  6

1)Create a graph
2)BFS
3)DFS
4)Quit
Enter Your Choice : 3

Enter starting node : 1

1
0
2
5
7
3
4
6

1)Create a graph
2)BFS
3)DFS
4)Quit
Enter Your Choice : 4

*/
