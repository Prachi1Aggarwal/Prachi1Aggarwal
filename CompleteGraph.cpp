#include<iostream>
using namespace std;
void adjancecy(char V[]);
void completeGraph(char A[][10],int n);
int main()
{
    char v[10];
    adjancecy(v);
    return 0;
}
void adjancecy(char V[])
{
    int num ;
    char A[10][10];
    cout<<"Enter the number of vertices "<<endl;
    cin>>num;
    char a;
    cout<<"Enter the name of the vertices"<<endl;
    for(int i=0; i<num ;i++)
    {
        cin>>V[i];
    }
    for(int a=0; a<num; a++)
    {
        for(int b=0; b<num ; b++)
        {
            A[a][b]='0';
        }
    }
    cout<<"Enter the pair of vertices for edges one by one"<<endl;
    char ch;
    char R[1][2];
    int index1 , index2;
    bool flag=true;
    while(flag==true)
    {
        int count=0;
        char a,b;
        cin>>R[0][0];
        cin>>R[0][1];
        a=R[0][0];
        b=R[0][1];
        bool ff=false;
        for(int i=0; i<num ;i++)
        {
            for(int j=0; j<num; j++)
            {
                if(a==V[i]&&b==V[j])
                {
                    ff=true;
                    break;
                }
            }
        }
        if(ff==false)
        {
            cout<<"Wrong pair of vertices enter again"<<endl;
        }
        index1=0 ;
        index2=0;
        for(int i=0; i<num; i++)
        {
            if(a==V[i])
            {
                index1=i;
            }
            if(b==V[i]){
                index2=i;
            }
        }
        A[index1][index2]='1';
        A[index2][index1]='1';
        cout<<"Do you want to choose more(y/n)"<<endl;
        cin>>ch;
        if(ch=='n')
        {
            flag=false;
        }
    }
    cout<<"The adjacency matrix is : "<<endl;
    for(int i=0; i<num ;i++)
    {
        for(int j=0; j<num; j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    completeGraph(A,num);
}
void completeGraph(char A[][10],int n)
{
    bool f=true;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(A[i][j]!='1'&&(i!=j))
            {
                f=false;
                break;
            }
        }
    }
    if(f==false)
    {
        cout<<"The given graph is not the complete graph"<<endl;
    }
    else {
        cout<<"The given graph is complete graph"<<endl;
    }
}
