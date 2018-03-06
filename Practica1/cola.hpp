/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cola.hpp
 * Author: carla
 *
 * Created on 14 de febrero de 2018, 11:50
 */

#ifndef COLA_HPP
#define COLA_HPP

#include <iostream>
#include <cassert>

#include "lista.hpp"

using namespace std;
template <class T>
class Cola {
    
    private:
        List<T> queue_l;
        
    public:
        Cola(void);
        ~Cola(void);
        bool empty(void);
        int size(void);
        T front(void);
        T back(void);
        void pop(void);
        void push(T dato);
   	ostream& write(ostream& os);           
};

#endif /* COLA_HPP */

