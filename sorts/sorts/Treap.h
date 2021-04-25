#pragma once

typedef struct {
	int x;
	int y;
	node_t* left;
	node_t* right;
} node_t;


node_t* Init(int x, int y);
void Merge(node_t** root, node_t* l, node_t* r);
void Split(int x, node_t* root, node_t** l, node_t** r);
