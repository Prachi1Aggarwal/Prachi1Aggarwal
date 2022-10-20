#include<iostream>
using namespace std;
class Node{
	public:
	Node *next;
	int data;
};
class CirculateLL{
	Node *tail;
	public:
	CirculateLL()
	{
		tail=NULL;
	}
	void add_node(int ele){
		Node *p;
		Node *q;
		if(tail==NULL)
		{
			p=new Node;
			p->data= ele;
			p->next=p;
			tail=p;
		}
		else{
			p=new Node;
			p->data=ele;
			p->next=tail->next;
			tail->next=p;
			tail=p;
		}
	}
	void traverse()
	{
		Node *p = tail->next;
		while(p!=tail){
			cout<<p->data<<" ";
			p=p->next;
		}
		cout<<tail->data<<" ";
		cout<<endl;
	}
	void head_node(int ele){
		Node *p;
		p=new Node;
		p->data=ele;
		p->next=tail->next;
		tail->next=p;
		traverse();
	}
	void insert_after(int y, int x)
	{
		Node *p;
		Node *q;
		if(tail->data==x){
			head_node(y);
		}
		else{
			p=tail->next;
			while(p->data!=x){
				p=p->next;
				
			}
			q=new Node;
			q->data=y;
			q->next=p->next;
			p->next=q;
		}
		traverse();
	}
	void tail_node(int ele)
	{
		Node *p ;
		p=new Node;
		p->data=ele;
		p->next=tail->next;
		tail->next=p;
		tail=p;
		traverse();
	}
	void remove_tail(){
		Node *p=tail->next;
		while(p->next!=tail)
		{
			p=p->next;
		}
		p->next=tail->next;
		delete tail;
		tail=p;
		traverse();
	}
	void remove_head(){
		Node *p = tail->next;
		tail->next=p->next;
		delete p;
		traverse();
	}
	void remove_x(int x)
	{
		Node *p = tail->next;
		Node *q;
		if(tail->data==x){
			remove_tail();
		}
		else if(p->data==x)
		{
			remove_head();
		}
		else{
			q=p;
			while(p->data!=x)
			{
				q=p;
				p=p->next;
			}
			q->next=p->next;
			delete p;
		}
		traverse();
	}
	Node* search(int x)
	{
		Node *p = tail->next;
		if(tail->data==x)
		{
			return tail;
		}
		else if(p->data==x){
			return p;
		}
		else{
			while(p!=tail){
				p=p->next;
				if(p->data==x)
				{
					return p;
				}
			}
		}
		return 0;
	}
	void concatenate(CirculateLL c1){
		Node *q;
		q=c1.tail;
		Node *p = tail->next;
		tail->next= c1.tail->next;
		q->next=p;
		
		tail=c1.tail ;
		traverse();
	}
};
int main()
{
	CirculateLL d;
	int choice;
	int item;
	char ch;
	int i;
	do{
		cout<<"Enter your choice:\n1)add node\n2)traverse\n3)add head node\n4)insert node after element x\n5)add tail node\n6)delete head node\n7)delete node element x\n8)delete tail node\n9)search node and return pointer\n10)concatenate\n";
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
				d.head_node(item);
				d.traverse();
				break;
			case 4:
				int pos;
				cout<<"Enter the data of the node"<<endl;
				cin>>item;
				cout<<"Enter the x node"<<endl;
				cin>>pos;
				d.insert_after(item,pos);
				d.traverse();
				break;
			case 5:
				cout<<"Enter the data of the node"<<endl;
				cin>>item;
				d.tail_node(item);
				d.traverse(); 
				break;
			case 6:
				d.remove_head();
				d.traverse() ;
				break;
			case 7:
				cout<<"Enter the element x want to remove"<<endl;
				cin>>item;
				d.remove_x(item);
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
				CirculateLL d2;
				do{    
					cout<<"Enter the item of the node in second list"<<endl;
					cin>>item;
					d2.add_node(item);
					cout<<"Do you want to enter element more(y/n)?"<<endl;
					cin>>choose;
				}while(choose=='y');
				d.concatenate(d2);
				break;
		}		
		cout<<"Do you want to choose more(y/n)?"<<endl;
		cin>>ch;
	}while(ch=='y');
	return 0;
}
