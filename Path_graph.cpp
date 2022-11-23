#include <iostream>
using namespace std;
void input();
void path(int A[][10], int num, char V[]);
int main()
{
    input();
    return 0;
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
    cout << "Enter the pair of edges" << endl;
    bool ff;
    for (int i = 0; i < e_num; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> E[i][j];
            for(int k=0; k<num; k++)
            {
                if (E[i][j] == V[k])
                {
                    ff = true;
                    break;
                }
                else{
                    ff=false;
                }
            }
            if(ff==false)
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
    path(A, num, V);
}
void path(int A[][10], int num, char V[])
{
    int res[10][10];
    int sum = 0;
    int length;
    cout << "Enter the length of the path" << endl;
    cin >> length;
    char start, dest;
    cout << "Enter the starting vertex" << endl;
    cin >> start;
    cout << "Enter the destination vertex" << endl;
    cin >> dest;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            res[i][j] = 0;
        }
    }
    for (int i = 0; i <= length; i++)//0
    {
        for (int j = 0; j <= length; j++)//0
        {
            for (int k = 0; k <= length; k++)//0//1//2
            {
                sum += A[i][k] * A[k][j];//0//1//1
            }
            res[i][j] = sum;
//            sum = 0;
        }
    }
    //01110
    //10011
    //10010
    //11101
    //01010
    cout << "The resultant matrix is: " << endl;
    //1
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    int i1, i2;
    for (int j = 0; j <= num; j++)
    {
        if (start == V[j])
        {
            i1 = j;
        }
        if (dest == V[j])
        {
            i2 = j;
        }
    }
    int l;
    if (res[i1][i2] != 0)
    {
        l = res[i1][i2];
        cout << "The total available path are " << endl;
        cout << l << endl;
    }
    else
    {
        cout << "There are no such path available" << endl;
    }

    return;
}
