#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class list {
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
