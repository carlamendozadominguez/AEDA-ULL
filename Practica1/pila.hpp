/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pila.hpp
 * Author: carla
 *
 * Created on 14 de febrero de 2018, 11:52
 */

#ifndef PILA_HPP
#define PILA_HPP

#include <iostream>
#include <cassert>
#include "lista.hpp"
/*A partir de una lista haremos una pila*/

using namespace std;

template <class T>
class Pila {
    private:
        List<T> stack_l;
        
   public:
       Pila(void);
       ~Pila(void);
       bool empty();
       T top(void);
       void pop(void);
       void push(T dato);
       ostream& write(ostream& os);   

};

#endif /* PILA_HPP */

