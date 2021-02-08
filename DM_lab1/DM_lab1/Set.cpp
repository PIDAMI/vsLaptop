#include "Set.h"
using namespace std;

node::node() {
    data = "";
    next = nullptr;
}
node::node(const string& str) {
    data = str;
    next = nullptr;
}
node::node(const string& str, node* nxt) {
    data = str;
    next = nxt;
}

node* Set::Head() {
    return head;
}

node* Set::Find(const string& data){
    node * tmp = head;
    if (!head || !size) {
        return nullptr;
    }
    while (tmp->next && tmp->data < data) {
        tmp = tmp->next;
    }
    if (tmp->data == data) {
        return tmp;
    }
    return nullptr;
}

Set::~Set() {
    node* tmp = head;
    if (size) {
        while (head) {
            tmp = tmp->next;
            delete head;
            head = tmp;
            size--;
        }
    }
}

Set::Set() {
    head = nullptr;
    size = 0;
}

Set::Set(node* _head, size_t _size) {
    head = _head;
    size = _size;
}


size_t Set::Power() const {
    return size;
}



bool Set::Check(const string& data) {
    if (this->Find(data) != nullptr) {
        return true;
    }
    return false;

}
// a b w
int Set::Add(const string& data) {
    if ((this->Check(data))) {
        string message = data + " is already in the set";
        throw invalid_argument(message.c_str());
    }
    node* new_node = new node(data);
    int position = 1;
    node* tmp = head;
    if (!size) {
        new_node->next = nullptr;
        head = new_node;
    }   
    else if (head->data > data) {
        new_node->next = head;
        head = new_node;
     
    }
    else {
        position=2;
        while (tmp->next != nullptr && tmp->next->data <  new_node->data) {
            tmp = tmp->next;
            position++;
        }
        new_node->next = tmp->next;
        
        tmp->next = new_node;

    }
    size++;
    return position;
}
// a b c
int Set::Del(const string& data) {

    if (!this->Check(data)) {
        string message = data + " is already in the set";
        throw invalid_argument(message.c_str());
    }
    node* tmp = head;
    if (tmp->data == data) {
        tmp = head->next;
        delete head;
        head = tmp;
     
    }
    else {
        while (tmp->next->data != data) {
            tmp = tmp->next;
        }
        node* nxt_after_deleting = tmp->next->next;
        delete tmp->next;
        tmp->next = nxt_after_deleting;
    }
    size--;
    return 0;

}

void Set::Print() {
    node* tmp = head;
    for (size_t i = 0; i < size; i++) {
        cout << tmp->data << ' ';
        tmp = tmp->next;
    }
}

Set Set::Union(const Set& b) {
    size_t union_power = 0;
    node* union_head = merge_lists(head, b.head, union_power);
    return { union_head, union_power };
}

bool Set::Includes(const Set& B) {
    node* a = head;
    node* b = B.head;
    while (a && b) {
        if (b->data < a->data) {
            return false;
        }
        else if (b->data > a->data) {
            a = a->next;
        }
        else {
            a = a->next;
            b = b->next;
        }

    }
   
    return (b==nullptr);
}

Set Set::Intersection(const Set& b) {
    node* a_i = head;
    node* b_i = b.head;
    node* res_head = nullptr;
    node* res_tail = nullptr;
    while (a_i && b_i) {
        if (a_i->data < b_i->data) {
            a_i = a_i->next;
        }


    }
    return {};

}

