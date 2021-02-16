#pragma once
#ifndef SET
#define SET
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <type_traits>
#include <string>
#include <sstream>
#include <vector>

template <typename T>
struct node {
    T data;
    node* next;
    node(const T& data);
    node(const T& data, node* next);
};




node<std::string>* merge_lists(node<std::string>* a, node<std::string>* b, size_t& resulting_size);
void Append(node<std::string>** head, node<std::string>** tail, std::string new_data);

// check for russian letters
template <typename T>
class Set
{
private:    
    std::string name;
    size_t size;
    node<T>* head;
    node<T>* Find(const T& data);
public:
    
    Set();
    Set(const std::string& n);
    Set(node<T>* _head, size_t _size);
    Set(std::vector <std::string> elems);
    ~Set();
    void ChangeName(const std::string& new_name);
    size_t Power() const ;
    std::string Name() const;
    T* FindByName(const std::string& n);//exceptions
    bool Check(const T& data);
    int Add(const T& data);//exceptions
    int Del(const T& data);//exceptions
    Set Union(const Set& b);
    bool Includes(const Set& b);
    Set Intersection(const Set& b);
    Set Subtract(const Set& b);
    Set XOR(const Set& b);
    void Print();
};



using namespace std;

string Set<string>::Name() const{
    return name;
}


template <typename T>
node<T>::node(const T& data_) {
    data = data_;
    next = nullptr;
}
template <typename T>
node<T>::node(const T& data_, node* nxt) {
    data = data_;
    next = nxt;
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

template <typename T>
Set<T>::~Set() {
    node<T>* tmp = head;
    while (head) {
        tmp = tmp->next;
        delete head;           
        head = tmp;
        size--;
    }
    cout << name << endl;
}

//Set<std::string>::~Set() {
//    node<std::string>* tmp = head;
//    cout << name << endl;
//    if (size) {
//        while (head) {
//            tmp = tmp->next;
//            if (head->data.size())
//                delete head;
//            head = tmp;
//            size--;
//        }
//    }
//}
//
//Set<Set<string>>::~Set() {
//    node<Set<string>>* tmp = head;
//    cout << name << endl;
//    if (size) {
//        while (head) {
//            tmp = tmp->next;
//            if (head->data.Power())
//                delete head;
//            head = tmp;
//            size--;
//        }
//    }
//}


template <typename T>
Set<T>::Set() {
    head = nullptr;
    size = 0;
    name = "unknown";
}

template <typename T>
Set<T>::Set(const string& n) {
    head = nullptr;
    size = 0;
    name = n;
}


Set<string>::Set(node<string>* _head, size_t _size) {
    head = _head;
    size = _size;
    name = "unknown";
}

Set<string>::Set(vector <string> elems) {

    for (auto& item : elems) {
        this->Add(item);
    }
    name = "unknown";
}



template <typename T>
T* Set<T>::FindByName(const string& n) {
    node<T>* set = Find({ n });
    if (!set) {
        string message = "No set named " + n;
        throw invalid_argument(message.c_str());
    }
    return &(set->data);
}


template <typename T>
size_t Set<T>::Power() const {
    return size;
}

// add check for existance of sets with similiar name
template <typename T>
void Set<T>::ChangeName(const string& new_name) {
    name = new_name;
}

template <typename T>
bool Set<T>::Check(const T& data){
    if (this->Find(data) != nullptr) {
        return true;
    }
    return false;

}

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
// a b c
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
template <typename T>

void Set<T>::Print() {
    node<T>* tmp = head;
    if (!size) {
        cout << "Empty set" << endl;
        return;
    }
    for (size_t i = 0; i < size; i++) {
        cout << tmp->data << endl;
        tmp = tmp->next;
    }
}

template <typename T>
bool operator<(const Set<T>& lhs, const Set<T>& rhs) {
    return lhs.Name() < rhs.Name();
}

// for printing names of all existing sets via Print()
ostream& operator<<(ostream& stream, const Set<string>& s) {
    stream << s.Name();
    return stream;
}
template <typename T>
bool operator>(const Set<T>& lhs, const Set<T>& rhs) {
    return lhs.Name() > rhs.Name();
}

template <typename T>
bool operator==(const Set<T>& lhs, const Set<T>& rhs) {
    return lhs.Name() == rhs.Name();
}

template <typename T>
bool operator!=(const Set<T>& lhs, const Set<T>& rhs) {
    return lhs.Name() != rhs.Name();
}




void Append(node<string>** head, node<string>** tail, string new_data) {
    	node<string>* new_elem = new node<string>(new_data,nullptr);
    	if (*head == nullptr) {
    		*head = new_elem;
    	}
    	else {
    		(*tail)->next = new_elem;
    	}
    	*tail = new_elem;
    }
    
    node<string>* merge_lists(node<string>* a, node<string>* b, size_t& resulting_size) {
    	node<string>* res_head = nullptr;
    	node<string>* res_tail = nullptr;
    	node<string>* a_i = a;
    	node<string>* b_i = b;
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
    
    		Append(&res_head, &res_tail, nxt_data);
    
    		count++;
    	}
    	
    	
    	node<string>* left_set = (a_i == nullptr ? b_i : a_i);
    	while (left_set) {
    
    		Append(&res_head, &res_tail, left_set->data);
    		left_set = left_set->next;
    		count++;
    	}
    
    	resulting_size = count;
    	return res_head;
    }
    
    
    Set<string> Set<string>::Union(const Set<string>& b) {
    	size_t union_power = 0;
    	node<string>* union_head = merge_lists(head, b.head, union_power);
    	return { union_head, union_power };
    }
    
    bool Set<string>::Includes(const Set<string>& B) {
    	node<string>* a = head;
    	node<string>* b = B.head;
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
    
    	return (b == nullptr);
    }
    
    Set<string> Set<string>::Intersection(const Set<string>& b) {
    	node<string>* a_i = head;
    	node<string>* b_i = b.head;
    	node<string>* res_head = nullptr;
    	node<string>* res_tail = nullptr;
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
    
    Set<string> Set<string>::Subtract(const Set<string>& b) {
    	node<string>* a_i = head;
    	node<string>* b_i = b.head;
    	node<string>* res_head = nullptr;
    	node<string>* res_tail = nullptr;
    	string new_data;
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
    
    Set<string> Set<string>::XOR(const Set<string>& b) {
    	node<string>* a_i = head;
    	node<string>* b_i = b.head;
    	node<string>* res_head = nullptr;
    	node<string>* res_tail = nullptr;
    	string new_data;
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
    	node<string>* left_set = (a_i == nullptr ? b_i : a_i);
    	while (left_set) {
    
    		Append(&res_head, &res_tail, left_set->data);
    		left_set = left_set->next;
    		count++;
    	}
    
    
    	return { res_head,count };
    }


#endif // !SET



