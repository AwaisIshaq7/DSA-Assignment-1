#pragma once


template <typename T>
class Stack {
private:
    T* arr;
    int capacity;
    int top;

public:
    Stack(int size = 10) : capacity(size), top(-1) {
        arr = new T[capacity];
    }

    ~Stack() {
        delete[] arr; // Deallocate memory
    }

    void push(const T& item) {
        if (top + 1 >= capacity) {
            resize();
        }
        arr[++top] = item;
    }
    void pop() {
        if (!isEmpty()) {
            --top;
        }
    }

    T peek() const {
        if (!isEmpty()) {
            return arr[top];
        }
        throw runtime_error("Stack is completely empty");
    }

    bool isEmpty() const {
        return top == -1;
    }

    int size() const {
        return top + 1;
    }

private:
    void resize() { // Resize the array
        capacity *= 2;
        T* newArr = new T[capacity]; 
        for (int i = 0; i < size(); ++i) {
            newArr[i] = arr[i];  // Copy elements to the new array
        }
        delete[] arr; 
        arr = newArr;   
    }
};

