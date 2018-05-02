/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matriz.cpp
 * Author: carla
 * 
 * Created on 24 de febrero de 2018, 11:58
 */

#include "Matriz.h"

Matriz::Matriz() {
    m_ = 10; 
    n_ = 10;
    vector<vector<int>> matrix(m_, vector<int>(n_));
    matriz = matrix;  
}

Matriz::Matriz(int m, int n) {
    m_ = m;
    n_ = n;
    vector<vector<int>> matrix(m, vector<int>(n));
    matriz = matrix;
}

Matriz::~Matriz() {
    m_ = 0;
    n_ = 0;
}

int Matriz::get(int i, int j){
    int valor = matriz[i].at(j);
    return (valor);  
}

void Matriz::set(int i, int j, int v){
    matriz[i].at(j) = v;
}

void Matriz::set_m(int m ){
    m_ = m;
}

void Matriz::set_n(int n){
    n_ = n;
}

int Matriz::get_m(void){
    return m_;
}

int Matriz::get_n(void){
    return n_;
}

Matriz& Matriz::operator=(const Matriz& other){
    
    if(this != &other){
        this->m_ = other.m_; 
        this->n_ = other.n_;
        this->matriz = other.matriz;
    }
    
    return *this;  
}