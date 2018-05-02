/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fDispersionBase.h
 * Author: carla
 *
 * Created on 1 de abril de 2018, 18:59
 */
#include <cstdio>
#include <cstdlib>

#ifndef FDISPERSIONBASE_H
#define FDISPERSIONBASE_H


template <class Clave>
class fDispersionBase{
    
public:
    virtual int hash (Clave x) = 0;
    
};



template <class Clave>
class fDispersionModulo : public fDispersionBase<Clave>{
    
private:
    int size_;
    
public:

    fDispersionModulo (int size){
        size_ = size;
    }
    
    int hash (Clave x){
        return (x % size_);
    }
};



template <class Clave>
class fDispersionAleatorio : public fDispersionBase<Clave>{
    
private:
    int size_;
    
public:

    fDispersionAleatorio (int size){
        size_ = size;
    }
    
    int hash (Clave x){
        int aux = static_cast<int> (x); //Cambia al tipo int en tiempo de ejecucion.
        srand(aux);
        return (rand() % size_);
    }
};


template <class Clave>
class fDispersionSuma : public fDispersionBase<Clave>{
    
private:
    int size_;
    
public:

    fDispersionSuma (int size){
        size_ = size;
    }
    
    int hash (Clave x){
        int d = 0 ;
        int y = 0;
        while (x > 0){
            y = x % 10;
            d = d + y;
            x = x / 10;
        }
        return (d % size_);
        
    }
};
#endif /* FDISPERSIONBASE_H */

