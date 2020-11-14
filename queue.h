#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <stdexcept>
#include "ldl.h"

using namespace std;

template<typename T>
class Queue
{
public:
    Queue(){}
    ~Queue()
    {
        list.clear();
    }
    bool empty() const;
    size_t size() const;
    const T& front() const;
    const T& back() const;
    void push(const T& element);
    void pop();

private:
    LDL<T> list;
};

template<typename T>
bool Queue<T>::empty() const
{
    return list.empty();
}

template<typename T>
size_t Queue<T>::size() const
{
    return list.size();
}

template<typename T>
const T &Queue<T>::front() const
{
    if (empty())
    {
        throw runtime_error("Trying front() from empty queue.");
    }

    return list.front();
}

template<typename T>
const T& Queue<T>::back() const
{
    if (empty())
    {
        throw runtime_error("Trying back() from empty queue.");
    }

    return list.back();
}

template<typename T>
void Queue<T>::push(const T& element)
{
    list.push_back(element);
}

template<typename T>
void Queue<T>::pop()
{
    list.pop_front();
}
#endif // QUEUE_H
