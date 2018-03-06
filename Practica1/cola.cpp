/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cola.cpp
 * Author: carla
 * 
 * Created on 14 de febrero de 2018, 11:51
 */

#include "cola.hpp"

template <class T>
Cola<T>::Cola(void){}

template <class T>
Cola<T>::~Cola(void){}

template <class T>
bool Cola<T>::empty(void){
    return queue_l.empty();
}

template <class T>
int Cola<T>::size(void){
    return queue_l.get_size();
}

template <class T>
T Cola<T>::front(void){
    assert(!empty());
    Node<T>* aux = queue_l.get_tail();
    T dato = aux->get_data();
    return dato;
}

template <class T>
T Cola<T>::back(void){
    assert(!empty());
    Node<T>* aux = queue_l.get_head();
    return aux->get_data();
}

template <class T>
void Cola<T>::pop(void){
    assert(!empty());
    Node<T>* aux = queue_l.extract_tail();
    delete aux;
}

template <class T>
void Cola<T>::push(T dato){
    Node<T>* aux = new Node<T>(dato);
    queue_l.insert_head(aux);
}

template <class T>
ostream& Cola<T>::write(ostream& os){
    Node<T>* aux = queue_l.get_head();
    while(aux != NULL){
        os<< aux->get_data();
        aux = aux->get_next();
    }
    
    os<<endl;
    return os;
}

//PARA EL FALLO DEL ENLAZADOR
template class Cola<int>;
template class Cola<float>;
template class Cola<double>;
template class Cola<char>;

