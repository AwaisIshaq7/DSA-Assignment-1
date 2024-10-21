#ifndef STACK_H
#define STACK_H

#include <stdexcept>

template <typename T>
class Stack 
{
private:
    T* arr;
    int capacity;
    int top;

public:
    Stack(int size = 10) : capacity(size), top(-1)
{
        arr = new T[capacity];
    }

    ~Stack() {
        delete[] arr;
    }

    void push(const T& item) 
{
        if (top + 1 >= capacity) {
            resize();
        }
        arr[++top] = item;
    }

    void pop() {
        if (!isEmpty())
        {
            --top;
        }
    }

    T peek() const
    {
        if (!isEmpty()) {
            return arr[top];
        }
        throw std::runtime_error("Stack is empty");
    }

    bool isEmpty() const 
    {
        return top == -1;
    }

    int size() const {
        return top + 1;
    }

private:
    void resize() 
{
        capacity *= 2;
        T* newArr = new T[capacity];
        for (int i = 0; i < size(); ++i)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
};

#endif // STACK_H
