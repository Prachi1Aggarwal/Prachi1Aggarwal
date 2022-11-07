#include<iostream>
using namespace std;
int height = 0;
class Node{
	public:
	int data;
	Node *left;
	Node *right;
};
class Queue
{
	private:
		Node *front;
		Node *rear;
	public:
		Queue()
		{
			front=NULL;
			rear=NULL;
		}
		void enqueue(int item)
		{
			if(front==NULL)
			{
				front=new Node;
				front->data=item;
				front->right= NULL;
				front->left=NULL;
				rear=front;
			}
			else{
				Node *q = new Node;
				q->data=item;
				q->left=rear;
				rear->right=q;
				q->right=NULL;
				rear=q;
			}
		}
		Node* first(){
			return front;
		}
		bool isEmpty()
		{
			if(front==NULL && rear==NULL)
			{
				return 1;
			}
			else{
				return 0;
			}
		}
		void dequeue()
		{
			if(isEmpty()){
				cout<<"empty"<<endl;
			}
			else{
				if(front==rear)
				{
					Node *q=front;
					front=NULL;
					rear=NULL;
					delete q;
				}
				else{
					Node *q=front;
					Node *r;
					r=q->right;
					delete q;
					front=r;
				}
			}
		}	
};
class BST{
	private:
		Node *root;
	public:
		BST()
		{
			root=NULL;
		}
		void create_node(int ele)
		{
			if(root==NULL)
			{
				root = new Node;
				root->data=ele;
				root->left=NULL;
				root->right=NULL;
			}
			else
			{
				Node *r = new Node;
				r->data=ele;
				r->left=NULL;
				r->right=NULL;
				Node *p = root;
				Node *q = NULL;
				while(p!=NULL)
				{
					if(ele<p->data)
					{
						q=p;
						p= p->left;
					}
					else
					{
						q=p;
						p=p->right;
					}
				}
				if(ele<q->data)
				{
					q->left=r;
				}
				else{
					q->right=r;
				}
			}
		}
		void visit(Node *n)
		{
			cout<<n->data<<" ";
		}
		void inorder(Node *n)
		{
			if(n!=NULL)
			{
				inorder(n->left);
				visit(n);
				inorder(n->right);
			}
		}
		void postorder(Node *n)
		{
			if(n!=NULL)
			{
				postorder(n->left);
				postorder(n->right);
				visit(n);
			}
		}
		void preorder(Node *n)
		{
			if(n!=NULL)
			{
				visit(n);
				preorder(n->left);
				preorder(n->right);
			}
		}
		void breath_first()
		{
			Queue q;
			q.enqueue(root->data);
			while(!q.isEmpty()){
				Node *f = q.first();
				Node *p = root;
				while(p->data!=f->data)
				{
					if(f->data==p->data)
					{
						p=p;
					}
					else if(f->data<p->data){
						p=p->left;
					}
					else{
						p=p->right;
					}
				
				}
				visit(f);
				q.dequeue();
				if(p->left!=NULL || p->right!=NULL)
				{
					height++;
				}
				if(p->left!=NULL){
					q.enqueue(p->left->data); 
				} 
				if(p->right!=NULL){
					q.enqueue(p->right->data); 
				}
			} 
		}
		void traverse()
		{
				int choice;
				cout<<"Enter:\n1)Preorder\n2)Postorder\n3)Inorder\n4)BreathFirst\n";
				cin>>choice;
				switch(choice)
				{
					case 1:
						preorder(root);
						break;
					case 2:
						postorder(root);
						break;
					case 3:
						inorder(root);
						break;
					case 4:
						breath_first();
						break;
					default:
						cout<<"Wrong choice"<<endl;
						break;
				}
		}

