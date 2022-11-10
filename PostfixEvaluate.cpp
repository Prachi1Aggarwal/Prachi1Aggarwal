#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class Stack{
	int size;
	public:
		int top;
		char *arr;
		Stack(int s){
			size=s;
			top=-1;
			arr=new char[size];	
		}
		void push(char ele){
			if(top==size-1){
				cout<<"OverFlow ERROR!!!"<<endl;
				return;
			}
			else{
				top++;
				arr[top]=ele;
			}
		}
		int pop(){
			if(top==-1){
				cout<<"UnderFlow ERROR!!"<<endl;
				exit(0);
			}
			else{
				char x = arr[top];
				top--;
				return x;
			}
		}
};
class Postfix{
	string expression;
	public:
		Postfix(string s){
			expression = s;
		}
		float evaluate(){
			Stack s(20);
			float sum;
			for(int i=0; i<expression.length(); i++){
				if((expression[i]>='0')&&(expression[i]<='9')){
					s.push(expression[i]);
				}
				else if((expression[i]=='+')||(expression[i]=='-')||(expression[i]=='*')||(expression[i]=='/')){
					float n1,n2;
					n1=(float)(s.pop()-48);
					n2=(float)(s.pop()-48);
					if(expression[i]=='+'){
						sum = n1+n2;
						s.push((char)(sum+48));
					}
					else if(expression[i]=='-'){
						sum = n2-n1;
						s.push((char)(sum+48));
					}
					else if(expression[i]=='*'){
						sum = n1*n2;;
						s.push((char)(sum+48));
					}
					else if(expression[i]=='/'){
						sum = n2/n1;
						s.push((char)(sum+48));
					}
				}
				
			}
			float final = sum;
			cout<<"After evaluation= "<<final<<endl;
		}
};
int main(){
	string str;
	cout<<"Enter postfix expression"<<endl;
	cin>>str;
	Postfix p(str);
	p.evaluate();
	return 0;
}
