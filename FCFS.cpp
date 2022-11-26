#include<iostream>
using namespace std;
typedef struct algo{
    float at;
    float bt;
    float tt;
    float et;
    float wt;
}T; 
class FCFS{
    private:
        int size;
        T *arr;
    public:
        FCFS(int s){
            size = s;
            arr = new T[size];
        }
        void input(){
            cout<<"Enter the arrival time of each process:"<<endl;
            for(int i=0; i<size; i++){
                cin>>arr[i].at;
            }
            cout<<"Enter the burst time of each process:"<<endl;
            for(int i=0; i<size;i++){
                cin>>arr[i].bt;
            }
        }
        void algorithm(){
            input();
            int avg_t, avg_w;
            int time =0 ;
            for(int i=0;i<size; i++){
            	time += arr[i].bt;
            	arr[i].et=time;
			}
            cout<<"**********FCFS**********"<<endl;
            cout<<"Process\t\tArrival Time\tBurst Time\tExit Time\tTurnAround Time\tWaiting Time\n";
            for(int i=0; i<size;i++){
            	arr[i].tt=arr[i].et-arr[i].at;
            	avg_t += arr[i].tt;
            	arr[i].wt= arr[i].tt-arr[i].bt;
            	avg_w += arr[i].wt;
                cout<<"P"<<i<<"\t\t\t"<<arr[i].at<<"\t"<<arr[i].bt<<"\t"<<arr[i].et<<"\t"<<arr[i].tt<<"\t\t"<<arr[i].wt<<endl;
            }
            cout<<"Average turnaround time is: "<<endl;
            cout<<(avg_t/size)<<endl;
            cout<<"Average waiting time is: "<<endl;
            cout<<(avg_w/size)<<endl;
        }
    }
};
int main(){
	int proces;
    cout<<"Enter the number of processes"<<endl;
    cin>>proces;
    FCFS s(proces);
    s.algorithm();
    return 0;
}
        
