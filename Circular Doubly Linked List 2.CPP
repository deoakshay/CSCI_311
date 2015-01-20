#include <iostream.h>
#include <conio.h>
class node
 {
	public:
		int  data;
		node *next;
		node()   //default constructor
		  {
			next=NULL;
		  }
		node(int x)   //parameterised constructor
		  {
			next=NULL;
			data=x;
		  }
  /* parameterised constructor will initialize the data field with x */
  };


class linkedlist
 {
	node *head; //to store the address of the starting node
	public:
		linkedlist() //Default constructor
		   {
			head=NULL;
		   }

		~linkedlist(); // Destructor to delete a linked list.
	void create();
	void print();
	int count();
	int search(int x);
	void insertf(int x);//insert at the front
	void insertr(int x);//insert at the rear
	void Deletef( );//Delete from the front
	void Deleter();//Delete from the Rear
 };

 linkedlist:: ~linkedlist()
     {
	node *p;
	if(head!=NULL)
	   {
		while(head->next!=head)
		   {
			p=head->next;
			head->next=p->next;
			delete p;
		   }
		delete head;
		head=NULL;
	    }
    }

void linkedlist:: create()
  {
	int x,n,i;
	node *p;
	cout << "\n Enter no of nodes : ";
	cin>>n;
	for(i=0;i<n;i++)
	   {
		cout<<"\n Next Data : ";
		cin >> x;
		if(head==NULL) // inserting the first node
		    {
			head=new node(x);
			head->next=head;
		    }
		else
		    {
			p=new node(x);
			p->next=head->next;
			head->next=p;
			head=p;
		    }
	   }
  }

 void linkedlist::print()
  {
	cout<<"\n Data stored in the linked list : ";
	node *p;
	if(head==NULL)
		return;
	p=head->next;
	do
	   {
		cout<<"  "<<p->data;
		p=p->next;
	   }while(head->next != p);
 }

int linkedlist::count()
 {
	int i=0;
	node *p;
	if(head==NULL)
		return 0;
	p=head->next;
   do
     {
	i++;
	p=p->next;
     }while(head->next != p);
   return i;
 }

int linkedlist::search(int x)
 {
	int i=0;
	node *p;
	if(head==NULL)
		 return -1;
	p=head->next;
	do
	   {
		i++;
		if(p->data==x)
			return i;
		p=p->next;
	   }while(head->next != p);
	return -1;
 }

void linkedlist::insertf(int x)
 {
	node *p;
	if(head==NULL) // inserting the first node
	    {
		head=new node(x);
		head->next=head;
	    }
	else
	    {
		p=new node(x);
		p->next=head->next;
		head->next=p;
	    }
 }

void linkedlist::insertr(int x)
 {
	node *p;
	if(head==NULL) // inserting the first node
	  {
		head=new node(x);
		head->next=head;
	  }
	else
	  {
		p=new node(x);
		p->next=head->next;
		head->next=p;
		head=p;
	  }

 }

 void linkedlist::Deletef()
   {
	node *p;
	if(head->next==head)
	  {
		delete head;
		head=NULL;
	  }
	else
	  {
		p=head->next;
		head->next=p->next;
		delete p;
	  }
  }

 void linkedlist::Deleter()
   {
	node *p;
	if(head->next==head)
	  {
		delete head;
		head=NULL;
	  }
	else
	  {
		p=head->next;
		while(p->next != head) // locate the predecessor of head node
			p=p->next;
		p->next=head->next;
		delete head;
		head=p;
	  }
  }

/* A program showing usage of class linkedlist */

void main()
 {
	int op,x,loc;
	linkedlist l,l1,l2;
	clrscr();
	do
	 {
		cout<<"\n\n1)Create\n2)Print\n3)Insert(front)\n4)insert(rear)";
		cout<<"\n5)Delete(front)\n6)Delete(rear)\n7)length";
		cout<<"\n8)Search\n9)Quit";
		cout<<"\nEnter your Choice : ";
		cin >> op;
		switch(op)
		   {
			case 1: l.create();break;
			case 2: l.print();break;
			case 3: cout<<"Enter the data  :"; cin>>x;
				l.insertf(x);break;
			case 4: cout<<"Enter the data  :"; cin>>x;
				l.insertr(x);break;
			case 5: l.Deletef();break;
			case 6: l.Deleter();break;
			case 7: cout << "Length of the linked list = "<<l.count();
				break;
			case 8: cout << "Enter element to be searched : ";
				cin >> x;
				loc=l.search(x);
				if(loc==-1)
					cout << "\n Element not found ";
				else
					cout << "\n Found at location : "<<loc;
				break;
		}
      }while(op!=9);
 }

/*

OUTPUT:

1)Create
2)Print
3)Insert(front)
4)insert(rear)
5)Delete(front)
6)Delete(rear)
7)length
8)Search
9)Quit
Enter your Choice : 1

 Enter no of nodes : 4

 Next Data : 1

 Next Data : 2

 Next Data : 3

 Next Data : 4


1)Create
2)Print
3)Insert(front)
4)insert(rear)
5)Delete(front)
6)Delete(rear)
7)length
8)Search
9)Quit
Enter your Choice : 2

 Data stored in the linked list :   1  2  3  4

1)Create
2)Print
3)Insert(front)
4)insert(rear)
5)Delete(front)
6)Delete(rear)
7)length
8)Search
9)Quit
Enter your Choice : 3
Enter the data  :55
1)Create
2)Print
3)Insert(front)
4)insert(rear)
5)Delete(front)
6)Delete(rear)
7)length
8)Search
9)Quit
Enter your Choice : 4
Enter the data  :45


1)Create
2)Print
3)Insert(front)
4)insert(rear)
5)Delete(front)
6)Delete(rear)
7)length
8)Search
9)Quit
Enter your Choice : 5


1)Create
2)Print
3)Insert(front)
4)insert(rear)
5)Delete(front)
6)Delete(rear)
7)length
8)Search
9)Quit
Enter your Choice : 6


1)Create
2)Print
3)Insert(front)
4)insert(rear)
5)Delete(front)
6)Delete(rear)
7)length
8)Search
9)Quit
Enter your Choice : 2

 Data stored in the linked list :   1  2  3  4

1)Create
2)Print
3)Insert(front)
4)insert(rear)
5)Delete(front)
6)Delete(rear)
7)length
8)Search
9)Quit
Enter your Choice : 7
Length of the linked list = 4

1)Create
2)Print
3)Insert(front)
4)insert(rear)
5)Delete(front)
6)Delete(rear)
7)length
8)Search
9)Quit
Enter your Choice : 8
Enter element to be searched : 4

 Found at location : 4

1)Create
2)Print
3)Insert(front)
4)insert(rear)
5)Delete(front)
6)Delete(rear)
7)length
8)Search
9)Quit
Enter your Choice : 9

*/
