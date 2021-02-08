#pragma once
#ifndef SET
#define SET
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>

#include <tuple>
//#include <algorithm>


struct node {
    std::string data;
    node* next;
    node();
    node(const std::string& data);
    node(const std::string& data, node* next);

};




node* merge_lists(node* a, node* b, size_t& resulting_size);
void Append(node** head, node** tail, std::string new_data);

class Set
{
private:
    std::string name = "unknown";
    size_t size;
    node* head;
    node* Find(const std::string& data);
public:
    Set();
    Set(node* _head, size_t _size);
    Set(std::vector <std::string> elems);
    Set(const std::string& name);
    ~Set();
    size_t Power() const;
    bool Check(const std::string& data);
    int Add(const std::string& data);
    int Del(const std::string& data);
    Set Union(const Set& b);
    bool Includes(const Set& b);
    Set Intersection(const Set& b);
    //node* Head();
    Set Subtract(const Set& b);
    Set XOR(const Set& b);


    void Print();
};

//todo: class of all classes
//class SetOfSets : public Set
//{
//    private:
//     
//public:
//
//};


#endif // !SET



