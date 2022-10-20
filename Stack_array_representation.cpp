#include<iostream>
using namespace std;
class Stack{
	int top;
	int *arr;
	int size;
	public:
		Stack(int s){
			size=s;
			top=-1;
			arr=new int[size];	
		}
		void push(int ele){
			if(top==size-1){
				cout<<"OverFlow ERROR!!!"<<endl;
				return;
			}
			else{
				top++;
				arr[top]=ele;
			}
		}
		int pop(){
			if(top==-1){
				cout<<"UnderFlow ERROR!!"<<endl;
				exit(0);
			}
			else{
				int x = arr[top];
				top--;
				return x;
			}
		}
};
int main(){
	int size;
	cout<<"Enter the size of the stack"<<endl;
	cin>>size;
	int item;
	char ch;
	int choose;
	Stack s(size);
	do{
		cout<<"Choose:\n1)Push\n2)Pop\n";
		cin>>choose;
		switch(choose){
			case 1:
				cout<<"Enter the element of the stack"<<endl;
				cin>>item;
				s.push(item);
				break;
			case 2:
				int x;
				x= s.pop();
				cout<<x<<" ";
				break;
			default:
				cout<<"Wrong choice Enter again"<<endl;
				break;
		}
		cout<<"\nDo you want to choose more?(y/n)"<<endl;
		cin>>ch;
	}while(ch=='y');
	return 0;
}
