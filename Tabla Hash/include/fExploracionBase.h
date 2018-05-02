/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fExploracionBase.h
 * Author: carla
 *
 * Created on 1 de abril de 2018, 19:03
 */

#ifndef FEXPLORACIONBASE_H
#define FEXPLORACIONBASE_H

#include <cstdio>
#include "fDispersionBase.h"

//Se utiliza cuando hay colison en una clave, nos devuelven cuantas pos se tiene que desplazar


template <class Clave>
class fExploracionBase{
public:
    virtual int explore (Clave x, int i) = 0;
  
};





//Busca hueco en la siguiente celda, no tiene encuenta la clave

template <class Clave>
class fExploracionLineal : public fExploracionBase<Clave>{

private:
    int size_;
    
public:

    fExploracionLineal (int size){
        size_ = size;
    }
    
    int explore (Clave x, int i){
        return i;
    }
};




//en este caso es el cuadrado del intento que estoy haciendo

template <class Clave>
class fExploracionCuadratica : public fExploracionBase<Clave>
{
    
private:
    int size_;
    
public:

    fExploracionCuadratica (int size){
        size_ = size;
    }
    
    int explore (Clave x, int i){
        return (i * i);
    }
};




//el método de doble dispersión juega con dos funciones de dispersión
//se genera un desplazamiento en función del intento y del valor que nos devuelva una función de dispersión

template <class Clave>
class fExploracionDoble : public fExploracionBase<Clave>{
    
private:
    int size_;
    
public:

    fExploracionDoble (int size){
        size_ = size;
    }
    
    int explore (Clave x, int i){
        fDispersionBase<Clave>* aux = new fDispersionAleatorio<Clave> (size_);
        return (i * aux->hash(x));
    }
};





//lo que haremos es poner como semilla la clave para la función srand();

template <class Clave>
class fExploracionReDisp : public fExploracionBase<Clave>{
    
private:
    int size_;
    
public:

    fExploracionReDisp (int size){
        size_ = size;
    }
    
    int explore (Clave x, int i){
        for (int j=0;j< i; j++){
            long int semilla = x;
            srand(semilla);
        }
        return rand() % size_;
    }
};

#endif /* FEXPLORACIONBASE_H */

