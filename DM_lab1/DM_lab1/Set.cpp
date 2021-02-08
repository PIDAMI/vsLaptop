#include "Set.h"
using namespace std;



Set::Set(const string& _name) {
    size = 0;
    head = nullptr;
    name = _name;
}

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

Set::Set(vector <string> elems) {
    
    for (const auto& item : elems) {
        this->Add(item);
    }
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

int Set::Add(const string& data ) {
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
    for (size_t i = 0; i < size-1; i++) {
        cout << tmp->data << ' ';
        tmp = tmp->next;
    }
    cout << tmp->data;
}




