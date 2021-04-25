#include "Set.h"
using namespace std;

template <typename T>
std::string Set<T>::Name() const {
    return name;
}

template std::string Set<string>::Name() const;
template std::string Set<Set<string>>::Name() const;


template <typename T>
node<T>::node(const T& data_) {
    data = data_;
    next = nullptr;
}

template node<string>::node(const string& data_);
template node<Set<string>>::node(const Set<string>& data_);

template <typename T>
node<T>::node(const T& data_, node* nxt) {
    data = data_;
    next = nxt;
}


template node<string>::node(const string& data_, node* nxt);
template node<Set<string>>::node(const Set<string>& data_, node* nxt);

std::vector<std::string> Set<std::string>::Elements() {
    std::vector<std::string> res;
    node<std::string>* tmp = head;
    while (tmp) {
        res.push_back(tmp->data);
        tmp = tmp->next;
    }
    return res;
}




template <typename T>
node<T>* Set<T>::Find(const T& data) {
    node<T>* tmp = head;
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

template node<string>* Set<string>::Find(const string& data);
template node<Set<string>>* Set<Set<string>>::Find(const Set<string>& data);



template <typename T>
Set<T>::~Set() {
    node<T>* tmp = head;
    while (head) {
        tmp = tmp->next;
        delete head;
        head = tmp;
        size--;
    }
}

template Set<string>::~Set();
template Set<Set<string>>::~Set();

template <typename T>
Set<T>::Set() {
    head = nullptr;
    size = 0;
    name = "unknown";
}

template Set<string>::Set();
template Set<Set<string>>::Set();

template <typename T>
Set<T>::Set(const std::string& n) {
    head = nullptr;
    size = 0;
    name = n;
}

template Set<string>::Set(const std::string& n);
template Set<Set<string>>::Set(const std::string& n);


template <typename T>
Set<T>::Set(node<T>* _head, size_t _size) {
    head = _head;
    size = _size;
    name = "unknown";
}

template Set<string>::Set(node<string>* _head, size_t _size);
template Set<Set<string>>::Set(node<Set<string>>* _head, size_t _size);

Set<std::string>::Set(std::vector <std::string> elems) {

    for (auto& item : elems) {
        this->Add(item);
    }
    name = "unknown";
}


void Set<std::string>::Copy(Set<std::string> dest) {
    std::vector<std::string> elems = dest.Elements();
    for (auto& elem : elems) {
        Add(elem);
    }

}




template <typename T>
T* Set<T>::FindByName(const std::string& n) {
    node<T>* set = Find({ n });
    if (!set) {
        std::string message = "No set named " + n;
        throw std::invalid_argument(message.c_str());
    }
    return &(set->data);
}

template string* Set<string>::FindByName(const std::string& n);
template Set<string>* Set<Set<string>>::FindByName(const std::string& n);


template <typename T>
size_t Set<T>::Power() const {
    return size;
}

template size_t Set<string>::Power() const;
template size_t Set<Set<string>>::Power() const;


template <typename T>
void Set<T>::ChangeName(const std::string& new_name) {
    name = new_name;
}

template void Set<string>::ChangeName(const std::string& new_name);
template void Set<Set<string>>::ChangeName(const std::string& new_name);


template <typename T>
bool Set<T>::Check(const T& data) {
    if (this->Find(data) != nullptr) {
        return true;
    }
    return false;
}

template bool Set<string>::Check(const string& data);
template bool Set<Set<string>>::Check(const Set<string>& data);



template <typename T>
int Set<T>::Add(const T& data) {
    if ((this->Check(data))) {
        return -1;
    }

    node<T>* new_node = new node<T>(data);
    int position = 1;
    node<T>* tmp = head;
    if (!size) {
        new_node->next = nullptr;
        head = new_node;
    }
    else if (head->data > data) {
        new_node->next = head;
        head = new_node;

    }

    else {
        position = 2;
        while (tmp->next != nullptr && tmp->next->data < new_node->data) {
            tmp = tmp->next;
            position++;
        }
        new_node->next = tmp->next;

        tmp->next = new_node;

    }
    size++;
    return position;
}

template int Set<string>::Add(const string& data);
template int Set<Set<string>>::Add(const Set<string>& data);

template <typename T>
int Set<T>::Del(const T& data) {
    if (!this->Check(data)) {
        return -1;
    }
    node<T>* tmp = head;
    if (tmp->data == data) {
        tmp = head->next;
        delete head;
        head = tmp;
    }
    else {
        while (tmp->next->data != data) {
            tmp = tmp->next;
        }
        node<T>* nxt_after_deleting = tmp->next->next;
        delete tmp->next;
        tmp->next = nxt_after_deleting;
    }
    size--;
    return 0;

}

template int Set<string>::Del(const string& data);
template int Set<Set<string>>::Del(const Set<string>& data);


template <typename T>
void Set<T>::Print() {
    node<T>* tmp = head;
    if (!size) {
        std::cout << "Empty set";
        return;
    }
    for (size_t i = 0; i < size - 1; i++) {
        auto elem = tmp->data;
    	if (is_whitespaces_only(elem))
            std::cout << '\"' << tmp->data << '\"' << std::endl;
        else
            std::cout << tmp->data << std::endl;
        tmp = tmp->next;
    }
    auto elem = tmp->data;
    if (is_whitespaces_only(elem))
        std::cout << '\"' << tmp->data << '\"';
    else
        std::cout << tmp->data;
}

template void Set<Set<string>>::Print();
template void Set<string>::Print();

template <typename T>
bool operator<(const Set<T>& lhs, const Set<T>& rhs) {
    return lhs.Name() < rhs.Name();
}

template bool operator<(const Set<string>& lhs, const Set<string>& rhs);
template bool operator<(const Set<Set<string>>& lhs, const Set<Set<string>>& rhs);


// for printing names of all existing sets via Print()
std::ostream& operator<<(std::ostream& stream, const Set<std::string>& s) {
    stream << s.Name();
    return stream;
}

template <typename T>
bool operator>(const Set<T>& lhs, const Set<T>& rhs) {
    return lhs.Name() > rhs.Name();
}

template bool operator>(const Set<string>& lhs, const Set<string>& rhs);
template bool operator>(const Set<Set<string>>& lhs, const Set<Set<string>>& rhs);


template <typename T>
bool operator==(const Set<T>& lhs, const Set<T>& rhs) {
    return lhs.Name() == rhs.Name();
}

template bool operator==(const Set<string>& lhs, const Set<string>& rhs);
template bool operator==(const Set<Set<string>>& lhs, const Set<Set<string>>& rhs);


template <typename T>
bool operator!=(const Set<T>& lhs, const Set<T>& rhs) {
    return lhs.Name() != rhs.Name();
}


template bool operator!=(const Set<Set<string>>& lhs, const Set<Set<string>>& rhs);
template bool operator!=(const Set<string>& lhs, const Set<string>& rhs);


Set<std::string> Set<std::string>::Union(const Set<std::string>& b) {
    size_t union_power = 0;
    node<std::string>* union_head = merge_lists(head, b.head, union_power);
    return { union_head, union_power };
}

bool Set<std::string>::Includes(const Set<std::string>& B) {
    node<std::string>* a = head;
    node<std::string>* b = B.head;
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
    //if (b == nullptr)
    //    cout << B.Name() << endl;
    //else
    //    cout << Name() << endl;
	
    return b == nullptr ? true : false;
}

Set<std::string> Set<std::string>::Intersection(const Set<std::string>& b) {
    node<std::string>* a_i = head;
    node<std::string>* b_i = b.head;
    node<std::string>* res_head = nullptr;
    node<std::string>* res_tail = nullptr;
    size_t count = 0;
    while (a_i && b_i) {
        if (a_i->data < b_i->data) {
            a_i = a_i->next;
        }
        else if (a_i->data > b_i->data) {
            b_i = b_i->next;
        }
        else {
            Append(&res_head, &res_tail, a_i->data);
            a_i = a_i->next;
            b_i = b_i->next;
            count++;
        }
    }
    return { res_head,count };
}

Set<std::string> Set<std::string>::Subtract(const Set<std::string>& b) {
    node<std::string>* a_i = head;
    node<std::string>* b_i = b.head;
    node<std::string>* res_head = nullptr;
    node<std::string>* res_tail = nullptr;
    std::string new_data;
    size_t count = 0;
    while (a_i && b_i) {
        if (b_i->data < a_i->data) {
            b_i = b_i->next;
        }
        else if (b_i->data > a_i->data) {
            Append(&res_head, &res_tail, a_i->data);
            a_i = a_i->next;
            count++;
        }
        else {
            a_i = a_i->next;
            b_i = b_i->next;
        }

    }
    if (a_i) {
        while (a_i) {
            Append(&res_head, &res_tail, a_i->data);
            a_i = a_i->next;
            count++;
        }
    }
    return { res_head,count };
}

Set<std::string> Set<std::string>::XOR(const Set<std::string>& b) {
    node<std::string>* a_i = head;
    node<std::string>* b_i = b.head;
    node<std::string>* res_head = nullptr;
    node<std::string>* res_tail = nullptr;
    std::string new_data;
    size_t count = 0;
    while (a_i && b_i) {
        if (a_i->data != b_i->data) {
            if (a_i->data < b_i->data) {
                new_data = a_i->data;
                a_i = a_i->next;
            }
            else {
                new_data = b_i->data;
                b_i = b_i->next;

            }
            Append(&res_head, &res_tail, new_data);
            count++;
        }
        else {
            b_i = b_i->next;
            a_i = a_i->next;
        }

    }
    node<std::string>* left_set = (a_i == nullptr ? b_i : a_i);
    while (left_set) {

        Append(&res_head, &res_tail, left_set->data);
        left_set = left_set->next;
        count++;
    }


    return { res_head,count };
}
