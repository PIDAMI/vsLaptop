//#include <stdio.h>
//#include <stdlib.h>
////#pragma warning (disable:4996)
//
//typedef struct Node {
//	int size;
//	int key[3];
//	struct Node* first;
//	struct Node* second;
//	struct Node* third;
//	struct Node* fourth;
//	struct Node* parent;
//} Node;
//
// 
//
//Node* InitNode(int key) {
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	if (!newNode) {
//		perror("not enough memory\n");
//		return NULL;
//	}
//	newNode->size = 1;
//	newNode->key[0] = key;
//	newNode->first = NULL;
//	newNode->second = NULL;
//	newNode->third = NULL;
//	newNode->fourth = NULL;
//	newNode->parent = NULL;
//	return newNode;
//}
//
//
//int IsLeaf(Node* p) {
//	return (p->first == NULL) && (p->second == NULL) && (p->third == NULL);
//}
//
//
//
//void Sort(Node* p) {
//	int tmp;
//	if (p->size == 1)
//		return;
//	else if (p->size == 2) {
//		if (p->key[0] > p->key[1]) {
//			tmp = p->key[0];
//			p->key[0] = p->key[1];
//			p->key[1] = tmp;
//		}
//	}
//
//	else if (p->size == 3) {
//		if (p->key[0] > p->key[1]) {
//			tmp = p->key[0];
//			p->key[0] = p->key[1];
//			p->key[1] = tmp;
//		}
//		if (p->key[0] > p->key[2]) {
//			tmp = p->key[0];
//			p->key[0] = p->key[2];
//			p->key[2] = tmp;
//		}
//		if (p->key[1] > p->key[2]) {
//			tmp = p->key[1];
//			p->key[1] = p->key[2];
//			p->key[2] = tmp;
//		}
//	}
//}
//
//
//
//void InsertToNode(Node* p, int key) {
//	p->key[p->size] = key;
//	p->size++;
//	Sort(p);
//}
//
//
//
//Node* Split(Node* p) {
//
//	if (p->size < 3)
//		return p;
//
//	Node* x = InitNode(p->key[0]);
//	x->first = p->first;
//	x->second = p->second;
//	x->parent = p->parent;
//
//	Node* y = InitNode(p->key[2]);
//	y->first = p->third;
//	y->second = p->fourth;
//	y->parent = p->parent;
//
//	if (x->first) x->first->parent = x;
//	if (x->second) x->second->parent = x;
//	if (y->first) y->first->parent = y;
//	if (y->second) y->second->parent = y;
//
//	if (p->parent) {
//		InsertToNode(p->parent, p->key[1]);
//
//		if (p->parent->first == p)
//			p->parent->first = NULL;
//		else if (p->parent->second == p)
//			p->parent->second = NULL;
//		else if (p->parent->third == p)
//			p->parent->third = NULL;
//
//		if (p->parent->first == NULL) {
//			p->parent->fourth = p->parent->third;
//			p->parent->third = p->parent->second;
//			p->parent->second = y;
//			p->parent->first = x;
//		}
//		else if (p->parent->second == NULL) {
//			p->parent->fourth = p->parent->third;
//			p->parent->third = y;
//			p->parent->second = x;
//		}
//		else {
//			p->parent->fourth = y;
//			p->parent->third = x;
//		}
//
//		Node* tmp = p->parent;
//		free(p);
//		return tmp;
//	}
//	else {
//
//		x->parent = p;
//		y->parent = p;
//
//		p->key[0] = p->key[1];
//		p->first = x;
//		p->second = y;
//		p->third = NULL;
//		p->fourth = NULL;
//		p->parent = NULL;
//		p->size = 1;
//
//		return p;
//	}
//}
//
//
//
//Node* Insert(Node* root, int key) {
//
//	if (!root) 
//		return InitNode(key);
//
//	if (IsLeaf(root))
//		InsertToNode(root, key);
//	else if (key <= root->key[0])
//		Insert(root->first, key);
//	else if ((root->size == 1) || ((root->size == 2) && key <= root->key[1]))
//		Insert(root->second, key);
//	else
//		Insert(root->third, key);
//
//	return Split(root);
//}
//
//
//int LenTree(Node* p) {
//	int len = 0;
//	Node* tmp = p;
//	while (tmp) {
//		len++;
//		tmp = tmp->first;
//	}
//	//free(tmp); //???? commented, was in code initially
//	return len;
//}
//
//
//void PrintTree(Node* p, int n) {
//	if (p) {
//
//		PrintTree(p->third, n + 1);
//		for (int i = 0; i < n; i++) 
//			printf(" ");
//
//		PrintTree(p->second, n + 1);
//		for (int i = 0; i < n; i++) 
//			printf(" ");
//
//		if (p->size == 1)
//			printf("%i\n", p->key[0]);
//		else if (p->size == 2)
//			printf("%i %i\n", p->key[0], p->key[1]);
//
//		PrintTree(p->first, n + 1);
//	}
//}
//
//
//
//int Find(Node* p, int key) {
//	for (int i = 0; i < p->size; i++)
//		if (p->key[i] == key) 
//			return 1;
//	return 0;
//
//}
//
//
//
//Node* Search(Node* p, int key) {
//	if (!p)
//		return NULL;
//
//	if (Find(p, key))
//		return p;
//	else if (key < p->key[0])
//		return Search(p->first, key);
//	else if ((p->size == 2 && key < p->key[1]) || p->size == 1)
//		return Search(p->second, key);
//	else if (p->size == 2)
//		return Search(p->third, key);
//}
//
//
//
//Node* SearchMin(Node* p) {
//	if (!p)
//		return p;
//	if (!(p->first))
//		return p;
//	else 
//		return SearchMin(p->first);
//}
//
// 
//void RemoveFromNode(Node* p, int key) {
//	if (p->size >= 1 && p->key[0] == key) {
//		p->key[0] = p->key[1];
//		p->key[1] = p->key[2];
//		p->size--;
//	}
//	else if (p->size == 2 && p->key[1] == key) {
//		p->key[1] = p->key[2];
//		p->size--;
//	}
//}
//
//
//Node* Redistribute(Node* leaf) {
//	Node* parent = leaf->parent;
//	Node* first = parent->first;
//	Node* second = parent->second;
//	Node* third = parent->third;
//
//	if ((parent->size == 2) && (first->size < 2) && (second->size < 2) && (third->size < 2)) {
//
//		if (first == leaf) {
//			parent->first = parent->second;
//			parent->second = parent->third;
//			parent->third = NULL;
//			InsertToNode(parent->first, parent->key[0]);
//			parent->first->third = parent->first->second;
//			parent->first->second = parent->first->first;
//
//			if (leaf->first != NULL)
//				parent->first->first = leaf->first;
//			else if (leaf->second != NULL)
//				parent->first->first = leaf->second;
//
//			if (parent->first->first != NULL)
//				parent->first->first->parent = parent->first;
//
//			RemoveFromNode(parent, parent->key[0]);
//
//			free(first);
//
//		}
//		else if (second == leaf) {
//
//			InsertToNode(first, parent->key[0]);
//			RemoveFromNode(parent, parent->key[0]);
//
//
//			if (leaf->first != NULL)
//				first->third = leaf->first;
//			else if (leaf->second != NULL)
//				first->third = leaf->second;
//
//			if (first->third != NULL)
//				first->third->parent = first;
//
//			parent->second = parent->third;
//			parent->third = NULL;
//
//			free(second);
//
//		}
//		else if (third == leaf) {
//
//			InsertToNode(second, parent->key[1]);
//			parent->third = NULL;
//			RemoveFromNode(parent, parent->key[1]);
//
//			if (leaf->first != NULL)
//				second->third = leaf->first;
//			else if (leaf->second != NULL)
//				second->third = leaf->second;
//
//			if (second->third != NULL)
//				second->third->parent = second;
//
//			free(third);
//
//		}
//	}
//	else if ((parent->size == 2) && ((first->size == 2) || (second->size == 2) || (third->size == 2))) {
//
//		if (third == leaf) {
//
//			if (leaf->first != NULL) {
//				leaf->second = leaf->first;
//				leaf->first = NULL;
//			}
//
//			InsertToNode(leaf, parent->key[1]);
//
//			if (second->size == 2) {
//				parent->key[1] = second->key[1];
//				RemoveFromNode(second, second->key[1]);
//				leaf->first = second->third;
//				second->third = NULL;
//
//				if (leaf->first != NULL)
//					leaf->first->parent = leaf;
//
//			}
//			else if (first->size == 2) {
//
//				parent->key[1] = second->key[0];
//				leaf->first = second->second;
//				second->second = second->first;
//
//				if (leaf->first != NULL)
//					leaf->first->parent = leaf;
//
//				second->key[0] = parent->key[0];
//				parent->key[0] = first->key[1];
//				RemoveFromNode(first, first->key[1]);
//				second->first = first->third;
//
//				if (second->first != NULL)
//					second->first->parent = second;
//
//				first->third = NULL;
//
//			}
//		}
//		else if (second == leaf) {
//
//			if (third->size == 2) {
//
//				if (leaf->first == NULL) {
//					leaf->first = leaf->second;
//					leaf->second = NULL;
//				}
//
//				InsertToNode(second, parent->key[1]);
//				parent->key[1] = third->key[0];
//				RemoveFromNode(third, third->key[0]);
//
//				second->second = third->first;
//
//				if (second->second != NULL)
//					second->second->parent = second;
//
//				third->first = third->second;
//				third->second = third->third;
//				third->third = NULL;
//			}
//			else if (first->size == 2) {
//
//				if (leaf->second == NULL) {
//					leaf->second = leaf->first;
//					leaf->first = NULL;
//				}
//
//				InsertToNode(second, parent->key[0]);
//				parent->key[0] = first->key[1];
//				RemoveFromNode(first, first->key[1]);
//
//				second->first = first->third;
//				if (second->first != NULL)
//					second->first->parent = second;
//				first->third = NULL;
//
//			}
//		}
//		else if (first == leaf) {
//
//			if (leaf->first == NULL) {
//				leaf->first = leaf->second;
//				leaf->second = NULL;
//			}
//
//			InsertToNode(first, parent->key[0]);
//
//			if (second->size == 2) {
//				parent->key[0] = second->key[0];
//				RemoveFromNode(second, second->key[0]);
//
//				first->second = second->first;
//
//				if (first->second != NULL)
//					first->second->parent = first;
//
//				second->first = second->second;
//				second->second = second->third;
//				second->third = NULL;
//
//			}
//			else if (third->size == 2) {
//				parent->key[0] = second->key[0];
//				second->key[0] = parent->key[1];
//				parent->key[1] = third->key[0];
//				RemoveFromNode(third, third->key[0]);
//				first->second = second->first;
//
//				if (first->second != NULL)
//					first->second->parent = first;
//
//				second->first = second->second;
//				second->second = third->first;
//
//				if (second->second != NULL)
//					second->second->parent = second;
//
//				third->first = third->second;
//				third->second = third->third;
//				third->third = NULL;
//
//			}
//
//		}
//
//	}
//	else if (parent->size == 1) {
//
//		InsertToNode(leaf, parent->key[0]);
//
//		if (first == leaf && second->size == 2) {
//			parent->key[0] = second->key[0];
//			RemoveFromNode(second, second->key[0]);
//
//			if (leaf->first == NULL)
//				leaf->first = leaf->second;
//
//			leaf->second = second->first;
//			second->first = second->second;
//			second->second = second->third;
//			second->third = NULL;
//
//			if (leaf->second != NULL)
//				leaf->second->parent = leaf;
//
//		}
//		else if (second == leaf && first->size == 2) {
//			parent->key[0] = first->key[1];
//			RemoveFromNode(first, first->key[1]);
//
//			if (leaf->second == NULL)
//				leaf->second = leaf->first;
//
//			leaf->first = first->third;
//			first->third = NULL;
//
//			if (leaf->first != NULL)
//				leaf->first->parent = leaf;
//		}
//
//	}
//
//	return parent;
//}
//
//
//
//// Ñêëåèâàíèå
//Node* Merge(Node* leaf) {
//
//	Node* tmp = NULL;
//	Node* parent = leaf->parent;
//
//	if (parent->first == leaf) {
//		InsertToNode(parent->second, parent->key[0]);
//		parent->second->third = parent->second->second;
//		parent->second->second = parent->second->first;
//
//		if (leaf->first != NULL)
//			parent->second->first = leaf->first;
//		else if (leaf->second != NULL)
//			parent->second->first = leaf->second;
//
//		if (parent->second->first != NULL)
//			parent->second->first->parent = parent->second;
//
//		RemoveFromNode(parent, parent->key[0]);
//
//		free(parent->first);
//		parent->first = NULL;
//
//	}
//	else if (parent->second == leaf) {
//		InsertToNode(parent->first, parent->key[0]);
//
//		if (leaf->first != NULL)
//			parent->first->third = leaf->first;
//		else if (leaf->second != NULL)
//			parent->first->third = leaf->second;
//
//		if (parent->first->third != NULL)
//			parent->first->third->parent = parent->first;
//
//		RemoveFromNode(parent, parent->key[0]);
//
//		free(parent->second);
//		parent->second = NULL;
//	}
//
//	if (parent->parent == NULL) {
//
//		if (parent->first != NULL)
//			tmp = parent->first;
//		else tmp = parent->second;
//
//		tmp->parent = NULL;
//		free(parent);
//		return tmp;
//	}
//
//	return parent;
//}
//
//
//
//// Èñïðàâëåíèå äåðåâà ïîñëå óäàëåíèÿ
//Node* Fix(Node* leaf) {
//
//	Node* parent = leaf->parent;
//
//	if (leaf->size == 0 && leaf->parent == NULL) {
//		free(leaf);
//		return NULL;
//	}
//
//	if (leaf->size != 0) {
//		if (leaf->parent)
//			return Fix(leaf->parent);
//		else return leaf;
//	}
//
//	if (parent->first->size == 2 || parent->second->size == 2 || parent->size == 2)
//		leaf = Redistribute(leaf);
//	else if (parent->size == 2 && parent->third->size == 2)
//		leaf = Redistribute(leaf);
//	else leaf = Merge(leaf);
//
//
//	return Fix(leaf);
//}
//
//
//
//Node* Remove(Node* p, int key) {
//
//	Node* item = Search(p, key);
//
//	Node* min = NULL;
//	int z = 0;
//
//	if (!item) return NULL;
//
//	if (item->key[0] == key)
//		min = SearchMin(item->second);
//	else
//		min = SearchMin(item->third);
//
//	if (min) {
//
//		if (key == item->key[0]) {
//			z = item->key[0];
//			item->key[0] = min->key[0];
//			min->key[0] = z;
//		}
//		else {
//			z = item->key[1];
//			item->key[1] = min->key[0];
//			min->key[0] = z;
//		}
//
//		item = min;
//	}
//
//	RemoveFromNode(item, key);
//
//	return Fix(item);
//}