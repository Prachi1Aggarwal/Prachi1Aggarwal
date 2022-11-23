#include<iostream>
using namespace std;
int fact(int n);
int main()
{
    int n;
    cout<<"Enter the total number of elements:"<<endl;
    cin>>n;
    int r;
    cout<<"Enter number of elements arranged or select:"<<endl;
    cin>>r;
    cout<<"Permutation is : nPr"<<endl;
    int P;
    P = fact(n)/fact(n-r);
    cout<<P<<endl;
    int C;
    cout << "Combination is : nCr"<<endl;
    C = fact(n)/(fact(r)*fact(n-r));
    cout<<C<<endl;
}
int fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    else{
        return n*fact(n-1);
    }
}
