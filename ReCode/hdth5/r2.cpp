#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

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

    /// --- Iterator Access ---
    Iterator begin() {
        return Iterator(_pHead);
    }
    Iterator end() {
        return Iterator(nullptr); // Iterator end() trỏ tới nullptr
    }

    /// --- Tên gọi theo chuẩn STL ---
    using iterator = Iterator;
    int size() const { return _n; }
    void push_back(const T& value) { AddTail(value); }
    void clear() { Clear(); }
    Iterator insert(Iterator pos, const T& value); // chèn trước vị trí pos

    T& operator[](int i);
    const T& operator[](int i) const;

    friend ostream& operator<<(ostream& os, const SLList& ll)
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
    // tự code
    Clear();
}

template<class T>
SLList<T>::SLList(const SLList& ll)
{
    // tự code: sao chép sâu (tạo nút mới cho từng phần tử của ll)
}

template<class T>
SLList<T>& SLList<T>::operator=(const SLList& ll)
{
    
}

template<class T>
void SLList<T>::Clear()
{
    // tự code
    while (_pHead != nullptr) {
        Node* tmp = _pHead;
        _pHead = _pHead->_pNext;
        delete tmp;
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
    // tự code
}

template<class T>
void SLList<T>::RemoveHead()
{
    // tự code
}

template<class T>
void SLList<T>::RemoveTail()
{
    // tự code
}

template<class T>
class SLList<T>::Iterator
{
public:
    // Các type alias cần thiết cho iterator traits (không dùng <cstddef>)
    using iterator_category = forward_iterator_tag;
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
            throw "Dereferencing end() or null iterator";
        }
        return current_node->_info;
    }

    pointer operator->() const {
        if (!current_node) {
            throw "Accessing member via end() or null iterator";
        }
        return &(current_node->_info);
    }

    Iterator& operator++() {
        if (current_node) {
            current_node = current_node->_pNext;
        }
        else {
            throw "Incrementing end() or null iterator";
        }
        return *this;
    }

    Iterator operator++(int) {
        if (!current_node) {
            throw "Incrementing end() or null iterator";
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
    while (prev->_pNext != pos.current_node)
    {
        prev = prev->_pNext;
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
        throw "SLList index out of range";
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
        throw "SLList index out of range";
    }
    Node* node = _pHead;
    for (int k = 0; k < i; ++k)
    {
        node = node->_pNext;
    }
    return node->_info;
}

void fnAction(int val)
{
    cout << val << ", ";
}

void fnAction2(int& val)
{
    val *= 2;
}

bool fnPredict(int val)
{
    const int threshold = 3;
    return val > threshold;
}

int main()
{
    SLList<int> l;
    l.AddTail(1);
    l.AddTail(1);
    l.AddTail(0);
    l.AddTail(4);
    l.AddTail(2);
    l.AddTail(5);

    /// duyệt sử dụng iterator (chuẩn STL)
    for (SLList<int>::Iterator it = l.begin(); it != l.end(); ++it)
    {
        cout << *it << ", ";
    }
    cout << endl;

    /// sử dụng hàm for_each trong algorithm
    for_each(l.begin(), l.end(), fnAction2);
    for_each(l.begin(), l.end(), fnAction);
    cout << endl;

    /// sử dụng hàm replace_if trong algorithm
    replace_if(l.begin(), l.end(), fnPredict, 100);
    cout << l << endl;

    /// sử dụng hàm fill trong algorithm
    fill(l.begin(), l.end(), 123);
    cout << l << endl;

    l.Clear();
    system("pause");
    return 0;
}
