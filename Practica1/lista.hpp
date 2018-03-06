/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lista.hpp
 * Author: carla
 *
 * Created on 13 de febrero de 2018, 22:29
 */

#ifndef LISTA_HPP
#define LISTA_HPP

#include <iostream>
#include <cassert>
#include "node_l.hpp"

using namespace std;

template <class T>

class List{

    private:
        Node<T>* head;
        Node<T>* tail;
        int sz;

    public:
        List(void);
        ~List(void);

        void insert_tail(Node<T>*);
        void insert_head(Node<T>*);

        Node<T>* extract_head(void);
        Node<T>* extract_tail(void);

        Node<T>* get_tail(void);
        Node<T>* get_head(void);

        bool empty(void);
        void remove(Node<T>*);
        int get_size(void);
        void remove_pos(int pos);
        T get_pos(int pos);
        void set_pos(T& dato, int pos);

        ostream& write(ostream& os);

};


#endif /* LISTA_HPP */

