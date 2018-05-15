/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   NodoBB.h
 * Author: carla
 *
 * Created on 28 de abril de 2018, 11:25
 */

#ifndef NODOBB_H
#define NODOBB_H


#include <cstdio>

using namespace std;

template <class T>
class nodoBB {

  public:
    T dato_;  // Valor del contenido del nodo
    nodoBB<T> *izq_;  // Nodo hijo izquierdo
    nodoBB<T> *dch_;  // Nodo hijo derecho
    int factor_balanceo;

  public:
    /* Constructor por defecto */
    nodoBB (void) {
        izq_ = NULL;
        dch_ = NULL;
    }

    /* Constructor parametrizado */
    nodoBB (const T dato, nodoBB<T> *izq=NULL, nodoBB<T> *dch=NULL) {
        dato_ = dato;
        izq_ = izq;
        dch_ = dch;
    }

    /* Destructor */
    ~nodoBB (void) {
        if (izq_ != NULL) {
            delete izq_;
            izq_ = NULL;
        }
        if (dch_ != NULL) {
            delete dch_;
            dch_ = NULL;
        }
    }

    T get_dato (void) {
        return dato_;
    }

    void set_dato (T dato) {
        dato_ = dato;
    }

    nodoBB<T>*& get_izq (void) {
        return izq_;
    }

    nodoBB<T>*& get_dch (void) {
        return dch_;
    }


    int get_factor() {
        return factor_balanceo;
    }

    void set_factor(int f) {
        factor_balanceo =f;
    }

    void mostrar(void) const {
        if (this == NULL) {
            cout << "[.]";
        } else {
            cout << "[" << dato_ << "]";
        }
    }
};

#endif /* NODOBB_H */

