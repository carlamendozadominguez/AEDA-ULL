/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "node_l.hpp"

template <class T>
Node<T>::Node(){
    next = NULL;
    prev = NULL;
}


template <class T>
Node<T>::Node(const T& d){
    next = NULL;
    prev = NULL;
    data = d;
}

template <class T>
Node<T>::Node(const T& d,stack<int> pila){
    next = NULL;
    prev = NULL;
    data = d;
    pila_ = pila;
}

template <class T>
void Node<T>::meter_pila(stack<int> n){
    pila_ = n;
}

template <class T>
Node<T>* Node<T>::get_next(void) const{
    return next;
}

template <class T>
void Node<T>::set_next(Node<T>* sig){
    next = sig;
}

template <class T>
void Node<T>::set_prev(Node<T>* ant){
	prev = ant;
}

template <class T>
Node<T>* Node<T>::get_prev(void) const{
	return prev;
}

template <class T>
void Node<T>::set_data(const T& d){
	data = d;
}

template <class T>
T Node<T>::get_data(void) const{
    return data;
}

template <class T>
ostream& Node<T>::write(ostream& os) const{
	os << data;
	return os;
}

template <class T>
Node<T>::~Node(void) {}

//PARA EL FALLO DEL ENLAZADOR
template class Node<int>;
template class Node<float>;
template class Node<double>;
template class Node<char>;
