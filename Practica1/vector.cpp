/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vector.cpp
 * Author: carla
 * 
 * Created on 14 de febrero de 2018, 19:13
 */

#include "vector.hpp"

template <class T>
Vector<T>::Vector(){
    vector = NULL;
    sz = 0;
}

template <class T>
Vector<T>::Vector(int size){
    vector = NULL;
    sz = size;
    
    crea_vector();
}

template <class T>
Vector<T>::~Vector(void){
    destruye_vector();
}

template <class T>
void Vector<T>::crea_vector(void){
    vector = new T[sz];
}

template <class T>
void Vector<T>::destruye_vector(void){
    if(vector != NULL){
        delete [] vector;
        vector = NULL;
    }
}

template <class T>
void Vector<T>::resize(int size){
    destruye_vector();
    sz = size;
    crea_vector();
}

template <class T>
int Vector<T>::get_sz(void) const{
    return sz;
}

template <class T>
T Vector<T>::get_v(int pos) const{
    assert((pos < sz) && (pos >= 0));
    return (vector[pos]);            
}

template <class T>
T& Vector<T>::get_set_v(int pos){
    assert((pos < sz) && (pos >= 0));
    return (vector[pos]);            
}

template <class T>
ostream& Vector<T>::write(ostream& os) const{
	
    for(int i = 0; i < sz; i ++)
        os << vector[i] << " ";
        return os;
}

//PARA EL FALLO DEL ENLAZADOR
template class Vector<int>;
template class Vector<float>;
template class Vector<double>;
template class Vector<char>;