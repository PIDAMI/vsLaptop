#include "Set.h"
using namespace std;

void Append(node** head, node** tail, string new_data) {
	node* new_elem = new node(new_data,nullptr);
	if (*head == nullptr) {
		*head = new_elem;
	}
	else {
		(*tail)->next = new_elem;
	}
	*tail = new_elem;
}

node* merge_lists(node* a, node* b, size_t& resulting_size) {
	node* res_head = nullptr;
	node* res_tail = nullptr;
	node* a_i = a;
	node* b_i = b;
	string nxt_data;
	size_t count = 0;
	node* nxt_node;
	while (a_i && b_i) {
		if (a_i->data < b_i->data) {
			nxt_data = a_i->data;
			a_i = a_i->next;
		}
		else if (a_i->data > b_i->data) {
			nxt_data = b_i->data;
			b_i = b_i->next;
		}
		else {
			nxt_data = a_i->data;
			b_i = b_i->next;
			a_i = a_i->next;
		}
		/*nxt_node = new node;
		nxt_node->next = nullptr;
		nxt_node->data = nxt_data;
		if (!res_head) {
			res_head = nxt_node;
		}
		else {
			res_tail->next = nxt_node;
		}
		res_tail = nxt_node;*/
		Append(&res_head, &res_tail, nxt_data);

		count++;
	}
	
	
	node* left_set = (a_i == nullptr ? b_i : a_i);
	while (left_set) {
		/*nxt_node = new node;
		nxt_node->next = nullptr;
		nxt_node->data = left_set->data;
		if (!res_head) {
			res_head = nxt_node;
		}
		else{
			res_tail->next = nxt_node;
		}
		res_tail = nxt_node;*/
		Append(&res_head, &res_tail, left_set->data);
		left_set = left_set->next;
		count++;
	}

	resulting_size = count;
	return res_head;
}



/*
#include "Set.h"
using namespace std;



Set Union(Set a, Set b) {
	node* res_head = nullptr;
	node* res_tail = nullptr;
	node* a_i = a.Head();
	node* b_i = b.Head();
	string nxt_data;
	size_t count = 0;
	while (a_i && b_i) {
		if (a_i->data < b_i->data) {
			nxt_data = a_i->data;
			a_i = a_i->next;
		}
		else if (a_i->data > b_i->data) {
			nxt_data = b_i->data;
			b_i = b_i->next;
		}
		else {
			nxt_data = a_i->data;
			b_i = b_i->next;
			a_i = a_i->next;
		}
		node* nxt_node = new node;
		nxt_node->next = nullptr;
		nxt_node->data = nxt_data;
		if (!res_head) {
			res_head = nxt_node;
			res_head->next = res_tail;
		}
		else if (res_tail){
			res_tail->next = nxt_node;
		}
		res_tail = nxt_node;
		count++;
		cout << nxt_data << endl;
	}

	node* left_set = (a_i == nullptr ? b_i : a_i);
	while (left_set) {
		node* nxt_node = new node;
		nxt_node->next = nullptr;
		nxt_node->data = left_set->data;
		if (!res_head) {
			res_head = nxt_node;
			res_head->next = res_tail;
		}
		else if (res_tail){
			res_tail->next = nxt_node;
		}
		res_tail = nxt_node;
		left_set = left_set->next;
		count++;
		cout << nxt_node->data;
	}
	Set result((res_head ? res_head->next : nullptr), count);
	return result;
}


Set Set::Union(const Set& b){
	node* res_head=nullptr;
	node* res_tail=nullptr;
	node* a_i = head;
	node* b_i = b.head;
	string nxt_data;
	size_t count = 0;
	while (a_i && b_i) {
		if (a_i->data < b_i->data) {
			nxt_data = a_i->data;
			a_i = a_i->next;
		}
		else if (a_i->data > b_i->data) {
			nxt_data = b_i->data;
			b_i = b_i->next;
		}
		else {
			nxt_data = a_i->data;
			b_i = b_i->next;
			a_i = a_i->next;
		}
		node* nxt_node = new node;
		nxt_node->next = nullptr;
		nxt_node->data = nxt_data;
		if (!res_head) {
			res_head = nxt_node;
		}
		else {
			res_tail->next = nxt_node;
		}
		res_tail = nxt_node;
		count++;
	}

	node* left_set = (a_i == nullptr? b_i : a_i);
	while (left_set) {
		node* nxt_node = new node;
		nxt_node->next = nullptr;
		nxt_node->data = left_set->data;
		if (!res_head) {
			res_head = nxt_node;
		}
		else {
			res_tail->next = nxt_node;
		}
		res_tail = nxt_node;
		left_set = left_set->next;
		count++;
	}


	Set result((res_head->next?res_head->next:nullptr), count);
	return result;
}

*/