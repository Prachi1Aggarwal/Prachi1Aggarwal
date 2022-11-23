#include<iostream>
#include<string>
using namespace std;
template<class T>
class Sorting
{
	private:
		T *array;
		int size;	
	public:
		
		Sorting(int s){
			size = s;
			array = new T[size];
		}
		void input()
		{
			cout<<"Enter the elements of the array in insorted manner"<<endl;
			for(int i=0; i<size; i++)
			{
				cin>>array[i];
			}
		}
		void bubble(){
			T hold;
			for(int i=0; i<size; i++)
 			{
 				for(int j=0; j<size-i-1; j++) 
  				{
  					if(array[j]>array[j+1])
  					{
    					hold=array[j];
   				        array[j]=array[j+1];
    					array[j+1]=hold;
   					}
  				}
 			}
 			cout<<"\nAfter sorting\n"<<endl;
 			for(int a=0; a<size; a++)
 			{
 				cout<<array[a]<<" ";
			}
		}
		void insertion(){
			int i, j;
			T key;
    		for (i = 1; i < size; i++)
    		{
       			key = array[i];
        		j = i - 1;
       			while (j >= 0 && array[j] > key)
        		{
            		array[j + 1] = array[j];
            		j = j - 1;
        		}
        		array[j + 1] = key;
    		}
    		cout<<"\nAfter sorting\n"<<endl;
    		for(int a=0; a<size; a++)
 			{
 				cout<<array[a]<<" ";
			}
		}
		void selection()
		{
			int i,j,min_in;
    		for(i=0;i<size;i++)
    		{
        		min_in = i;
        		for(j=i+1;j<size;j++)
            	{
            		if (array[j] < array[min_in])
                	{
                		min_in = j;
					}
				}
				T hold = array[i];
				array[i]=array[min_in];
				array[min_in]=hold;
    		}
    		cout<<"\nAfter sorting\n"<<endl;
    		for(int a=0; a<size; a++)
 			{
 				cout<<array[a]<<" ";
			}
		}
};
int main()
{
	cout<<"Enter the size of the array"<<endl;
	int size;
	cin>>size;
	cout<<"Enter the data type of the elements of the array along with type of sorting \n1)int\n2)float\n3)char\n4)string\n\n0 for bubble sort\n 9 for insertion sort\n 8 for selection sort\n";
	int choose,sort;
	cin>>choose;
	cin>>sort;
	if(choose==1)
	{
		Sorting<int> s(size);
		s.input();
		if(sort==0){
			s.bubble() ;
		}
		else if(sort==9){
			s.insertion();
		}
		else{
			s.selection() ;
		}
	}
	else if(choose==2){
		Sorting<float> s(size);
		s.input();
		if(sort==0){
			s.bubble() ;
		}
		else if(sort==9){
			s.insertion();
		}
		else{
			s.selection() ;
		}
	}
	else if(choose==3){
		Sorting<char> s(size);
		s.input();
		if(sort==0){
			s.bubble() ;
		}
		else if(sort==9){
			s.insertion();
		}
		else{
			s.selection() ;
		}
	}
	else if(choose==4){
		Sorting<string> s(size);
		s.input();
		if(sort==0){
			s.bubble() ;
		}
		else if(sort==9){
			s.insertion();
		}
		else{
			s.selection() ;
		}
	}
}
