#include<iostream>
#include<queue>
using namespace std;


typedef struct node
{
	char data;
	struct node* lchild;
	struct node* rchild;
}node;

queue<node*>q;

void create(node*& p)
{
	char ch;
	cin >> ch;
	if (ch == '0')
		p = NULL;
	else
	{
		p = new node;
		p->data = ch;
		create(p->lchild);
		create(p->rchild);
	}
}

void levelorder(node*& p)
{
	if (!p)
		return;
	q.push(p);
	while (!q.empty())
	{
		node* pa;
		pa = q.front();
		cout << pa->data;
		q.pop();
		if (pa->lchild)
			q.push(pa->lchild);
		if (pa->rchild)
			q.push(pa->rchild);
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		node* p;
		create(p);
		levelorder(p);
	}
	return 0;
}