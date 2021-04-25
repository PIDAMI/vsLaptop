#pragma once

#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
	struct node* first;
	struct node* second;
	struct node* third;
	struct node* fourth;
	struct node* parent;
	int size;
	int key[3];
} node;


bool is_in(int val, node* p);
void sort_keys(node* p);
void swap(int* x, int* y);

node* init();
node* find(int val, node* root);
