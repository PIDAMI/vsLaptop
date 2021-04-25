#pragma once
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <type_traits>
#include <string>
#include <vector>
#include <sstream>
template <typename T>
struct node {
    T data;
    node* next;
    node(const T& data);
    node(const T& data, node* next);
};

node<std::string>* merge_lists(node<std::string>* a, node<std::string>* b, size_t& resulting_size);
void Append(node<std::string>** head, node<std::string>** tail, std::string new_data);


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
    size_t Power() const;
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
    void Copy(Set dest);
    std::vector<std::string> Elements();
};
std::ostream& operator<<(std::ostream& stream, const Set<std::string>& s);



void init_();
void help(const std::string& command);
bool has_one_operand(const std::string& command);
bool has_two_operands(const std::string& command);
bool has_three_operands(const std::string& command);
bool add_or_del(const std::string& command);
bool valid_name(const std::string& name);

void one_operand_action(Set<Set<std::string>>& main, const std::string& command, const std::string& set_name);
void two_operand_action(Set<Set<std::string>>& main, const std::string& command,
    const std::string& set_name, const std::string& rest_of_command);
void three_operand_action(Set<Set<std::string>>& main, const std::string& command,
    const std::string& set_name, const std::string& set_lhs, const std::string& set_rhs);
void add_or_del_action(Set<Set<std::string>>& main, const std::string& command,
    const std::string& set_name, const std::string& words);
void parse_command(const std::string& input, Set<Set<std::string>>& main, Set<std::string>& valid_commands);
std::vector <std::string> tokenize(const std::string& str);

template <typename T>
bool is_whitespaces_only(const T& s)
{
    bool res = true;
    std::stringstream stream;
    stream << s;
    std::string str;
    stream >> str;
    for (auto c : str)
    {
        if (c != ' ')
            res = false;
    }
    return res;
}
