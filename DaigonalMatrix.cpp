#include<iostream>
using namespace std;
class Diagonal{
    private:
        int size;
        int *arr;
    public:
        Diagonal(int s)
        {
           size = s;
            arr= new int[size];
        }
        void store(int ele, int i , int j)
        {
            if(i==j)
            {
                arr[i-1]=ele;
            }
            else{
                cout<<"element stored"<<endl;
            }
        }
        void retrieve(int i , int j){
            if(i!=j)
            {
                cout<<"0";
            }
            else{
                cout<<arr[i];
            }
        }
};
int main()
{
    int size;
    cout<<"Enter the dimension n of the square diagonal matrix"<<endl;
    cin>>size;
    Diagonal di(size);
    int i,j,element;
    int choice;
    char ch;
    do{
        cout<<"Enter the choice\n1)Store\n2)Retrieve\n3)Exit\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"Enter the element want to insert"<<endl;
            cin>>element;
            cout<<"Enter the dimension of the element"<<endl;
            cin>>i>>j;
            di.store(element,i,j);
            break;
            case 2:
            cout<<"Enter the dimension of retrieving element"<<endl;
            cin>>i>>j;
            di.retrieve(i,j);
            break;
            case 3:
            default:
            cout<<"Wrong choice enter again"<<endl;
            break;
        }
        cout<<"\nWant to choose more?(y/n)"<<endl;
        cin>>ch;
    }while(ch=='y');
    return 0;   
}
