#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class list 
{
protected:
    template <typename V>
    class Node {
    public:
        V value;
        Node<V>* next;
        Node(const V& value = V(), Node<V>* next = nullptr) : value(value), next(next) {}
    };

    Node<T>* first = nullptr;
    Node<T>* last = nullptr;

public:
    class iterator {
    public:
        Node<T>* currNode;

        iterator(Node<T>* node) : currNode(node) {}

        T& operator*() 
        {
            if (currNode == nullptr) throw std::out_of_range("Iterator out of range");
            return currNode->value;
        }

        iterator& operator++() 
        {
            if (currNode != nullptr) currNode = currNode->next;
            return *this;
        }

        bool operator!=(const iterator& second) const 
        {
            return currNode != second.currNode;
        }

        bool operator==(const iterator& second) const 
        {
            return currNode == second.currNode;
        }

        Node<T>* getNode() const 
        { 
            return currNode;
        } 
    };

    iterator begin() const 
    { 
        return iterator(first); 
    }

    iterator end() const 
    { 
        return iterator(nullptr); 
    }

    void insert_front(const T& val)
    {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = first;
        first = newNode;
        if (last == nullptr) {
            last = newNode;
        }
    }

    void erase_front()
    {
        if (first == nullptr) return;
        Node<T>* tmp = first;
        first = first->next;
        if (first == nullptr) {
            last = nullptr;
        }
        delete tmp;
    }

    void insert_after(iterator it, const T& val) 
    {
        if (it.getNode() == nullptr) { 
            push_back(val);
            return;
        }
        Node<T>* newNode = new Node<T>(val);
        newNode->next = it.currNode->next;
        it.currNode->next = newNode;
        if (newNode->next == nullptr) {
            last = newNode; 
        }
    }

    void erase_after(iterator it) 
    {
        if (it.getNode() == nullptr || it.getNode()->next == nullptr) return;
        Node<T>* tmp = it.currNode->next;
        it.currNode->next = tmp->next;
        if (tmp == last) last = it.currNode;
        delete tmp;
        if (it.currNode->next == nullptr) {
            it.currNode = nullptr; 
        }
    }

    list(int size = 0)
    {
        if (size < 0) throw std::out_of_range("incorrect size");
        for (int i = 0; i < size; i++) {
            push_back(T());
        }
    }

    list(list&& second) noexcept
    {
        this->first = second.first;
        last = second.last;
        second.first = nullptr;
        second.last = nullptr;
    }

    list(const list& other) {  
        if (other.empty()) return;

        Node<T>* current = other.first;
        while (current) {
            push_back(current->value);
            current = current->next;
        }
    }

    list& operator=(const list& second) { 
        if (this == &second) { 
            return *this;
        }
        clear(); 
        Node<T>* curr = second.first;
        while (curr) {
            push_back(curr->value);
            curr = curr->next;
        }
        return *this;
    }

    list& operator=(list&& second) noexcept
    {
        this->clear();
        this->first = second.first;
        this->last = second.last;
        second.first = nullptr;
        second.last = nullptr;
        return *this;
    }

    void clear()
    {
        while (first != nullptr) {
            pop_front();
        }
        first = last = nullptr;
    }


    ~list()
    {
        clear();
    }

    bool empty() const
    {
        return (first == nullptr);
    }

    void push_back(const T& val)
    {
        Node<T>* newNode = new Node<T>(val);

        if (last == nullptr) {
            first = last = newNode;
        }
        else {
            last->next = newNode;
            last = newNode;
        }
    }

    void pop_back() 
    {
        if (first == nullptr) throw std::out_of_range("list is empty");
        Node<T>* prev = nullptr;
        Node<T>* curr = first;
        while (curr != last) {
            prev = curr;
            curr = curr->next;
            if (!curr) break;
        }
        if (prev == nullptr) {
            delete curr;
            first = last = nullptr;
        }
        else {
            delete curr;
            last = prev;
        last->next = nullptr;
    }
    }

    void push_front(const T& val)
    {
        Node<T>* newNode = new Node<T>(val);
        if (first == nullptr) {
            first = last = newNode;
        }
        else {
            newNode->next = first;
            first = newNode;
        }
    }

    void pop_front()
    {
        if (first == nullptr) throw std::out_of_range("list is empty");
        Node<T>* tmp = first;
        first = first->next;
        delete tmp;
        if (first == nullptr) last = nullptr;

    }

    T& back_val()
    {
        if (last == nullptr) throw std::out_of_range("list is empty");
        return last->value;
    }

    const T& back_val() const
    {
        if (last == nullptr) throw std::out_of_range("list is empty");
        return last->value;
    }

    T& front_val()
    {
        if (first == nullptr) throw std::out_of_range("list is empty");
        return first->value;
    }

    const T& front_val() const
    {
        if (first == nullptr) throw std::out_of_range("list is empty");
        return first->value;
    }

    size_t size() const
    {
        size_t count = 0;
        Node<T>* curr = first;
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }
        return count;
    }

    void print()
    {
        Node<T>* curr = first;
        bool empty = 1;
        while (curr != nullptr) {
            std::cout << curr->value << " ";
            curr = curr->next;
            empty = 0;
        }
        if (empty) {
            std::cout << "empty list";
        }
        std::cout << std::endl;
    }
};


