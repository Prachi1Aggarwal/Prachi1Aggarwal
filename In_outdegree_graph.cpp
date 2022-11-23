#include<iostream>
using namespace std;

void directed_in_out(char V[]);
int main()
{
	char v[20];
	directed_in_out(v);
	return 0;
}
void directed_in_out(char V[])
{
	char in[10],out[10];
	bool f=true;
	int num;
	char A[10][10];
	cout<<"Enter the number of vertices in the graph"<<endl;
	cin>>num;
	char a;
	cout<<"Enter the name of your vertices"<<endl;
	for(int i=0; i<num ;i++)
	{
		cin>>V[i];
	}
	for(int a=0; a<num; a++)
	{
		for(int b=0; b<num; b++)
		{
			A[a][b]='0';
		}
	}
	
	cout << "Enter the pairs of vertices to form an edge in the direction of vertice1-->vertice2:" << endl;
    char ch;
	char R[1][2];
    int index1 =0, index2 =0;
    bool flag=true;
    for(int i=0 ; i<num; i++)
    {
    	for(int j=0 ; j<num ;j++)
    	{
    		A[i][j]='0';
		}
	}
    while (flag == true)
    {
        int count = 0;
        char a, b;
        cin >> R[0][0];
        cin >> R[0][1]; 
        a = R[0][0];
        b = R[0][1];
        bool ff=false;
        for(int i=0; i<num ;i++)
        {
        	for(int j=0; j<num ;j++){
			
        		if(a==V[i] && b==V[j])
        		{
        			ff=true;
        			break;
				}
			}		
		}
		if(ff==false)
		{
			cout<<"ERROR! Wrong pair of vertices"<<endl;
		}
        for (int i = 0; i < num; i++)
                
        {
            if (a == V[i])
            {
                index1 = i;
            }
            if (b == V[i])
            {
                index2 = i;
            }
               
        }
        A[index1][index2]='1';
            
        cout << "Do you want to choose more (y/n)" << endl;
        cin >> ch;
        if (ch == 'n')
        {
            flag = false;
        }
    }
    cout<<endl;
    cout<<"The adjacency matrix is : "<<endl;
	for(int i=0; i<num; i++)
	{
		for(int j=0 ; j<num; j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	int sum_out=0;
	int sum_in=0;
	cout<<endl;
	cout<<"------------OUTDEGREES----------"<<endl; 
	cout<<endl;
	for(int i=0; i<num ; i++)
	{	
		cout<<"The outdegree of vertice "<<V[i]<<" is ";
		for(int j=0; j<num ; j++)
		{
			
			if(A[i][j]=='1')
			{
				sum_out+=1;
			}
		}
		cout<<sum_out;
		cout<<endl;
		sum_out=0;
	}
	cout<<endl;
	cout<<"-----------INDEGREES-----------"<<endl;
	cout<<endl;
	for(int i=0; i<num; i++)
	{
		cout<<"The indegree of vertice "<<V[i]<<" are ";
		for(int j=0 ; j<num ;j++)
		{
			if(A[j][i]=='1')
			{
				sum_in+=1;
			}
		}
		cout<<sum_in;
		cout<<endl;
		sum_in=0;
	}
}
