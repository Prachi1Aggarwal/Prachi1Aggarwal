#include<iostream>
using namespace std;
class Node{
	public:
	char data;
	Node *next;
};
//add head node
//add x at pos i
//remove head node
//remove ith pos node
//search x node and return its pointer
//concatenate two singly list
class SinglyLinkedList{
	Node *head;
	public:
	SinglyLinkedList()
	{
		head=NULL;
	}
	void add_node(int x)
	{
		if(head==NULL)
		{
			head=new Node;
			head->data=x;
			head->next=NULL;
		}
		else{
			Node *p=head;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			Node *q ;
			q=new Node;
			q->data=x;
			q->next = NULL;
			p->next=q;
		}
	}
	void add_head(int x)
	{
		Node *p=head;
		Node *q;
		q=new Node;
		q->data=x;
		q->next=p;
		head=q;
	}
	void insert_node(int x, int i)
	{
		Node *p=head;
		int counter=1;
		if(i==1)
		{
			add_head(x);		
		}
		else{
		
			while(counter!=i)
			{
				p=p->next;
				counter++;
			}
			Node *q;
			q=new Node;
			q->data=x;
			q->next=p->next;
			p->next=q;
		}
	}
	void remove_head()
	{
		Node *p=head;
		head=p->next;
		delete p;
	}
	void remove_ithNode(int i)
	{
		Node *p=head;
		Node *q;
		q=p;
		int counter=1;
		if(i==1)
		{
			remove_head();
		}
		else{
			while(counter!=i)
			{
				q=p;
				p=p->next;
				counter++;
			}
			q->next=p->next;
			delete p;
		}
	}
	void traverse()
	{
		Node *p=head;
		while(p!=NULL)
		{
			cout<<(p->data)<<" ";
			p=p->next;
		}
		cout<<endl;
	}
	Node* pointer_return(int i)
	{
		int counter=1;
		Node *p=head;
		while(counter!=i)
		{
			p=p->next;
			counter++;
		}
		return p;
	}
	void concatenate(SinglyLinkedList o2)
	{
		Node *p=head;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=o2.head;
		cout<<"The concatenated linked list is\n";
		traverse(); 
	}
	void search(int x){
		Node *p = head;
		int found=0;
		int count=1; 
		while(p!=NULL)
		{
			if(p->data==x){
				found=1;
				break;
			}
			p=p->next;
			count++;
		}
		if(found==1)
		{
			cout<<"Element found at "<<count<<" position"<<endl;
		}
		else{
			cout<<"Element not found"<<endl;
		}
	}
};
int main()
{
	int choice ;
	char ch;
	int j;
	int a;
	char item;
	SinglyLinkedList s;
	SinglyLinkedList s2;
	cout<<"Enter the elements of list and terminate by #"<<endl;
	while(item!='#'){
		cout<<"Enter the data of node"<<endl;
		cin>>item;
		s.add_node(item);
	}
	cout<<"Creation Finished"<<endl;
	do{
		cout<<"Choose:\n1)Insert an element x at the begining of the singly linked list\n2)Insert an element x at position in the singly linked list\n3)Remove an element from the beginning of the singly linked list\n3)Remove an element fromthe beginning of the singly linkedlist\n4)Remove an element from position in the singly linked list.\n5)Search for an element x in singly linked list\n6)Concatenate two singly linked list\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter the data"<<endl;
				cin>>item;
				s.add_head(item);
				s.traverse();
				break;
			case 2:
				cout<<"Enter the data"<<endl;
				cin>>item;
				cout<<"Enter the position"<<endl;
				cin>>j;
				s.insert_node(item,j);
				s.traverse();
				break;
			case 3:
				s.remove_head();
				cout<<"Removed"<<endl;
				s.traverse();
				break;
			case 4:
				cout<<"Enter the position"<<endl;
				cin>>j;
				s.remove_ithNode(j);
				cout<<"Removed"<<endl;
				s.traverse();
				break;
			case 5:
				cout<<"Enter the data to be searched"<<endl;
				cin>>item;
				s.search(item);
				s.traverse();
				break;
			case 6:
				
				cout<<"Enter the no. of elements in second singly linkedlist"<<endl;
				cin>>a;
				for(int i=0; i<a; i++)
				{
					cout<<"Enter the data of the node";
					cin>>item;
					s2.add_node(item);
				}
				s2.traverse();
				s.concatenate(s2);
				
				break;
			default:
				cout<<"Wrong choice choose again"<<endl;
				break;
		}
		
		cout<<"\nDo you want to choose again(y/n)?"<<endl;
		cin>>ch;
	}while(ch=='y');
	s.traverse();
	return 0;
}
