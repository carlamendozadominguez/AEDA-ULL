/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matriz.h
 * Author: carla
 *
 * Created on 24 de febrero de 2018, 11:58
 */

#ifndef MATRIZ_H
#define MATRIZ_H

#include <vector>
#include <iostream>

using namespace std;

class Matriz {
    
private:  
    vector < vector<int> > matriz;
    int m_;
    int n_;
    
public:
    Matriz();
    Matriz(int m , int n);
    ~Matriz();
    int get(int i, int j);
    void set(int, int, int);
    int max_iter();
    int get_size();
    int get_n();
    int get_m();
    void set_n(int);
    void set_m(int);
    
    Matriz& operator=(const Matriz& other);    
    
};

#endif /* MATRIZ_H */

