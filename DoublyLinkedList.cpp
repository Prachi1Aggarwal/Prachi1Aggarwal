#include<iostream>
using namespace std;
class Node{
	public:
		Node *next;
		Node *prev;
		int data;
};
class DoublyLinkedList{
	Node *head;
	public:
		DoublyLinkedList()
		{
			head=NULL;
		}
		void add_node(int x)
		{
			if(head==NULL){
				head=new Node;
				head->data=x;
				head->next=NULL;
				head->prev=NULL;
			}
			else{
				Node *p = head;
				while(p->next!=NULL){
					p=p->next;
				}
				Node *q;
				q=new Node;
				q->data=x;
				q->prev=p;
				q->next=NULL;
				p->next=q;
			}
		}
		void traverse()
		{
			Node *p= head;
			while(p!=NULL)
			{
				cout<<(p->data)<<" ";
				p=p->next;
			}
			cout<<endl;
		}
		void add_head_node(int x)
		{
			Node *p=head;
			Node *q= new Node;
			q->data=x;
			q->next=p;
			q->prev=NULL;
			p->prev=q;
			head=q;
		}
		void insert_node(int x, int i)
		{
			Node *p=head;
			Node *q;
			int counter =1;
			while(counter!=i)
			{
				p=p->next;
				counter++;
			}
			q=new Node;
			q->data=x;
			q->next=p;
			q->prev=p->prev;
			p->prev->next=q;
			p->prev=q;
		}
		void insert_node_end(int x)
		{
			Node *p=head;
			Node *q;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			q=new Node;
			q->data=x;
			q->prev=p;
			q->next=NULL;
			p->next=q;
		}
		void remove_head()
		{
			Node *p=head;
			p->next->prev=NULL;
			head=p->next;
			delete p;
		}
		void remove_node(int i)
		{
			Node *p = head;
			Node *q;
			q=p;
			int counter=1;
			while(counter!=i)
			{
				q=p;                                          
				p=p->next;
				counter++;
			}
			q->next= p->next;
			p->next->prev=q;
			delete p;
		}
		void remove_tail()
		{
			Node *p = head;
			Node *q;
			q=p;
			while(p->next!=NULL)
			{
				q=p;
				p=p->next;
			}
			q->next=NULL;
			delete p;
			
		}
		Node* search(int x)
		{
			Node *p= head;
			int found = 0;
			int count=1;
			while(p!=NULL)
			{
				if(p->data==x)
				{
					found=1;
					break;
				}
				p=p->next;
				count++;
			}
			if(found==1)
			{
				return p;
			}
			else{
				return 0;
			}
			
		}
		void concatenate(DoublyLinkedList obj)
		{
			Node *p = head;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			p->next=obj.head;
			obj.head->prev=p;
		}
};
int main()
{
	DoublyLinkedList d;
	int choice;
	int item;
	char ch;
	int i;
	do{
		cout<<"Enter your choice:\n1)add node\n2)traverse\n3)add head node\n4)insert node at pos i\n5)add node at end\n6)delete head node\n7)delete node at pos i\n8)delete end node\n9)search node and return pointer\n10)concatenate\n";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter the data of the node"<<endl;
				cin>>item;
				d.add_node(item);
						
				break;
			case 2:
				d.traverse();
				break;
			case 3:
				cout<<"Enter the data of the node"<<endl;
				cin>>item;
				d.add_head_node(item);
				d.traverse();
				break;
			case 4:
				cout<<"Enter the data of the node"<<endl;
				cin>>item;
				cout<<"Enter the position"<<endl;
				cin>>i;
				d.insert_node(item,i);
				d.traverse();
				break;
			case 5:
				cout<<"Enter the data of the node"<<endl;
				cin>>item;
				d.insert_node_end(item);
				d.traverse(); 
				break;
			case 6:
				d.remove_head();
				d.traverse() ;
				break;
			case 7:
				cout<<"Enter the position"<<endl;
				cin>>i;
				d.remove_node(i);
				d.traverse() ; 
				break;
			case 8:
				d.remove_tail() ;
				d.traverse() ;
				break;
			case 9:
				cout<<"Enter the item to be searched"<<endl;
				cin>>item;
				Node *q;
				q= d.search(item);
				if(q==0)
				{
					cout<<"The item not found"<<endl;
				}
				else{
					cout<<"The item "<<(q->data)<<" found "<<endl;
				}
				break;
			case 10:
				char choose;
				DoublyLinkedList d2;
				do{
					cout<<"Enter the item of the node in second list"<<endl;
					cin>>item;
					d2.add_node(item);
					cout<<"Do you want to enter element more(y/n)?"<<endl;
					cin>>choose;
				}while(choose=='y');
				d.concatenate(d2);
				d.traverse() ; 
				break;
		}		
		cout<<"Do you want to choose more(y/n)?"<<endl;
		cin>>ch;
	}while(ch=='y');
	return 0;
}
