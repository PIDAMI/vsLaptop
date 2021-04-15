#include <stdio.h>
#include <stdlib.h>
#include "Treap.h"

node_t* Init(int x, int y) {
	node_t* new_node = (node_t*)malloc(sizeof(node_t));
	if (!new_node) 
		return NULL;
	new_node->x = x;
	new_node->y = y;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}
// A.x < B.x for all x in A,B
void Merge(node_t** root, node_t* l, node_t* r){
	if (!l)
		*root = r;
	else if (!r)
		*root = l;
	else if (l->y > r->y) {
		Merge(&(l->right), l->right,r);
		*root = l;
	}
	else {
		Merge(&(r->left), l, r->left);
		*root = r;
	}
}
// returns the splitted part, root doesnt change
void Split(int x, node_t* root, node_t** l, node_t** r){
	if (!root) 
		*l = *r = NULL;
	else if (root->x > x) {
		Split(x, root->left, l, &(root->left));
		*r = root;
	}
	else {
		Split(x, root->right, &(root->right), r);
		*l = root;
	}
}


void Insert_node(node_t** root, node_t* new_node) {
	if (!*root)
		*root = new_node;
	else if (new_node->y > (*root)->y) {
		Split(new_node->y, *root, &(new_node->left), &(new_node->right));
		*root = new_node;
	}
	else
		Insert_node(new_node->x > (*root)->x ? &((*root)->right): &((*root)->left), new_node);
}

void Insert_val(node_t** root, int x, int y) {
	node_t* new_node = Init(x, y);
	Insert_node(root, new_node);
}

node_t* Find(node_t* root, int x) {
	if (root->x == x)
		return root;
	else if (root->x < x)
		return Find(root->right, x);
	else
		return Find(root->left, x);
}


int main() {
	node_t* root = NULL;
	int k[] = { 3, 1, 6, 4, 9, 2, 5, 10 };
	for (int i = 0; i < 8; i++)
		Insert_val(&root, k[i], rand());

	
	return 0;
}