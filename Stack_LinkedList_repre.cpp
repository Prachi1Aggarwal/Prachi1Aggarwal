#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};
class Stack{
    private:
    Node *top;
    public:
    Stack(){
        top=NULL;
    }
    void push(int item){
        Node *p;
        p= new Node;
        p->data=item;
        p->next=top;
        top=p;
    }
    int pop(){
        Node *p = top;
        if(p==NULL)
        {
            cout<<"Underflow ERROR"<<endl;
            return -1;
        }
        else{
            cout<<(top->data)<<endl;
            p=top;
            top=top->next;
            delete p;
            
        }
    }
};
int main(){
    Stack s;
    int choice; 
    char ch;
    do{
        cout<<"Enter your choice\n1)Push\n2)Pop\n";
        cin>>choice;
        switch (choice)
        {
        case 1:
            int item;
            cout<<"Enter the element want to push"<<endl;
            cin>>item;
            s.push(item);
            break;
        case 2:
            int ele;
            ele=s.pop();
            cout<<"Poped element is: "<<ele<<endl;
            break;
        default:
            cout<<"Wrong choice CHOOSE AGAIN"<<endl;
            break;
        }
        cout<<"\nDo you want to choose more(y/n)?"<<endl;
        cin>>ch;
    }while(ch=='y');
    return 0;
}
