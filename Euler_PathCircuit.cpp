#include <iostream>
using namespace std;
void input();
void euler(int A[][10],int num);
int main()
{
    input();
}
void input()
{
    int A[10][10];
    int num;
    cout << "Enter the number of vertices" << endl;
    cin >> num;
    char V[num];
    cout << "Enter the name of your vertices" << endl;
    for (int i = 0; i < num; i++)
    {
        cin >> V[i];
    }
    int e_num;
    cout << "Enter the number of edges in your graph" << endl;
    cin >> e_num;
    char E[e_num][2];
    bool ff;
    cout << "Enter the pair of edges" << endl;
    for (int i = 0; i < e_num; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> E[i][j];
            for(int k=0; k<num;k++)
            {
            	if(E[i][j]==V[k])
            	{
           			ff=true;
					break; 		
				}
				else{
					ff=false;
				}
			}
			if(ff=false)
			{
				cout<<"Wrong vertex input"<<endl;
				ff=true;
				i--;
				break;	
			}
        }
    }
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            A[i][j] = 0;
        }
    }
    for (int i = 0; i < e_num; i++)
    {
        int index1 = 0;
        int index2 = 0;
        for (int j = 0; j <= num; j++)
        {
            if (E[i][0] == V[j])
            {
                index1 = j;
            }
            if (E[i][1] == V[j])
            {
                index2 = j;
            }
        }
        A[index1][index2] = 1;
        A[index2][index1] = 1;
    }
    cout << "The adjacency matrix is: " << endl;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    euler(A,num);
}
void euler(int A[][10],int num)
{
    int count=0;
    int deg=0;
    for(int i=0; i<num; i++)
    {
        for(int j=0; j<num; j++)
        {
            if(A[i][j]==1)
            {
                deg+=1;
            }
        }
        if(deg%2==0)
        {
            count++;
        }
        deg=0;
    }
    if(count==num)
    {
        cout<<"The given graph is Euler circuit"<<endl;
    }
    else{
        if(count==num-2)
        {
            cout<<"The given graph is euler path"<<endl;
        }
        else{
            cout<<"The given graph is neither euler circuit nor euler path"<<endl;
        }
    }
}
