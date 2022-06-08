#include <bits/stdc++.h>
using namespace std;
struct nodes 
{
	int n;
	struct nodes *l_child, *r_child;
};
nodes* n_nodes(int v)
{
	nodes* t_ptr = new nodes;
	t_ptr->n = v;
    t_ptr->l_child = t_ptr->r_child = NULL;
	return t_ptr;
}
void INorder(nodes* Root)
{
	if (Root != NULL)
    {
		INorder(Root->l_child);
		cout<<Root->n<<" ";
		INorder(Root->r_child);
	}
}
nodes* Insertion(nodes* p, int n)
{
	if (p == NULL)
		return n_nodes(n);
	if (n < p->n)
		p->l_child = Insertion(p->l_child, n);
	else
		p->r_child = Insertion(p->r_child, n);
	return p;
}
nodes* Deletion(nodes* Root, int v)
{
	if (Root == NULL)
		return Root;
	if (Root->n > v)
    {
		Root->l_child = Deletion(Root->l_child, v);
		return Root;
	}
	else if (Root->n < v)
    {
		Root->r_child = Deletion(Root->r_child, v);
		return Root;
	}
	if (Root->l_child == NULL)
	{
		nodes* t_ptr = Root->r_child;
		delete Root;
		return t_ptr;
	}
	else if (Root->r_child == NULL)
	{
	    nodes* t_ptr = Root->l_child;
		delete Root;
		return t_ptr;
	}
	else
	{
        nodes* succ = Root;
		nodes* suc = Root->r_child;
		while (succ->l_child != NULL)
        {
			succ = suc;
			suc = suc->l_child;
		}
		if (succ != Root)
			succ->l_child = suc->r_child;
		else
			succ->r_child = suc->r_child;
		Root->n = suc->n;
		delete suc;
		return Root;
	}
}
bool Searching(nodes* Root, int x)
{
	if(Root == NULL)
	{
		return false;
	}
	else if(Root->n == x)
	{
		return true;
	}
	else if(x<= Root->n)
	{
		return Searching(Root->l_child, x);
	}
	else
	{
		return Searching(Root->r_child, x);
	}
}
int main()
{
	nodes* Root = NULL;
	Root = Insertion(Root, 20);
	Root = Insertion(Root, 10);
	Root = Insertion(Root, 15);
	Root = Insertion(Root, 34);
	Root = Insertion(Root, 12);
	Root = Insertion(Root, 14);
	Root = Insertion(Root, 40);
	Root = Insertion(Root, 50);
      
	printf("\n Inorder:\n");
	INorder(Root);
       if(Searching(Root,20) == true)
	cout<<"\n The element is found: "<<20<<"\n";
	else
	cout<<"\n The element is not found: "<<20<<"\n";
	
	printf("Delete 12");
        Root = Deletion(Root, 12);
	printf("\n Inorder:\n");
	INorder(Root);
	return 0;
}
