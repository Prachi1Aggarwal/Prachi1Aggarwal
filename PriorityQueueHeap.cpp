#include<iostream>
#include<math.h>
using namespace std;
class Heap{
	private:
		int arr[100];
		int c,node;
	public:
		Heap(){
			c=-1;
		}
		int parent(int i){
			return (i-1)/2;
		}
		void insert(int x){
			c++; 
			arr[c]=x;
			node=c;
			while(node>0 && arr[parent(node)]>arr[node]){
				
				int temp = arr[node];
				arr[node]=arr[parent(node)];
				arr[parent(node)]=temp;
				node=parent(node);
			}
		}
		void removeMin(){
			node=0;
			arr[node]=arr[c];
			c=c-1;
			while(node<=c){
				if(arr[node]>arr[2*node+1] || arr[node]>arr[2*node+2]){
					if(arr[2*node+1]>arr[2*node+2]){
					int temp=arr[2*node+2];
					arr[2*node+2]=arr[node];
					arr[node]=temp;
					node=2*node+2;
					}
					else if(arr[2*node+1]<arr[2*node+2]){
						int temp=arr[2*node+1];
						arr[2*node+1]=arr[node];
						arr[node]=temp;
						node=2*node+1;
					}
					else{
						break;
					}
				}
				
			}
		}
		int min(){
			return arr[0];
		}
		void display(){
			for(int i=0;i<=c;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
};
int main(){
	int choice,item;
	char ch;
	Heap h;
	do{
		cout<<"Enter your choice:\n1)Insert\n2)Remove min\n3)traverse\n4)get min\n5)exit\n";
		cin>>choice;
		switch(choice){
			case 1:
				do{
					cout<<"Enter the item to be inserted:"<<endl;
					cin>>item;
					h.insert(item); 
					cout<<"Do you want to insert more?(y/n)"<<endl;
					cin>>ch;
				}while(ch=='y');
				break;
			case 2:
				h.removeMin() ;
				break;
			case 3:
				h.display() ;
				break;
			case 4:
				h.min() ;
				break;
			case 5:
				exit(0);
				break;
			default:
				cout<<"Wrong choice enter again"<<endl;
				break;
		}
		cout<<"Do you wanna choose more(y/n)?"<<endl;
		cin>>ch;
	}while(ch=='y');
	return 0;    
}