		Node *predecessor(Node *n)
		{
			n = n->left;
			while(n->right!=NULL)
			{
				n=n->right;
			}
			return n;
		}
		Node *successor(Node *n)
		{
			n=n->right;
			while(n->left!=NULL)
			{
				n = n->left;
			}
			return n;
		}
		void delete_merging(Node *node, Node *prev=NULL)
		{
			Node *a=node;
			Node *p = node;
			Node *q;
			if(node!=NULL)
			{
				if(node->left==NULL && node->right==NULL)
				{
					if(prev->left==node){
						prev->left=NULL;
					}
					else{
						prev->right=NULL;
					}
					delete p;
				}
				else if(node==root)
				{
					q=predecessor(p);
					q->right=node->right;
					root= node->left;
					delete node;
				}
				else if(node->right==NULL)
				{
					if(node==prev->left){
						node=node->left;
						prev->left=node;
					}
					else{
						node=node->left;
						prev->right=node;
					}
					delete p;
				}
				else if(node->left==NULL){
					if(node==prev->left){
						node=node->right;
						prev->left=node;
					}
					else{
						node=node->right;
						prev->right=node;
					}
					delete p;
				}
				else{
					q=predecessor(p);
					p=p->left;
					
					q->right=node->right;
					q=node;
					node= node->left;
					if(prev->data<p->data){
						prev->right=p;
					}
					else{
						prev->left=p;
					}
					delete q;
				}
			
			}
			
		}
		void delete_copying(Node *node,Node *previous=NULL)
		{
			Node *p = node;
			Node *prev = node;
			if(node->left==NULL && node->right==NULL)
			{
				if(prev->left==node){
					prev->left=NULL;
				}
				else{
					prev->right=NULL;
				}
				delete p;
			}
			else if(node->right==NULL)
			{
				if(node==prev->left){
					node=node->left;
					prev->left=node;
				}
				else{
					node=node->left;
					prev->right=node;
				}
				delete p;
			}
			else if(node->left==NULL){
				if(node==prev->left){
					node=node->right;
					prev->left=node;
				}
				else{
					node=node->right;
					prev->right=node;
				}
				delete p;
			}
			else
			{
				p= node->left;
				prev=node;
				while(p->right!=NULL)
				{
					prev=p;
					p=p->right;
				}
				node->data=p->data;
				if(prev==node)
				{
					prev->left=p->left;
				}
				else{
					prev->right=p->left;
				}
			}
//			p=node;
			delete p;
		}
		void deletion(int ele)
		{
			Node *p = root;
			Node *q = NULL;
			while(p!=NULL)
			{
				if(p->data==ele)
				{
					break;
				}
				q=p;
				if(ele<p->data){
//					q=p;
					p=p->left;
				}
				else
				{
//					q=p;
					p=p->right;
				}
			}
			if(p!=NULL && p->data==ele)
			{
				int choose;
				cout<<"choose:\n1)Delete by Merging\n2)Delete by Copying\n";
				cin>>choose;
				if(choose==1)
				{
					if(p==root)
					{       
						delete_merging(root);
					}
					else if(q->left==p)
					{
						delete_merging(q->left,q);
					}
					else{
						delete_merging(q->right,q);
					}
				}
				else{
					if(p==root)
					{       
						delete_copying(root);
					}
					else if(q->left==p)
					{
						delete_copying(q->left,q);
					}
					else{
						delete_copying(q->right,q);
					}
				}
				
				
			}
			else if(root!=NULL)
			{
				cout<<"Element not found"<<endl;
			}
			else{
				
				cout<<"Emplty BST"<<endl;
			}
			
			
		}
		int search(Node *p, int ele){
			while(p!=NULL)
			{
				if(ele==p->data)
				{
					return p->data;
				}
				else if(ele<p->data){
					p=p->left;
				}
				else{
					p=p->right;
				}
				
			}
			return 0;
		}
		void searching(int ele,int y)
		{
			int found;
			found=  search(root,ele);
			deletion(found);
			create_node(y);
			return;
		}
};
int main()
{
	BST bst;
	int choose; 
	char ch;
	int item;
	do{
		cout<<"Enter your choice:\n1)Create Tree Node\n2)Traverse Tree\n3)Delete Node\n4)Search node and set y node in bst\n5)Height of tree\n";
		cin>>choose;
		switch(choose)
		{
			case 1:
				do{
					cout<<"Enter the value "<<endl;
					cin>>item;
					bst.create_node(item); 
					cout<<"Do you want to create more(y/n)?\n";
					cin>>ch;
				}while(ch=='y');
				break;
			case 2:
				bst.traverse() ;
				break;
			case 3:
				cout<<"Enter the item want to delete"<<endl;
				cin>>item;
				bst.deletion(item);
				break;
			case 4:
				cout<<"Enter the item want to search"<<endl;
				cin>>item;
				int y;
				cout<<"Enter the item want to insert"<<endl;
				cin>>y;
				bst.searching(item,y);
				break;
			case 5:
				cout<<"The tree is:"<<endl;
				bst.breath_first() ;
				cout<<"\nHeight of the tree is: "<<height<<endl;
				break;
			default:
				cout<<"Wrong choice"<<endl;
				break; 
		}
		cout<<"\nDo you wanna choose More(y/n)?"<<endl;
		cin>>ch;
	}while(ch=='y');
	return 0; 
}
