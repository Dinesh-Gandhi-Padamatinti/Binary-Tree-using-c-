#include<bits/stdc++.h>
#include "queue.h"
using namespace std;
class binarytree
{
	private:
		treenode *root;
	public:
		binarytree()
		{
			root=NULL;
		}
		void insert_elements()
		{
			int root_ele;
			cout<<"Enter root element:";
			cin>>root_ele;
			root=new treenode;
			root->data=root_ele;
			root->lchild=root->rchild=NULL;
			Queue q1;
			q1.enqueue(root); //pushes address of root node
			while(!q1.is_empty())
			{
				treenode *p=q1.dequeue();
				int l_ele,r_ele;
				cout<<"Enter left element of "<<p->data<<":";
				cin>>l_ele;
				cout<<"Enter right element of "<<p->data<<":";
				cin>>r_ele;
				if(l_ele!=-1)
				{
					treenode *temp= new treenode;
					temp->data=l_ele;
					temp->lchild=temp->rchild=NULL;
					q1.enqueue(temp); //pushes address of node
					p->lchild=temp;
				}
				else if(l_ele==-1)
				{
					p->lchild=NULL;
				}
				if(r_ele!=-1)
				{
					treenode *temp= new treenode;
					temp->data=r_ele;
					temp->lchild=temp->rchild=NULL;
					q1.enqueue(temp); //pushes address of node
					p->rchild=temp;
				}
				else if(r_ele==-1)
				{
					p->rchild=NULL;
				}
			}
		}
		void preorder_traversal(treenode *p)
		{
			if(p)
			{
				cout<<p->data<<" ";
				preorder_traversal(p->lchild);
				preorder_traversal(p->rchild);
			}
		}
		void inorder_traversal(treenode *p)
		{
			if(p)
			{
				inorder_traversal(p->lchild);
				cout<<p->data<<" ";
				inorder_traversal(p->rchild);
			}
		}
		void postorder_traversal(treenode *p)
		{
			if(p)
			{
				postorder_traversal(p->lchild);
				postorder_traversal(p->rchild);
				cout<<p->data<<" ";
			}
		}
		void levelorder_traversal(treenode *p)
		{
			cout<<p->data<<" ";
			Queue q2;
			q2.enqueue(p);
			while(!q2.is_empty())
			{
				p=q2.dequeue();
				if(p->lchild)
				{
					cout<<p->lchild->data<<" ";
					q2.enqueue(p->lchild);
				}
				if(p->rchild)
				{
					cout<<p->rchild->data<<" ";
					q2.enqueue(p->rchild);
				}
			}
		}
		void display()
		{
			preorder_traversal(root);
			cout<<endl;
			inorder_traversal(root);
			cout<<endl;
			postorder_traversal(root);
			cout<<endl;
			levelorder_traversal(root);
			cout<<endl;
		}
		int count(treenode *p) // gives number of nodes in the binary tree
		{
			int x,y;
			if(p)
			{
				x=count(p->lchild);
				y=count(p->rchild);
				return x+y+1;
			}
			return 0;
		}
		int count_degree_two(treenode *p) //gives number of nodes with degree=2
		{
			int x,y;
			if(p)
			{
				x=count_degree_two(p->lchild);
				y=count_degree_two(p->rchild);
				if(p->lchild && p->rchild)
					return x+y+1;
				return x+y;
			}
			return 0;
		}
		int count_leaf(treenode *p) //gives number of leaf nodes
		{
			if(p)
			{
				if(p->lchild==NULL && p->rchild==NULL)
					return count_leaf(p->lchild)+count_leaf(p->rchild)+1; //same can be written in x and y form as in count function
				return count_leaf(p->lchild)+count_leaf(p->rchild);
			}
			return 0;
		}
		int count_non_leaf(treenode *p) //gives number of non leaf nodes i.e., nodes with degree 1 and 2
		{
			if(p)
			{
				if(p->lchild || p->rchild)
					return count_non_leaf(p->lchild)+count_non_leaf(p->rchild)+1;
				return count_non_leaf(p->lchild)+count_non_leaf(p->rchild);
			}
			return 0;
		}
		int count_degree_one(treenode *p)
		{
			if(p)
			{	// ((p->lchild!=NULL && p->rchild==NULL) || (p->lchild==NULL && p->rchild!=NULL))
				if(p->lchild!=NULL ^ p->rchild!=NULL)  //here not equal to NULL should be written compulsory
					return count_degree_one(p->lchild)+count_degree_one(p->rchild)+1;
				return count_degree_one(p->lchild)+count_degree_one(p->rchild);
			}
			return 0;
		}
		int height(treenode *p)
		{
			int x,y;
			if(p)
			{
				x=height(p->lchild);
				y=height(p->rchild);
				if(x>y)
					return x+1;
				return y+1;
			}
			return 0;
		}
		void remaining_operations()
		{
			cout<<"Number of nodes="<<count(root)<<endl;
			cout<<"Number of nodes with degree two="<<count_degree_two(root)<<endl;
			cout<<"Number of nodes with degree one="<<count_degree_one(root)<<endl;
			cout<<"Number of leaf nodes="<<count_leaf(root)<<endl;
			cout<<"Number of non-leaf nodes="<<count_non_leaf(root)<<endl;
			cout<<"Height of the tree="<<height(root)-1<<endl;
			cout<<"Number of levels in the tree="<<height(root)<<endl;
		}
};

int main()
{
	binarytree b1;
	b1.insert_elements();
	b1.display();
	b1.remaining_operations();
	return 0;
}
















