//typedef struct node_t{
//	int x;
//	int y;
//	struct node_t* left;
//	struct node_t* right;
//} node_t;
//node_t* init(int x, int y) {
//	node_t* new_node = (node_t*)malloc(sizeof(node_t));
//	if (!new_node)
//		return NULL;
//	new_node->x = x;
//	new_node->y = y;
//	new_node->left = NULL;
//	new_node->right = NULL;
//	return new_node;
//}
//
//
//node_t* merge(node_t* l, node_t* r) {
//	if (!l)
//		return r;
//	else if (!r)
//		return l;
//	else if (l->y > r->y) {
//		l->right = merge(l->right, r);
//		return l;
//	}
//	else {
//		r->left = merge(l, r->left);
//		return r;
//	}
//}
//
//
//
//void split(int x, node_t* root, node_t** l, node_t** r) {
//	if (!root)
//		*l = *r = NULL;
//	else if (x < root->x) {
//		split(x, root->left, l, &(root->left));
//		*r = root;
//	}
//	else {
//		split(x, root->right, &(root->right), r);
//		*l = root;
//	}
//}
//
//
//void insert_node(node_t** root, node_t* new_node) {
//	if (!(*root))
//		*root = new_node;
//	else if (new_node->y > (*root)->y) {
//		split(new_node->x, *root, &(new_node->left), &(new_node->right));
//		*root = new_node;
//	}
//	else
//		insert_node(new_node->x > (*root)->x ? &((*root)->right) : &((*root)->left), new_node);
//}
//
//void insert_val(node_t** root, int x, int y) {
//	node_t* new_node = init(x, y);
//	insert_node(root, new_node);
//}
//
//node_t* find(node_t* root, int x) {
//	if (!root)
//		return NULL;
//	else if (root->x == x)
//		return root;
//	else if (root->x < x)
//		return find(root->right, x);
//	else
//		return find(root->left, x);
//}
//
//
//
//void del(node_t** root, int x) {
//	if (x == (*root)->x) {
//		node_t* l = (*root)->left;
//		node_t* r = (*root)->right;
//		free(*root);
//		*root = merge(l, r);
//	}
//	else
//		del(x > (*root)->x ? &((*root)->right): &((*root)->left), x);
//}
//
//void free_tree(node_t** root) {
//	if (!*root)
//		return;
//	free_tree(&((*root)->left));
//	free_tree(&((*root)->right));
//	free(*root);
//}
//
//void print(node_t* root) {
//	if (!root)
//		return;
//	print(root->left);
//	printf("(%d, %d) ", root->x, root->y);
//	print(root->right);
//}
// int main(){
//node_t* root = NULL;
//char* command = (char*)malloc(MAX_INPUT_LENGTH*sizeof(char));
//int val;
//while (fgets(command, MAX_INPUT_LENGTH, stdin)) {
//	val = strtol(command + 2, NULL, 10);
//	if (command[0] == 'a')
//		insert_val(&root, val, rand());
//	else if (command[0] == 'd') {
//		del(&root, val);
//	}
//	else if (command[0] == 'f') {
//		if (!find(root, val))
//			printf("no\n");
//		else
//			printf("yes\n");
//	}
//	else if (command[0] == 'p') {
//		print(root);
//		printf("\n");
//	}
//}


//free_tree(&root);
//free(command);
//}


