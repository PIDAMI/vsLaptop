//#include "Set.h"
//using namespace std;

//void Append(node<string>** head, node<string>** tail, string new_data) {
//	node<string>* new_elem = new node<string>(new_data,nullptr);
//	if (*head == nullptr) {
//		*head = new_elem;
//	}
//	else {
//		(*tail)->next = new_elem;
//	}
//	*tail = new_elem;
//}
//
//node<string>* merge_lists(node<string>* a, node<string>* b, size_t& resulting_size) {
//	node<string>* res_head = nullptr;
//	node<string>* res_tail = nullptr;
//	node<string>* a_i = a;
//	node<string>* b_i = b;
//	string nxt_data;
//	size_t count = 0;
//	while (a_i && b_i) {
//		if (a_i->data < b_i->data) {
//			nxt_data = a_i->data;
//			a_i = a_i->next;
//		}
//		else if (a_i->data > b_i->data) {
//			nxt_data = b_i->data;
//			b_i = b_i->next;
//		}
//		else {
//			nxt_data = a_i->data;
//			b_i = b_i->next;
//			a_i = a_i->next;
//		}
//
//		Append(&res_head, &res_tail, nxt_data);
//
//		count++;
//	}
//	
//	
//	node<string>* left_set = (a_i == nullptr ? b_i : a_i);
//	while (left_set) {
//
//		Append(&res_head, &res_tail, left_set->data);
//		left_set = left_set->next;
//		count++;
//	}
//
//	resulting_size = count;
//	return res_head;
//}
//
//
//Set<string> Set<string>::Union(const Set<string>& b) {
//	size_t union_power = 0;
//	node<string>* union_head = merge_lists(head, b.head, union_power);
//	return { union_head, union_power };
//}
//
//bool Set<string>::Includes(const Set<string>& B) {
//	node<string>* a = head;
//	node<string>* b = B.head;
//	while (a && b) {
//		if (b->data < a->data) {
//			return false;
//		}
//		else if (b->data > a->data) {
//			a = a->next;
//		}
//		else {
//			a = a->next;
//			b = b->next;
//		}
//
//	}
//
//	return (b == nullptr);
//}
//
//Set<string> Set<string>::Intersection(const Set<string>& b) {
//	node<string>* a_i = head;
//	node<string>* b_i = b.head;
//	node<string>* res_head = nullptr;
//	node<string>* res_tail = nullptr;
//	size_t count = 0;
//	while (a_i && b_i) {
//		if (a_i->data < b_i->data) {
//			a_i = a_i->next;
//		}
//		else if (a_i->data > b_i->data) {
//			b_i = b_i->next;
//		}
//		else {
//			Append(&res_head, &res_tail, a_i->data);
//			a_i = a_i->next;
//			b_i = b_i->next;
//			count++;
//		}
//	}
//	return { res_head,count };
//}
//
//Set<string> Set<string>::Subtract(const Set<string>& b) {
//	node<string>* a_i = head;
//	node<string>* b_i = b.head;
//	node<string>* res_head = nullptr;
//	node<string>* res_tail = nullptr;
//	string new_data;
//	size_t count = 0;
//	while (a_i && b_i) {
//		if (b_i->data < a_i->data) {
//			b_i = b_i->next;
//		}
//		else if (b_i->data > a_i->data) {
//			Append(&res_head, &res_tail, a_i->data);
//			a_i = a_i->next;
//			count++;
//		}
//		else {
//			a_i = a_i->next;
//			b_i = b_i->next;
//		}
//
//	}
//	if (a_i) {
//		while (a_i) {
//			Append(&res_head, &res_tail, a_i->data);
//			a_i = a_i->next;
//			count++;
//		}
//	}
//	return { res_head,count };
//}
//
//Set<string> Set<string>::XOR(const Set<string>& b) {
//	node<string>* a_i = head;
//	node<string>* b_i = b.head;
//	node<string>* res_head = nullptr;
//	node<string>* res_tail = nullptr;
//	string new_data;
//	size_t count = 0;
//	while (a_i && b_i) {
//		if (a_i->data != b_i->data) {
//			if (a_i->data < b_i->data) {
//				new_data = a_i->data;
//				a_i = a_i->next;
//			}
//			else {
//				new_data = b_i->data;
//				b_i = b_i->next;
//
//			}
//			Append(&res_head, &res_tail, new_data);
//			count++;
//		}
//		else {
//			b_i = b_i->next;
//			a_i = a_i->next;
//		}
//		
//	}
//	node<string>* left_set = (a_i == nullptr ? b_i : a_i);
//	while (left_set) {
//
//		Append(&res_head, &res_tail, left_set->data);
//		left_set = left_set->next;
//		count++;
//	}
//
//
//	return { res_head,count };
//}


