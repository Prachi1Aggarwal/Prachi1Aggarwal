#include<iostream>
using namespace std;
typedef struct algo{
    bool done = false;
    float at;
    float bt;
    float tt;
    float et;
    float wt;
}T; 
class SJF{
    private:
        int size;
        T *arr;
    public:
        SJF(int s){
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
            float time=0;
            int count=0;
            float min=100;
            int index;
            while(count<size){
                for(int i=0; i<size;i++){
                    if(arr[i].at<=time && arr[i].done!=true){
                        if(arr[i].bt<min){
                            min=arr[i].bt;
                            index=i;
                        }
                    }
                }
                time += min;
                arr[index].et=time;
                min=100;
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
            cout<<"**********SJF**********"<<endl;
            cout<<"Process\t\tArrival Time\tBurst Time\tExit Time\tTurnAround Time\tWaiting Time\n";
            for(int i=0; i<size;i++){
                cout<<"P"<<i<<"\t\t\t"<<arr[i].at<<"\t"<<arr[i].bt<<"\t"<<arr[i].et<<"\t"<<arr[i].tt<<"\t\t"<<arr[i].wt<<endl;
            }
        }
};
int main(){
    int proces;
    cout<<"Enter the number of processes"<<endl;
    cin>>proces;
    SJF s(proces);
    s.algorithm();
    return 0;
}
