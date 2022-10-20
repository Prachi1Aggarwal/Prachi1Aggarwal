#include<iostream>
 #include<cmath>
using namespace std;
char arr[20];
char arr1[20];
void menu(char a[],char a1[],int i,int i2);
int input(char a[]);
bool is_member(int n1,char ch, char a[]);
void subset(char arr[],int i);
void binary(int n,int num,char arr[]);
class SET
{
	private:
		int n1;
		int n2;
	public:
		SET(){
			n1=0;
			n2=0;
		}
		SET(int s1,int s2)
		{
			n1=s1;
			n2=s2;
		}
		void is_subset(int n1,int n2 ,char a[],char a1[])
		{
			
    		int i,j,k;
    		int count=0;
    		for(i=0; i<n1; i++)
   			{
   	    		for(j=0; j<n2; j++)
        		{
            		if(a[i]==a1[j])
            		{
                		count++;
            		}
        		}
    		}
    		if(count==n1)
    		{
        		cout<<"set1 is the subset of set2"<<endl;
    		}
    		else
    		{
        		cout<<"set1 is the not the subset of set2"<<endl;
    		}
		}
		void Union_Intersection(int n1,int n2,char a[], char a1[])
		{
			
    		int i,j,k;
    		char un[n1+n2];
    		int count=0;
    		for(i=0; i<n1; i++){
        		un[i]=a[i];
        		count++;
    		}
    		for(j=0; j<n2; j++){
        		bool flag=false;
        		for(k=0; k<n1; k++){
            		if(a1[j]==a[k]){
                		k=n1;
                		flag=true;
            		}
        		}
        		if(flag==false)
        		{
            		un[i]=a1[j];
            		count++;
            		i++;
        		}
    		}
    		for(int m=0; m<count; m++)
    		{
        		cout<<un[m]<<" ";
    		}
    		int p=0;
    		int q,r;
    		char inter[n1+n2];
    		for(q=0; q<n2; q++)
    		{
        		for(r=0; r<n1; r++)
        		{
            		if(arr1[q]==arr[r])
            		{
                	    inter[p]=arr1[q];
                	    p++;
            		}
        		}
    		}
    		cout<<"\nThe intersection of the sets are:\n";
    		for(int aa=0; aa<p; aa++)
    		{
        		cout<<inter[aa]<<" ";
    		}

		}
		void difference(int n1, int n2, char a[], char a1[])
		{
    		int i=0;
    		int j,k;
    		char differ[n1+n2];
    		for(j=0; j<n1; j++)
    		{
        		bool flag=false;
        		for(k=0; k<n2; k++)
        		{
            		if(a[j]==a1[k])
            		{
                		k=n2;
                		flag=true;
            		}
        		}
        		if(flag == false)
        		{
            		differ[i]=a[j];
            		i++;
        		}
    		}
    		cout<<"The difference of set1-set2 sets are:\n";
    		for(int r=0; r<i; r++)
    		{
        		cout<<differ[r]<<" ";
    		}
		}
		void symmetric(int n1, int n2 , char a[], char a1[])
		{
    		int i=0;
    		int j,k;
    		int aa,b;
    		int c=0;
    		char differ[n1+n2];
    		char differ1[n1+n2];
    		for(j=0; j<n1; j++)
    		{
        		bool flag=false;
        		for(k=0; k<n2; k++)
        		{
            		if(a[j]==a1[k])
            		{
                		k=n2;
                		flag=true;
            		}
        		}
        		if(flag == false)
        		{
            		differ[i]=a[j];
            		i++;
            // cout<<"i= "<<i<<endl;
        		}
    		}
    		for(aa=0; aa<n2; aa++)
    		{
    		    bool flagi=false;
        		for(b=0; b<n1; b++)
        		{
        		    if(a1[aa]==a[b])
        		    {
        		        b=n1;
        		        flagi=true;
            		}
        		}
        		if(flagi == false)
        		{
        		    differ1[c]=a1[aa];
            		c++;
        		}
    		}
    		Union_Intersection(i,c,differ,differ1);
    	}
		
		
};
int main()
{
	int size1,size2;
	size1 = input(arr);
	size2 = input(arr1);
	menu(arr,arr1,size1,size2);
//	SET s;
//	s.is_subset(arr,arr1);
	return 0;
}
int input(char a[])
{
	int i;
    cout<<"Enter the elements of your set and terminates by entering character '%'"<<endl;
    cin>>a[0];
    for(i=1; a[i-1]!='%';i++){
        cin>>a[i];
    }
    return i-1;
}
bool is_member(int n1,char ch, char a[])
{
	
	bool flag=false;
    for(int i=0; i<n1; i++)
    {
        if(ch==a[i])
        {
            flag=true;
        }
    }
    if(flag==true){
        return true;
    }
    else{
        return false;
    }
}
void menu(char a[],char a1[],int i,int i2)
{
    int choice; 
    char choose;
    do{
        cout<<"Enter your choice\n1)Power set\n2)Union & Intersection\n3)Difference & Symmetric Difference\n4)Check_Subset or not\n5)Belong to\n6)Complement\n";
        cin>>choice;
        //done
        if(choice==1){
            subset(arr,i);
        }
        //done
        else if(choice==2){
            SET s;
            cout<<"The union of two sets are\n";
            s.Union_Intersection(i,i2,a,a1);
        }
        else if(choice==3){
            SET s;
            s.difference(i,i2,a,a1);
            cout<<"\nsymmetric difference"<<endl;
            s.symmetric(i,i2,a,a1); 
        }
        else if(choice==4)
        {
            SET s;
            s.is_subset(i,i2,arr,arr1);
        }
        //done
        else if(choice==5)
        {
			bool b;
			cout<<"enter the character to which want to check"<<endl;
			char ch;
			cin>>ch;
			b= is_member(i,ch,arr);
			if(b==0)
			{
				cout<<"The character is not in the set"<<endl;
			}
			else
			{
				cout<<"The character is present in the set"<<endl;
			}
        }
        //done
        else if(choice==6)
        {
            cout<<"the array two is universal set"<<endl;
            cout<<"COMPLIMENT"<<endl;
            SET s;
            s.difference(i,i2,a,a1); 
            
        }
        else
        {
            cout<<"INVALID CHOICE   enter correct choice"<<endl;
        }

        cout<<"\nDo you want to choose more?(y/n):"<<endl;
        cin>>choose;
    }while(choose=='y');
    return;
}
void binary(int n,int num,char arr[])
{
    int a1[num];
    int a2[num];
    while(n!=0)
    {
        for(int i=0; i<num; i++)
        {
            if(n%2==0)
            {
                a1[i]=0;
                n=n/2;
            }
            else
            {
                a1[i]=1;
                n=n/2;
            }
        }
    }
    int a=0;
    for(int i=num-1; i>=0; i--)
    {
        a2[a]=a1[i];
        if(a2[a]==1)
        {
            cout<<arr[a]<<" ";
        }
//        if(i0)
//        {
//        	cout<<",";
//		}
        a++;
    }
    return;
}
void subset(char arr[], int i)
{
    int subNo = pow(2,i);
    for(int j=0; j<subNo ; j++)
    {
        cout<<"{";
        binary(j,i,arr);
        cout<<"}";
        cout<<endl;
    }
    return ;
}
