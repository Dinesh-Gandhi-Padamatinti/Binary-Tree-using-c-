using namespace std;
class treenode
{
	public:
		int data;
		treenode *lchild;
		treenode *rchild;
};

class queuenode
{
	public:
		treenode *data;
		queuenode *next;
};

class Queue
{
	private:
		queuenode *front;
		queuenode *rear;
	public:
		Queue()
		{
			front=rear=NULL;
		}
		~Queue()
		{
			queuenode *p=front;
			while(p)
			{
				front =front->next;
				delete p;
				p=front;
			}
			rear=NULL;
		}
		void enqueue(treenode *ele)
		{
			queuenode *t=new queuenode;
			if(t==NULL)
			{
				cout<<"Queue is full"<<endl;
				return;
			}
			t->data=ele;
			t->next=NULL;
			if(front==NULL)
			{
				front=t;
				rear=t;
				return;
			}
			rear->next=t;
			rear=rear->next;
			return;
		}
		treenode * dequeue()
		{
			if(front!=NULL)
			{
				queuenode *p=front;
				treenode *temp=front->data;
				front=front->next;
				delete p;
				return temp;
			}
		}
		int is_empty()
		{
			if(front==NULL)
				return 1;
			return 0;
		}
};





