#include <iostream.h>
#include <conio.h>

class dnode
 { public:
       int  data;
       dnode *next,*prev;
       dnode()   //default constructor
	  {
		next=prev=NULL;
	  }
       dnode(int x)   //parameterised constructor
	  {
		next=prev=NULL;
		data=x;
	  }

  };


class linkedlist
 {   dnode *head; //to store the address of the starting node
   public:
	linkedlist()
	    {
		head=NULL;
	    }
	~linkedlist(); // Destructor to delete a linked list.
	void create();
	void print();
	int count();
	int search(int x);
	void insert(int x,int loc);
	void Delete(int loc);
	void sort();
	void reverse();
	void merge(linkedlist &l1,linkedlist &l2);
 };

 linkedlist:: ~linkedlist()
     {
	dnode *p;
	while(head !=NULL)
	   {
		p=head;
		head=head->next;
		delete p;
	   }
     }
void linkedlist:: create()
  {
	int x,n,i;
	dnode *p;
	cout << "\n Enter no of nodes : ";
	cin>>n;
	for(i=0;i<n;i++)
	   {
		cout<<"\n Next Data : ";
		cin >> x;
		if(head==NULL) // inserting the first node
			head=p=new dnode(x);
		else
		    {
			p->next=new dnode(x);
			p->next->prev=p;
			p=p->next;
		    }
	   }
  }

 void linkedlist::print()
 {
	cout<<"\n Data stored in the Doubly linked list : ";
	for(dnode *p=head; p!=NULL ; p=p->next)
		cout<<p->data<<" ";
 }

 int linkedlist::count()
 {
	int i=0;
	for(dnode *p=head; p!=NULL ; p=p->next)
		i++;
	return i;
 }

 int linkedlist::search(int x)
 {
	int i=0;
	for(dnode *p=head; p!=NULL ; p=p->next)
	   {
		if(p->data == x)
			return(i);
		i++;
	   }
	return -1;
 }

 void linkedlist::insert(int x,int loc)
 {
	dnode *p=new dnode(x);
	if(loc==1) // inserting as a first node
	   {
		p->next=head;
		head->prev=p;
		head=p;
	   }
	else
	   {
		dnode *q=head;
		for(int i=1; i<loc-1;i++)
			if(q!=NULL)
				q=q->next;
			else
			   {
				cout <<"\nOverflow **** ";
				return;
			   }
     //insert a node as next node of q
		p->next=q->next;
		p->prev=q;
		q->next=p;
		q->next->prev=q;
	   }
 }

 void linkedlist::Delete(int loc)
 {
	dnode *p,*q;
	int i;
	if(loc==1) //Deleting the first node
	   {
		p=head;
		head=head->next;
		head->prev=NULL;
		delete p;
	   }
	else
	   {
		q=head;
		for(i=1;i<loc;i++) //postion q on the node to be deleted
		   {
			if(q==NULL)
			   {
				cout << "\n Undeflow *****";
				return;
			   }
			else
				q=q->next;
		    }
		if(q->next != NULL)
			q->next->prev=q->prev;
		q->prev->next=q->next;
		delete q;
	   }
 }

 void linkedlist::sort()
 {
	int i,j,temp;
	int n=count();
	dnode *p;
   //bubble sort is being used for sorting
	for(i=1;i<n;i++)
	   {
		p=head;           //p ponts to jth node
		for(j=0;j<n-i;j++,p=p->next)
			if(p->data > p->next->data)
			    { // interchange
				temp=p->data;
				p->data=p->next->data;
				p->next->data=temp;
			    }
	   }
 }
void linkedlist::reverse()
 {
	dnode *head1=NULL,*p; // head1 is the head of the new linked list
	while(head!=NULL)
	   {
		p=head;
		head=head->next;
		p->next=head1;
		head1->prev=p;
		head1=p;
	   }
	head=head1;  //new linked list becomes the currect linked list
}


 void linkedlist::merge(linkedlist &l1,linkedlist &l2)
 {
	dnode *p; //p points to the last node of the current linked list;
	if(l1.head==NULL) // if the first linked list is empty
	   {
		head=l2.head;
		l2.head=NULL;
		return;
	   }
	if(l2.head==NULL)  //if the second linked list is empty
	   {
		head=l1.head;
		l1.head=NULL;
		return;
	   }
	if(l1.head->data < l2.head->data)
	   {
		head=p=l1.head;
		l1.head=l1.head->next;
	   }
	else
	   {
		head=p=l2.head;
		l2.head=l2.head->next;
	   }
	while(l1.head !=NULL && l2.head != NULL)
		if(l1.head->data < l2.head->data)
		    {
			p->next=l1.head;
			l1.head->prev=p;
			l1.head=l1.head->next;
			p=p->next;
		    }
		else
		    {
			p->next=l2.head;
			l2.head->prev=p;
			l2.head=l2.head->next;
			p=p->next;
		    }

	if(l1.head !=NULL )
	    {
		p->next=l1.head;
		l1.head->prev=p;
	    }
	if(l2.head != NULL)
	    {
		p->next=l2.head;
		l1.head->prev=p;
	    }
	l1.head=l2.head=NULL;
}


