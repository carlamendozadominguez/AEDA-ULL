
#ifndef NODE_HPP
#define NODE_HPP

#include <cstdio>
#include <cassert>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

template <class T>

class Node{
    
    private:
        Node<T>* next;
        Node<T>* prev;
        T data;
        stack <int> pila_;

    public:
        Node();
        Node(const T& d);
        Node(const T& d, const stack<int>);
        ~Node();
        void meter_pila(stack<int> n);
        void set_next(Node<T>*);
        void set_prev(Node<T>*);

        Node<T>* get_next(void) const;
        Node<T>* get_prev(void) const;

        void set_data(const T& d);
        T get_data(void) const;

        ostream& write(ostream& os) const;

};

#endif /* NODE_HPP */


