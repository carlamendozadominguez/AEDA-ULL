/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vector.hpp
 * Author: carla
 *
 * Created on 14 de febrero de 2018, 19:13
 */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstdio>
#include <iostream>
#include <iomanip>

#include <cassert>

using namespace std;

template <class T>
class Vector {
    
    private:
        T* vector;
        int sz;
        
    public:
        Vector();
        Vector(int);
        ~Vector();
        void resize(int);
        int get_sz(void) const;
        T get_v(int pos) const;
        T& get_set_v(int pos);
        void crea_vector(void);
        void destruye_vector(void);
        ostream& write(ostream& os) const;
};

#endif /* VECTOR_HPP */

