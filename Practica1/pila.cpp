/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pila.cpp
 * Author: carla
 * 
 * Created on 14 de febrero de 2018, 11:52
 */

#include "pila.hpp"

template <class T>
Pila<T>::Pila(void){}

template <class T>
Pila<T>::~Pila(){}

template <class T>
bool Pila<T>::empty(){
    return stack_l.empty();
}

template <class T>
T Pila<T>::top(void){
   assert(!empty());
   //Para devolver el top de la pila, cogemos el primer elemento de la lista       
   Node<T>* aux = stack_l.get_head();
   T data = aux ->get_data();
   return (data);
}

template <class T>
void Pila<T>::pop(void){
    assert(!empty());
    Node<T>* aux = stack_l.extract_head();
    delete aux;
}

template <class T>
void Pila<T>::push(T dato){
//Para meter un nuevo elemento creamos un nodo con el dato
//e insertamos al inicio en el top
    Node<T>* aux = new Node<T>(dato);
    stack_l.insert_head(aux);
}

template <class T>
ostream& Pila<T>::write(ostream& os){
    Node<T>* aux = stack_l.get_head();
    
    while(aux != NULL){
        cout<< aux->get_data()<<" ";
        aux = aux->get_next();
    }
}

//PARA EL FALLO DEL ENLAZADOR
template class Pila<int>;
template class Pila<float>;
template class Pila<double>;
template class Pila<char>;
