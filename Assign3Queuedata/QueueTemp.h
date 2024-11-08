#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Queue {
private:
    T* data;
    int front, rear, capacity,num_items;

public:
    Queue(int size) : front(-1), rear(-1), capacity(size), num_items(0) {
        data = new T[capacity];
    }

    ~Queue() {
        delete[] data;
    }
    // empty function 
    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }
    // push function 
    void enqueue(const T& item) {
        if (isFull()) {
            std::cout << "Queue is full!" << std::endl;
            return;
        }

        if (isEmpty()) {
            front = 0;
        }

        rear = (rear + 1) % capacity;
        num_items++;
        data[rear] = item;
    }

    // pop function 
    T dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty!" << std::endl;
            throw std::runtime_error("Queue underflow");
        }

        T item = data[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % capacity;
        }
        num_items--;
        return item;
    }

    // front function
    T peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty!" << std::endl;
            throw std::runtime_error("Queue underflow");
        }

        return data[front];
    }

    // size function
    T count() {
        return num_items;
    }
    
    T move_to_rear() {
        int shift;
        shift = data[front];
        dequeue();
        enqueue(shift);
        return 0;
    }

    T display() {
        int shift,length; 
        length = count();
        for (int i = 0; i < length; i++) {
            
            cout << peek() << ", ";
            
            shift = data[front];
            dequeue();
            enqueue(shift);
        }
        return 0;
    }

};

