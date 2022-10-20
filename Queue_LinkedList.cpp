#include<iostream>
using namespace std;
class Queue;
class Node{
	int data;
	Node *next;
	friend Queue;
};
class Queue{
	private:
		Node *tail;
	public:
		Queue()
		{
			tail=NULL;
		}
		void enqueue(int item)
		{
			Node *p,*q;
			if(tail==NULL)
			{
				tail=new Node;
				tail->data=item;
				tail->next=tail;
				p=tail;
			}
			else{
				p=new Node;
				p->data=item;
				p->next=tail->next;
				tail->next=p;
				tail=p;
			}
		}
		void dequeue(){
			Node *p ;
			p=tail->next;
			cout<<p->data<<endl;
			tail->next=p->next;
			delete p;
			if(tail->next==tail){
				cout<<"The Queue is Empty"<<endl;
				return;  
			}
		}
};
int main()
{
	int item;
	Queue q;
	int choice;
	char ch;
	do{
		cout<<"Enter the choice:\n1)Enqueue\n2)Dequeue\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter the element want to enqueue"<<endl;
				cin>>item;
				q.enqueue(item);
				break;
			case 2:
				q.dequeue();
				break;
			default:
				cout<<"Wrong choice"<<endl;
				break;
		}
		cout<<"Do you want to enter again?(y/n)"<<endl;
		cin>>ch;
	}while(ch=='y');
	return 0;
	
}