void main()
 {
	int op,x,loc;
	linkedlist l,l1,l2;
	clrscr();
	do
	  {
		cout<<"\n\n1)Create\n2)Print\n3)Insert\n4)Delete\n5)length";
		cout<<"\n6)Search\n7)Reverse\n8)Merge two sorted linked list";
		cout<<"\n9)Sort\n10)Quit";
		cout<<"\nEnter your Choice : ";
		cin >> op;
		switch(op)
		  {
			case 1: l.create();break;
			case 2: l.print();break;
			case 3: cout<<"Enter the location :"; cin >> loc;
				cout<<"Enter the data  :"; cin>>x;
				l.insert(x,loc);break;
			case 4: cout<<"Enter the location :"; cin >> loc;
				l.Delete(loc);break;

			case 5: cout << "Length of the linked list = "<<l.count();
				break;
			case 6: cout << "Enter element to be searched : ";
				cin >> x;
				loc=l.search(x);
				if(loc==-1)
					cout << "\n Element not found ";
				else
					cout << "\n Found at location : "<<loc+1;
				break;
			case 7: l.reverse(); cout<<"Reversed linked list : ";
				l.print();break;
			case 8: cout<<"\n Creating first linked list ****\n";
				l1.create();l1.sort();
				cout<<"\n Creating second linked list ****\n";
				l2.create();l2.sort();
				l.merge(l1,l2);
				cout<<"\n Final Linked List *****\n";
				l.print();
				break;
			case 9: l.sort();
				cout <<"\nSorted Data :\n";
				l.print();
				break;
		}
	}while(op!=10);
   }

/*

OUTPUT:

1)Create
2)Print
3)Insert
4)Delete
5)length
6)Search
7)Reverse
8)Merge two sorted linked list
9)Sort
10)Quit
Enter your Choice : 1

 Enter no of nodes : 4

 Next Data : 1

 Next Data : 2

 Next Data : 3

 Next Data : 4


1)Create
2)Print
3)Insert
4)Delete
5)length
6)Search
7)Reverse
8)Merge two sorted linked list
9)Sort
10)Quit
Enter your Choice : 2

 Data stored in the Doubly linked list : 1 2 3 4

1)Create
2)Print
3)Insert
4)Delete
5)length
6)Search
7)Reverse
8)Merge two sorted linked list
9)Sort
10)Quit
Enter your Choice : 3
Enter the location :5
Enter the data  :55


1)Create
2)Print
3)Insert
4)Delete
5)length
6)Search
7)Reverse
8)Merge two sorted linked list
9)Sort
10)Quit
Enter your Choice : 2

 Data stored in the Doubly linked list : 1 2 3 4 55

1)Create
2)Print
3)Insert
4)Delete
5)length
6)Search
7)Reverse
8)Merge two sorted linked list
9)Sort
10)Quit
Enter your Choice :4
Enter the location :5


1)Create
2)Print
3)Insert
4)Delete
5)length
6)Search
7)Reverse
8)Merge two sorted linked list
9)Sort
10)Quit
Enter your Choice : 55


1)Create
2)Print
3)Insert
4)Delete
5)length
6)Search
7)Reverse
8)Merge two sorted linked list
9)Sort
10)Quit
Enter your Choice : 2

 Data stored in the Doubly linked list : 1 2 3 4

1)Create
2)Print
3)Insert
4)Delete
5)length
6)Search
7)Reverse
8)Merge two sorted linked list
9)Sort
10)Quit
Enter your Choice :5
Length of the linked list = 4

1)Create
2)Print
3)Insert
4)Delete
5)length
6)Search
7)Reverse
8)Merge two sorted linked list
9)Sort
10)Quit
Enter your Choice : 6
Enter element to be searched : 4

 Found at location : 4

1)Create
2)Print
3)Insert
4)Delete
5)length
6)Search
7)Reverse
8)Merge two sorted linked list
9)Sort
10)Quit
Enter your Choice : 7
Reversed linked list :
 Data stored in the Doubly linked list : 4 3 2 1

1)Create
2)Print
3)Insert
4)Delete
5)length
6)Search
7)Reverse
8)Merge two sorted linked list
9)Sort
10)Quit
Enter your Choice : 8
Enter your Choice : 8

 Creating first linked list ****

 Enter no of nodes : 3

 Next Data : 5

 Next Data : 6

 Next Data : 90

 Creating second linked list ****

 Enter no of nodes : 5

 Next Data : 4

 Next Data : 0

 Next Data : 88

 Next Data : 34

 Next Data : 22

 Final Linked List *****

 Data stored in the Doubly linked list : 0 4 5 6 22 34 88 90

1)Create
2)Print
3)Insert
4)Delete
5)length
6)Search
7)Reverse
8)Merge two sorted linked list
9)Sort
10)Quit
Enter your Choice : 9

 Data stored in the Doubly linked list : 0 4 5 6 22 34 88 90

1)Create
2)Print
3)Insert
4)Delete
5)length
6)Search
7)Reverse
8)Merge two sorted linked list
9)Sort
10)Quit
Enter your Choice : 10

*/
