#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

template <class T>
class Queue {
private:
    T *data;
    int first, last;
    int length;

public:
    Queue() {
        data = new T[100];
        first = last = 0;
        length = 100;
    }

    Queue(int _length): length(_length) {
        data = new T[_length];
        first = last = 0;
    }

    ~Queue() {
        if (data) {
            delete[] data;
        }
    }

    void push(T _data) {
        if (last < length) {
            if (first != last) {
                data[last] = _data;
            } else {
                data[first] = _data;
            }
            last++;
        } else {
            cout<<"Queue is full"<<endl;
        }
    }

    T pop() {
        if (first != last) {
            T ret = data[first];
            for (int i = first; i < last; i++) {
                data[i] = data[i+1];
            }
            last--;
            return ret;
        } else {
            return T();
        }
    }

    T peek() {
        return data[first];
    }

    int occupiedSize() {
        return last;
    }

    void print() {
        if (first != last) {
            for (int i = first; i < last; i++) {
                cout<<data[i]<<" ";
            }
            cout<<endl;
        } else {
            cout<<"Queue is empty"<<endl;
        }
    }
};

#endif // QUEUE_H
