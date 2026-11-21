#include <iostream>
#include <cstdlib>
#include "b2.h"


template<class InputIt, class UnaryFunction>
UnaryFunction for_each(InputIt first, InputIt last, UnaryFunction f)
{
    for (; first != last; ++first) {
        f(*first);
    }
    return f;
}

template<class ForwardIt, class UnaryPredicate, class T>
void replace_if(ForwardIt first, ForwardIt last, UnaryPredicate p, const T& new_value)
{
    for (; first != last; ++first) {
        if (p(*first)) {
            *first = new_value;
        }
    }
}

template<class ForwardIt, class T>
void fill(ForwardIt first, ForwardIt last, const T& value)
{
    for (; first != last; ++first) {
        *first = value;
    }
}

void fnAction(int val)
{
    std::cout << val << ", ";
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
    for (SLList<int>::Iterator it = l.begin(); it != l.end(); ++it)
    {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
    for_each(l.begin(), l.end(), fnAction2);
    for_each(l.begin(), l.end(), fnAction);
    std::cout << std::endl;
    replace_if(l.begin(), l.end(), fnPredict, 100);
    std::cout << l << std::endl;
    fill(l.begin(), l.end(), 123);
    std::cout << l << std::endl;
    l.Clear();
    system("pause");
    return 0;
}