#include<iostream>
using namespace std;
class Queue{
	int *arr;
	int size;
	int front;
	int rear;
	public:
		Queue(int s)
		{
			size = s;
			arr= new int[size];
			front =-1;
			rear= -1;
		}
		void enqueue(int item)
		{
			if(((front==0) && (rear==size-1))||(front==rear+1))
			{
				cout<<"Queue is Full ERROR"<<endl;
				return;
			}
			else{
				if(front==-1)
				{
					front=0;
					rear=0;
					arr[rear]=item;
				}
				else if(rear==size-1)
				{
					rear=0;
					arr[rear]=item;
				}
				else{
					rear++;
					arr[rear]=item;
				}
			}
		}
		void dequeue(){
			if(front==-1)
			{
				cout<<"Queue is Empty"<<endl;
				return;
			}
			else{
				if(front==rear)
				{
					cout<<arr[front]<<endl;
					front=-1;
					rear=-1;
				}
				else if(front==size-1)
				{
					cout<<arr[front]<<endl;
					front=0;
				}
				else{
					cout<<arr[front]<<endl;
					front++;
				}
			}
		}
};
int main()
{
	int item;
	int size;
	cout<<"Enter the size of your queue"<<endl;
	cin>>size;
	Queue q(size);
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
