#include<iostream>
using namespace std;
void toh(int n, char a1, char a2, char a3)
{
    if(n==0)
    {
        return ;
    }
    else{
        toh(n-1,a1,a3,a2);
        cout<<"The disk "<<n<<" move from rod "<<a1<<" to rod "<<a2<<endl;
        toh(n-1,a3,a2,a1);
    }
}
int main()
{
	cout<<"********TOWER OF HANOI********"<<endl;
    int disk;
    cout<<"Enter number of disks"<<endl;
    cin>>disk;
    toh(disk,'A','B','C');
    return 0;
}
