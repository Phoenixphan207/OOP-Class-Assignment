#pragma once 
#include <iostream>
#include <stdexcept>
#include <exception>


template<class T>
class SLList
{
private:
    struct Node
    {
        T _info;
        Node* _pNext;
    };

    Node* _pHead, * _pTail;
    int _n;

    static Node* CreateNode(const T& value)
    {
        Node* node = new Node{ value, nullptr };
        return node;
    }

public:
    class Iterator;

    SLList();
    SLList(const SLList&);
    ~SLList();
    SLList& operator=(const SLList&);

    void AddHead(const T&);
    void AddTail(const T&);
    void RemoveHead();
    void RemoveTail();
    void Clear();

    Iterator begin() {
        return Iterator(_pHead);
    }
    Iterator end() {
        return Iterator(nullptr);
    }

    using iterator = Iterator;
    int size() const { return _n; }
    void push_back(const T& value) { AddTail(value); }
    void clear() { Clear(); }
    Iterator insert(Iterator pos, const T& value);

    T& operator[](int i);
    const T& operator[](int i) const;

    friend std::ostream& operator<<(std::ostream& os, const SLList& ll)
    {
        Node* node = ll._pHead;
        while (node != nullptr)
        {
            os << node->_info << ", ";
            node = node->_pNext;
        }
        return os;
    }
};

template<class T>
SLList<T>::SLList()
{
    _pHead = _pTail = nullptr;
    _n = 0;
}

template<class T>
SLList<T>::~SLList()
{
    Clear();
}

template<class T>
SLList<T>::SLList(const SLList& ll)
{
    _pHead = _pTail = nullptr;
    _n = 0;
    Node* cur = ll._pHead;
    while (cur != nullptr)
    {
        AddTail(cur->_info);
        cur = cur->_pNext;
    }
}

template<class T>
SLList<T>& SLList<T>::operator=(const SLList& ll)
{
    if (this == &ll)
    {
        return *this;
    }
    Clear();
    Node* cur = ll._pHead;
    while (cur != nullptr)
    {
        AddTail(cur->_info);
        cur = cur->_pNext;
    }
    return *this;
}

template<class T>
void SLList<T>::Clear()
{
    while (_pHead != nullptr)
    {
        Node* temp = _pHead;
        _pHead = _pHead->_pNext;
        delete temp;
    }
    _pTail = nullptr;
    _n = 0;
}

template<class T>
void SLList<T>::AddTail(const T& value)
{
    Node* node = CreateNode(value);
    if (node == nullptr)
    {
        return;
    }
    if (_pHead == nullptr)
    {
        _pHead = _pTail = node;
        _n++;
        return;
    }
    _pTail->_pNext = node;
    _pTail = node;
    _n++;
}

template<class T>
void SLList<T>::AddHead(const T& value)
{
    Node* node = CreateNode(value);
    if (node == nullptr)
    {
        return;
    }
    if (_pHead == nullptr)
    {
        _pHead = _pTail = node;
        _n++;
        return;
    }
    node->_pNext = _pHead;
    _pHead = node;
    _n++;
}

template<class T>
void SLList<T>::RemoveHead()
{
    if (_pHead == nullptr)
    {
        return;
    }
    Node* temp = _pHead;
    _pHead = _pHead->_pNext;
    delete temp;
    _n--;
    if (_pHead == nullptr)
    {
        _pTail = nullptr;
    }
}

template<class T>
void SLList<T>::RemoveTail()
{
    if (_pHead == nullptr)
    {
        return;
    }
    if (_pHead == _pTail)
    {
        delete _pHead;
        _pHead = _pTail = nullptr;
        _n = 0;
        return;
    }
    Node* prev = _pHead;
    while (prev->_pNext != _pTail)
    {
        prev = prev->_pNext;
    }
    delete _pTail;
    _pTail = prev;
    _pTail->_pNext = nullptr;
    _n--;
}

template<class T>
class SLList<T>::Iterator
{
public:
    using difference_type = long long;
    using value_type = T;
    using pointer = T*;
    using reference = T&;

private:
    Node* current_node;
    Iterator(Node* node) : current_node(node) {}
    friend class SLList<T>;

public:
    Iterator() : current_node(nullptr) {}

    reference operator*() const {
        if (!current_node) {
            throw std::out_of_range("Dereferencing end() or null iterator");
        }
        return current_node->_info;
    }

    pointer operator->() const {
        if (!current_node) {
            throw std::out_of_range("Accessing member via end() or null iterator");
        }
        return &(current_node->_info);
    }

    Iterator& operator++() {
        if (current_node) {
            current_node = current_node->_pNext;
        }
        else {
            throw std::out_of_range("Incrementing end() or null iterator");
        }
        return *this;
    }

    Iterator operator++(int) {
        if (!current_node) {
            throw std::out_of_range("Incrementing end() or null iterator");
        }
        Iterator temp = *this;
        current_node = current_node->_pNext;
        return temp;
    }

    bool operator==(const Iterator& other) const {
        return current_node == other.current_node;
    }

    bool operator!=(const Iterator& other) const {
        return !(*this == other);
    }
};

template<class T>
typename SLList<T>::Iterator SLList<T>::insert(Iterator pos, const T& value)
{
    if (pos.current_node == _pHead)
    {
        AddHead(value);
        return begin();
    }
    if (pos.current_node == nullptr)
    {
        AddTail(value);
        return Iterator(_pTail);
    }
    Node* prev = _pHead;
    while (prev != nullptr && prev->_pNext != pos.current_node)
    {
        prev = prev->_pNext;
    }
    if (prev == nullptr)
    {
        throw std::invalid_argument("Iterator does not belong to this list");
    }
    Node* node = CreateNode(value);
    node->_pNext = pos.current_node;
    prev->_pNext = node;
    _n++;
    return Iterator(node);
}

template<class T>
T& SLList<T>::operator[](int i)
{
    if (i < 0 || i >= _n)
    {
        throw std::out_of_range("SLList index out of range");
    }
    Node* node = _pHead;
    for (int k = 0; k < i; ++k)
    {
        node = node->_pNext;
    }
    return node->_info;
}

template<class T>
const T& SLList<T>::operator[](int i) const
{
    if (i < 0 || i >= _n)
    {
        throw std::out_of_range("SLList index out of range");
    }
    Node* node = _pHead;
    for (int k = 0; k < i; ++k)
    {
        node = node->_pNext;
    }
    return node->_info;
}