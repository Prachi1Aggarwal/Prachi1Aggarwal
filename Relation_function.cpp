#include<iostream>
using namespace std;
bool f,f1,f2,f3;
class RELATION
{
public:
    int size;
    char A[][20];
	

    RELATION()
    {
        size = 0;
    }
    void matric()
    {
        int p;
        char arr[20];
        cout << "Enter the elements of set and terminates by #" << endl;
        cin >> arr[0];
        for (p = 1; arr[p - 1] != '#'; p++)
        {
            cin >> arr[p];
        }
        size = p - 1;
        cout << "The cardinality of the set is: " << size << endl;
        for(int i=0; i<size; i++){
            for(int j=0; j<size ; j++)
            {
                A[i][j]='0';
            }
        }
        bool flag = true;
        cout << "Enter the relation A->A:" << endl;
        char ch;
        char R[1][2];
        int index1 =0, index2 =0;
        while (flag == true)
        {
            int count = 0;
            char a, b;
            cin >> R[0][0];
            cin >> R[0][1]; 
            a = R[0][0];
            b = R[0][1];
            int index1 =0, index2 =0;
            for (int i = 0; i < size; i++)
                
            {
                if (a == arr[i])
                {
                    index1 = i;
                }
                if (b == arr[i])
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

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << A[i][j] <<" ";
            }
            cout << endl; 
        }
       
    
    }
    void reflexive()
    {
        f = true;
        for (int i = 0; i < size; i++)
        {
            if (A[i][i] == '0')
            {
                f = false;
                
            }
        }
        if (f == false)
        {
            cout << "The given relation is not reflexive:" << endl;
        }
        else
        {
            cout << "The given relation is REFLEXIVE:" << endl;
        }
    }
    void symmetric(){
        f1=true;
        for(int i=0; i<size; i++)
        {
            for(int j=0 ; j<size ; j++)
            {
                if(A[i][j]!=A[j][i]){
                    f1=false;
                }
            }
        }
        if (f1 == false)
        {
            cout << "The given relation is not symmetric" << endl;
        }
        else
        {
            cout << "The given relation is SYMMETRIC:" << endl;
        }
    }
    void antisymmetric(){
        f2=true;
        for(int i=0; i<size; i++)
        {
            for(int j=0 ; j<size ; j++)
            {
                if(A[i][j]=='1'&&A[j][i]=='1'&&i!=j){
                    f2=false;
                }
            }
        }
        if (f2 == false)
        {
            cout << "The given relation is not anti symmetric" << endl;
        }
        else
        {
            cout << "The given relation is ANTI SYMMETRIC:" << endl;
        }
    }
    void transitive(){
    	f3=true;
    	for(int i=0; i<size; i++){
    		for(int j=0; j<size ; j++)
    		{
    			for(int k=0; k<size; k++)
    			{
    				if(A[i][j]=='1'&&A[j][k]=='1'&&A[i][k]!='1'){
    					
						f3= false;
						break;
					}
				}
			}
		}
		if (f3 == false)
        {
            cout << "The given relation is not transitive" << endl;
        }
        else
        {
            cout << "The given relation is TRANSITIVE" << endl;
        }
	}
	bool equivalent(){
       	if(f&&f1&&f3){
       		cout<<"Equivalent relation"<<endl;
       		return 1;
		}
		else{
			cout<<"not equivalent relation"<<endl;
			return 0;
		}
	}
	bool porel(){
       	if(f&&f2&&f3){
       		cout<<"Partial ordered relation"<<endl;
       		return 1;
		}
		else{
			cout<<"not partial ordered relation"<<endl;
			return 0;
		}
	}
};
int main()
{
    RELATION r;
    r.matric();
    r.reflexive();
    r.symmetric();
    r.antisymmetric();
    r.transitive();
    bool e = r.equivalent();
    bool p = r.porel();
    if(e!=1&&p!=1){
    	cout<<"the relation is neither equivalent nor porel"<<endl;
	}
    return 0;
}
