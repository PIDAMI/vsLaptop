//#include "Set.h"
//using namespace std;
//
//
//
//template <typename T>
//node<T>::node(const T& data_) {
//    data = data_;
//    next = nullptr;
//}
//template <typename T>
//node<T>::node(const T& data_, node* nxt) {
//    data = data_;
//    next = nxt;
//}
//
//
//
//
//template <typename T>
//node<T>* Set<T>::Find(const T& data){
//    node<T>* tmp = head;
//    if (!head || !size) {
//        return nullptr;
//    }
//    while (tmp->next && tmp->data < data) {
//        tmp = tmp->next;
//    }
//    if (tmp->data == data) {
//        return tmp;
//    }
//    return nullptr;
//}
//
//template <typename T>
//Set<T>::~Set() {
//    node<T>* tmp = head;
//    if (size) {
//        while (head) {
//            tmp = tmp->next;
//            delete head;
//            head = tmp;
//            size--;
//        }
//    }
//}
//
//template <typename T>
//Set<T>::Set() {
//    head = nullptr;
//    size = 0;
//    name = "unknown";
//}
//
//
//Set<string>::Set(const string& n) {
//    head = nullptr;
//    size = 0;
//    name = n;
//}
//
//
//Set<string>::Set(node<string>* _head, size_t _size) {
//    head = _head;
//    size = _size;
//    name = "unknown";
//}
//
//Set<string>::Set(vector <string> elems) {
//    
//    for (const auto& item : elems) {
//        this->Add(item);
//    }
//    name = "unknown";
//}
//
//
//size_t Set<string>::Power() const {
//    return size;
//}
//
//// add check for existance of sets with similiar name
//void Set<string>::ChangeName(const string& new_name) {
//    name = new_name;
//}
//
//template <typename T>
//bool Set<T>::Check(const T& data) {
//    if (this->Find(data) != nullptr) {
//        return true;
//    }
//    return false;
//
//}
//template <typename T>
//int Set<T>::Add(const T& data) {
//    if ((this->Check(data))) {
//        string message = data + " is already in the set";
//        throw invalid_argument(message.c_str());
//    }
//    node<T>* new_node = new node<T>(data);
//    int position = 1;
//    node<T>* tmp = head;
//    if (!size) {
//        new_node->next = nullptr;
//        head = new_node;
//    }   
//    else if (head->data > data) {
//        new_node->next = head;
//        head = new_node;
//     
//    }
//    else {
//        position=2;
//        while (tmp->next != nullptr && tmp->next->data <  new_node->data) {
//            tmp = tmp->next;
//            position++;
//        }
//        new_node->next = tmp->next;
//        
//        tmp->next = new_node;
//
//    }
//    size++;
//    return position;
//}
//// a b c
//template <typename T>
//int Set<T>::Del(const T& data) {
//
//    if (!this->Check(data)) {
//        string message = data + " is already in the set";
//        throw invalid_argument(message.c_str());
//    }
//    node* tmp = head;
//    if (tmp->data == data) {
//        tmp = head->next;
//        delete head;
//        head = tmp;
//     
//    }
//    else {
//        while (tmp->next->data != data) {
//            tmp = tmp->next;
//        }
//        node* nxt_after_deleting = tmp->next->next;
//        delete tmp->next;
//        tmp->next = nxt_after_deleting;
//    }
//    size--;
//    return 0;
//
//}
//
//void Set<string>::Print() {
//    node<string>* tmp = head;
//    for (size_t i = 0; i < size-1; i++) {
//        cout << tmp->data << ' ';
//        tmp = tmp->next;
//    }
//    cout << tmp->data;
//}
//
//template <typename T>
//bool operator<(const Set<T>& lhs, const Set<T>& rhs) {
//    return lhs.name < rhs.name;
//}
//
//template <typename T>
//bool operator>(const Set<T>& lhs, const Set<T>& rhs) {
//    return lhs.name > rhs.name;
//}
//
//template <typename T>
//bool operator==(const Set<T>& lhs, const Set<T>& rhs) {
//    return lhs.name == rhs.name;
//}