#include<iostream>
using namespace std;
class Array
{
    private:
        int size;
        int *arr;
    public:
        Array(int s)
        {
            size=s;
            arr=new int[size];
        }
        void input()
        {
            cout<<"Enter the elements"<<endl;
            for(int i=0; i<size; i++)
            {
                cin>>arr[i];
            }
        }
        void display()
        {
            cout<<"The elements of the array are: "<<endl;
            for(int i=0; i<size; i++)
            {
                cout<<arr[i]<<" ";
            }
        }
        void linearSearch(int item)
        {
            bool flag=false;
            for(int i=0;i<size; i++){
                if(item==arr[i]){
                    cout<<"The element found at index "<<i<<endl;
                    flag=true;
                    break;
                }
                else{
                    flag=false;
                }
            }
            if(flag==false){
                cout<<(-1)<<endl;
            }
        }
};
int main()
{
    int size;
    cout<<"Enter the size of the array"<<endl;
    cin>>size;
    Array a(size);
    a.input();
    a.display();
    int s;
    cout<<"\nEnter the element want to search"<<endl;
    cin>>s;
    a.linearSearch(s);
    return 0;
}
