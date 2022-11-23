#include <iostream>
using namespace std;
int main()
{
        int x, y;
        char ch;
        int choice;
        cout << "Enter the value of x and y" << endl;
        cin >> x >> y;
        do
        {
                cout << "Enter the choice\n1)Conjunction\n2)Disjunction\n3)Exclusive OR\n4)Conditioinal\n5)Bi-Conditional\n6)Exclusive NOR\n7)Negation\n8)NAND\n9)NOR\n"
                     << endl;
                cin >> choice;
                switch (choice)
                {
                case 1:
                        cout << "Conjuction of x and y is: " << (x & y) << endl;
                        break;
                case 2:
                        cout << "Disjuction of x and y is: " << (x | y) << endl;
                        break;
                case 3:
                        cout << "Exclusive OR of x and y is: " << (x ^ y) << endl;
                        break;
                case 4:
                        if (x == 1 && y == 0)
                        {
                                cout << "Coniditional of x and y is: " << 0 << endl;
                        }
                        else
                        {
                                cout << "Coniditional of x and y is: " << 1 << endl;
                        }
                        break;
                case 5:
                        if ((x == 1 && y == 1) || (x == 0 && y == 0))
                        {
                                cout << "BiConiditional of x and y is: " << 1 << endl;
                        }
                        else
                        {
                                cout << "BiConiditional of x and y is: " << 0 << endl;
                        }
                        break;
                case 6:
                        cout << "Exclusive NOR of x and y is: " << !(x ^ y) << endl;
                        break;
                case 7: cout<<"negation of x is: "<<!x<<endl;
                        cout<<"negation of y is: "<<!y<<endl;
                        break;
                case 8: if(x==1&&y==1)
                        {
                                cout<<"Nand of x and y is: "<<0<<endl;
                        }else{
                                cout<<"Nand of x and y is: "<<1<<endl;
                        }
                        break;
                case 9: if(x==0&&y==0)
                        {
                                cout<<"Nor of x and y is: "<<1<<endl;
                        }else{
                        	
                                cout<<"Nor of x and y is: "<<0<<endl;
                        }
                }
                cout<<"Do you want to choose more: (y/n)"<<endl;
                cin>>ch;
        }while(ch=='y');
        return 0;
}
