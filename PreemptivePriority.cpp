#include<iostream>
using namespace std;
typedef struct process{
	float at;
	float bt;
	float et;
	float comp=0;
	float tt;
	float wt;
	int pr;
	bool done=false;	
} T;
class Priority{
	T *arr;
	int size;
	public:
		Priority(int s)
		{
			size=s;
			arr = new T[size];
		}
		void input(){
			cout<<"**********Arrival Time********"<<endl;
			for(int i=0 ; i<size; i++)
			{
				cout<<"AT of P"<<i<<"= ";
				cin>>arr[i].at;
			}
			cout<<"***********Burst Time**********"<<endl;
			for(int i=0 ; i<size; i++)
			{
				cout<<"BT of P"<<i<<"= ";
				cin>>arr[i].bt;
			}
			for(int i=0 ; i<size; i++)
			{
				cin>>arr[i].pr;
			}
		}
		void algorithm(){
			input();
			int time =0 ;
			int count=0;
			int index;
			int max=0;
			while(count<size){
				for(int i=0; i<size && arr[i].done==false; i++){
					for(int j=0; j<size; j++){
						if(arr[j].at<=time){
							if(arr[j].pr>max && arr[j].done==false){
								max=arr[j].pr;
								index=j;
							}
						}
					}
					if(arr[size-1].at<=time){
						for(int a=0; a<arr[index].bt && arr[index].comp<arr[index].bt; a++){
							arr[index].comp += 1;
							time += 1;
						}
						arr[index].et=time;
						arr[index].done = true;
						count++;
					}
					else{
						for(int a=0; time<arr[index+1].at && arr[index].comp<=arr[index].bt; a++){
							arr[index].comp += 1;
							time += 1;
						}
						if(arr[index].comp==arr[index].bt){
							arr[index].et=time;
							arr[index].done=true;
							count++;
						}
					}
					max=0;
				}
				
			}
			for(int i=0;i<size;i++){
                arr[i].tt=arr[i].et-arr[i].at;
            }
            for(int i=0; i<size; i++)
            {
                arr[i].wt= arr[i].tt-arr[i].bt;
            }
            cout<<"**********PRIORITY SCHEDULING**********"<<endl;
            cout<<"Process\t\tArrival Time\tPriority\tBurst Time\tExit Time\tTurnAround Time\tWaiting Time\n";
            for(int i=0; i<size;i++){
                cout<<"P"<<i<<"\t\t\t"<<arr[i].at<<"\t"<<arr[i].pr<<"\t\t"<<arr[i].bt<<"\t\t"<<arr[i].et<<"\t\t"<<arr[i].tt<<"\t\t"<<arr[i].wt<<endl;
            }
		}
};
int main(){
    int proces;
    cout<<"Enter the number of processes"<<endl;
    cin>>proces;
    Priority s(proces);
    s.algorithm();
    return 0;
}
