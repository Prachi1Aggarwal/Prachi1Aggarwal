#include<iostream>
using namespace std;
class DoubleEQ;
class Node {
	friend DoubleEQ;
	int data;
	Node *next;
	Node *prev;
};
class DoubleEQ{
	private:
		Node *head;
		Node *tail;
	public:
		DoubleEQ(){
			head=NULL;
			tail=NULL;
		}
		void Insertion_at_front(int ele)
		{
			if (head==NULL)
			{
				head= new Node;
				head->data=ele;
				head->next=NULL;
				head->prev=NULL;
				tail=head;
			}
			else
			{
				Node *p;
				p= new Node;
				p->data= ele;
				p->next=head;
				p->prev=NULL;
				head=p;
			}
		}
		void Insertion_at_rear(int ele)
		{
			if(tail==NULL)
			{
				tail=new Node;
				tail->data=ele;
				tail->next=NULL;
				tail->prev=NULL;
				head=tail;
			}
			else
			{
				Node *p;
				p=new Node;
				p->data=ele;
				p->next=NULL;
				tail->next=p;
				p->prev=tail;
				tail=p;
			}
		}
		void Deletion_at_front()
		{
			Node *p = head;
			head= p->next;
			p->next->prev=NULL;
			delete p;
		}
		void Deletion_at_rear()
		{
			Node *p =tail;
			p->prev->next=NULL;
			tail=p->prev;
			delete p;
		}
		void traverse()
		{
			Node *p = head;
			while(p!=NULL){
				cout<<p->data<<" ";
				p=p->next;
			}
			cout<<endl;
		}
};
int main()
{
	DoubleEQ deq;
	int choice; 
	char ch;
	int item;
	do{
		cout<<"Enter your choice:\n1)Insert at front\n2)Insert at rear\n3)Delete from front\n4)Delete from rear\n5)Traverse\n6)Exit"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter the item to be inserted"<<endl;
				cin>>item;
				deq.Insertion_at_front(item);
				deq.traverse() ;
				break;
			case 2:
				cout<<"Enter the item to be inserted"<<endl;
				cin>>item;
				deq.Insertion_at_rear(item);
				deq.traverse() ;
				break;
			case 3:
				deq.Deletion_at_front() ;
				deq.traverse() ;
				break;
			case 4:
				deq.Deletion_at_rear() ;
				deq.traverse() ; 
				break;
			case 5:
				deq.traverse() ;
				break;
			case 6:
				exit(0);
				break;
			default:
				cout<<"Wrong choice Enter Again"<<endl;
				break;  
		}
		cout<<"Do you want to choose again(y/n)"<<endl;
		cin>>ch;
	}while(ch=='y');
	return 0;
}
