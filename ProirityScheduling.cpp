#include<iostream>
using namespace std;
typedef struct process{
	float at;
	float bt;
	float et;
	float tt;
	float wt;
	int pr;
	bool done=false;	
} T;
class Priority{
	int size;
	T *arr;
	public:
		Priority(int s){
			size= s;
			arr = new T[size];
		}
		void algorithm()
		{
			float time=0.0;
			int count=0;
			int high;
			int index;
			cout<<"Enter the priority of each process"<<endl;
			for(int i=0; i<size ;i++)
			{
				cin>>arr[i].pr;
			}	
			cout<<"Enter the arrival time of each process"<<endl;
			for(int i=0; i<size; i++){
				cin>>arr[i].at;
			}
			cout<<"Enter the burst time of each process"<<endl;
			for(int i=0; i<size; i++){
				cin>>arr[i].bt;
			}
			while(count<size){
				high=50;
				for(int i=0 ;i<size; i++){
					if(time>=arr[i].at && arr[i].done!=true){
						if(arr[i].pr<high){
							high = arr[i].pr;
							index=i;
						}
					}
				}
				time += arr[index].bt;
				arr[index].et= time;
				count++;
				arr[index].done=true;
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
                cout<<"P"<<i<<"\t\t\t"<<arr[i].at<<"\t"<<arr[i].pr<<"\t"<<arr[i].bt<<"\t"<<arr[i].et<<"\t"<<arr[i].tt<<"\t\t"<<arr[i].wt<<endl;
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
