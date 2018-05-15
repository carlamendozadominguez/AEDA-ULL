/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dni.h
 * Author: carla
 *
 * Created on 1 de mayo de 2018, 19:28
 */

#ifndef DNI_H
#define DNI_H


#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <random>
#include <string>

extern int contador;  // Se importa la variable global contador como variable externa


class Dni{
    
private:
   unsigned long int numero_dni;
    std::string name;
    
public:
    
    Dni(void){
        numero_dni = 0;
    }
    
    Dni (unsigned long int dni){
        numero_dni = dni;
    }
    
    long int dni(void){
        return numero_dni;
    }

    std::string get_name(void) const{
    	return name;
    }

    void set_name(std::string name_){
    	name = name_;
    }
    
    long int operator% (const int& num){
        long int resultado = numero_dni % num;
        return resultado;
    }
    
    void operator= (const int& num){
        numero_dni = num;
    }
    
    bool operator== (const Dni& other) const{
        contador++;
        if (numero_dni == other.numero_dni)
            return true;
        else
            return false;
    }
    
    bool operator== (const int& num) const{
        contador++;
        if (numero_dni == num)
            return true;
        else
            return false;
    }
    
    
    bool operator!= (const Dni& other){
    	contador++;
        if (this->numero_dni == other.numero_dni)
            return false;
        else
            return true;
    }
    
    bool operator> (const Dni& other) const{
    	contador++;
        if (this->numero_dni > other.numero_dni)
            return true;
        else
            return false;
    }
    
    bool operator> (const int& num) const{
        contador++;
        if (this->numero_dni > num)
            return true;
        else
            return false;
    }
    
    bool operator< (const Dni& other){
    	contador++;
        if (numero_dni < other.numero_dni)
            return true;
        else
            return false;
    }
    
    bool operator>= (const Dni& other){
        contador++;
        if (numero_dni >= other.numero_dni)
            return true;
        else
            return false;
    }
    
    bool operator<= (const Dni& other){
    	contador ++;
        if (numero_dni <= other.numero_dni)
            return true;
        else
            return false;
    }
    
    operator long int () const{
        return numero_dni;
    }
    
};

#endif /* DNI_H */

