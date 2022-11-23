#include<iostream>
using namespace std;
class allocation
{
	private:
		int size;
		int *arr;
		int hole;
		int *holeArr;
	public:
		allocation(int s, int h){
			size=s;
			hole=h;
			arr= new int[size];
			holeArr= new int[hole];
		}	
		void input()
		{
			cout<<"Enter the process size"<<endl;
			for(int i=0; i<size; i++)
			{
				cout<<"Enter the size of process P"<<i;
				cin>>arr[i];	
			}		
			cout<<"Enter the sizes of the holes"<<endl;
			for(int i=0; i<hole; i++)
			{
				cin>>holeArr[i];
			}
		}		
		void firstFit(){
			for(int i=0; i<size; i++)
			{
				for(int j=0; j<hole; j++)
				{
					if(arr[i]<holeArr[j]){
						holeArr[j] -= arr[i];
						break;
					}
				}
			}
			for(int i=0; i<hole;i++)
			{
				cout<<holeArr[i]<<" ";
			}
		}
		void bestFit(){
			int min= 5000;
			int index;
			for(int i=0; i<size; i++)
			{
				for(int j=0; j<hole;j++)
				{
					if(arr[i]<=holeArr[j]){
						if(min>holeArr[j]){
							
							min = holeArr[j];
							index =j;
							
						}
					}
				}
				holeArr[index] -= arr[i];
				min= 5000;
			}
			for(int i=0; i<hole;i++)
			{
				if(holeArr[i]<0){
					cout<<"Not able to get any hole"<<endl;
					break;
				}
				cout<<holeArr[i]<<" ";
			}
		}
		void worstFit(){
			int max= 0;
			int index;
			for(int i=0; i<size; i++)
			{
				for(int j=0; j<hole;j++)
				{
					if(arr[i]<=holeArr[j]){
						if(max<holeArr[j]){
							
							max = holeArr[j];
							index =j;
							
						}
					}
				}
				holeArr[index] -= arr[i];
				max= 0;
			}
			for(int i=0; i<hole;i++)
			{
				if(holeArr[i]<0){
					cout<<"Not able to get any hole"<<endl;
					break;
				}
				cout<<holeArr[i]<<" ";
			}
		}
};
int main()
{
	int size, hole;
	cout<<"Enter the number of processes"<<endl;
	cin>>size;
	cout<<"Enter the number of holes available in physical memory"<<endl;
	cin>>hole;
	allocation a(size, hole);
	a.input();
	int choice;
	char ch; 
	do{
		cout<<"Enter your choice:\n1)FirstFit\n2)BestFit\n3)WorstFit\n"<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				a.firstFit() ;
				break;
			case 2:
				a.bestFit() ;
				break;
			case 3:
				a.worstFit() ;
				break;
			default:
				cout<<"Wrong choice enter again"<<endl;
				break;
		}
		cout<<"Do you want to choose more(y/n)?"<<endl;
		cin>>ch;
	}while(ch=='y');
	return 0;
}
