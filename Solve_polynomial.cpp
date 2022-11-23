#include<iostream>
#include<cmath>
using namespace std;
int polynomial(int n , int d, int arr[]);
int main()
{
    int degree;
    int n;
    int result;
    cout<<"Enter the degree of the polynomial"<<endl;
    cin>>degree;
    int arr[degree+1];
    cout<<"Enter the coefficients of the equation"<<endl;
    for(int i=0; i<=degree; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the value of n in f(n) at which want to find the solution"<<endl;
    cin>>n;
    result=polynomial(n,degree,arr);
    cout<<"The solution of the equation is"<<endl;
    int d=degree;
    for(int i=0; i<=degree; i++)
    {
        cout<<arr[i]<<"n^"<<d<<" + ";
        d--;
    }
    cout<<" with the value of n= "<<n<<" is "<<endl;
    cout<<result<<endl;
    return 0; 
}
int polynomial(int n, int d , int arr[])
{
    int equal;
    int sum=0;
    equal=d;
    for(int i=0; i<=d; i++)
    {
        sum+= arr[i]*pow(n,equal);
        --equal;
    }
    return sum;
}
