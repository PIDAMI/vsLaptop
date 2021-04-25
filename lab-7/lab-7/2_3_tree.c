#include "2_3_tree.h"
void swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

bool is_in(int val, node* p)
{
	for (int i = 0; i < p->size; i++)
	{
		if (p->key[i] == val)
			return true;
	}
	return false;
}

void sort_keys(node* p)
{
	if (p->size == 1) return;
	if (p->size == 2)
	{
		if (p->key[0] > p->key[1])
			swap(p->key, p->key + 1);
	}
	else
	{
		if (p->key[0] > p->key[1])
			swap(p->key, p->key + 1);
		if (p->key[0] > p->key[2])
			swap(p->key, p->key + 2);
		if (p->key[1] > p->key[2])
			swap(p->key + 1, p->key + 2);
	}
}


void insert_key(node* p, int val)
{
	p->key[p->size] = val;
	p->size++;
	sort_keys(p);
}

node* find(int x, node* root)
{
	return;
}