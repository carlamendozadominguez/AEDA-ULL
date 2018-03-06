/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   node.hpp
 * Author: carla
 *
 * Created on 13 de febrero de 2018, 22:31
 */

#ifndef NODE_HPP
#define NODE_HPP

#include <cstdio>
#include <cassert>
#include <iostream>

using namespace std;

template <class T>

class Node{
    
    private:
        Node<T>* next;
        Node<T>* prev;
        T data;

    public:
        Node();
        Node(const T& d);
        ~Node();

        void set_next(Node<T>*);
        void set_prev(Node<T>*);

        Node<T>* get_next(void) const;
        Node<T>* get_prev(void) const;

        void set_data(const T& d);
        T get_data(void) const;

        ostream& write(ostream& os) const;

};

#endif /* NODE_HPP */

