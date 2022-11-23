#include<iostream>
using namespace std;
int fib(int a)
{
    if((a==1)||(a==0))
    {
        return a;
    } 
    else{
        return (fib(a-1)+fib(a-2));
    }
}
int main()
{
    int num , i;
    cout<<"Enter the limit of the series"<<endl;
    cin>>num;
    cout<<"FIBONACCI SERIES\n";
    for(i=0; i<num; i++)
    {
        cout<<" "<<fib(i);
    }
    return 0;
}
