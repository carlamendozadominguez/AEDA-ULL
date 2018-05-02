/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Celdas.h
 * Author: carla
 *
 * Created on 1 de abril de 2018, 18:10
 */


#include <vector>
#include <cstdio>
#include <iostream>
#include <iomanip>


#include <cstdio>


template<class Clave>
class Celdas{

private:
    std::vector<Clave> celdas;
    int nClaves;
    int it;

public:
    Celdas(void);
    Celdas(int nClaves);
    ~Celdas();
    bool estaLlena();
    bool buscar(const Clave& x);
    bool insertar(const Clave& x);
    void print (void) const;
    void print_name(void) const;
    void resize (int sz);



};

template<class Clave>
Celdas<Clave>::Celdas(void){
    nClaves = 0;
    it = 0;
}

//Creamos un vector de n Claves
template <class Clave>
Celdas<Clave>::Celdas(int nClaves_){
    celdas.resize(nClaves);
}

template <class Clave>
Celdas<Clave>::~Celdas (void)
{
	it = 0;
	celdas.clear();
}


template<class Clave>
bool Celdas<Clave>::estaLlena(){
    if(it >= celdas.size()){
        return true;
    }else{
        return false;
    }
}

template <class Clave>
bool Celdas<Clave>::insertar(const Clave &x){
    
    if(estaLlena()){
        
        std::cout<<"No insertado"<<std::endl;
        return false;
    }
    
    else{
        celdas[it]=x;
        it++; //Hemos metido a uno mas en la Celda
        std::cout<< "Insertado"<<std::endl;
        return true;
    }
    
}

template <class Clave>
bool Celdas<Clave>::buscar(const Clave &x){
    for(int i = 0; i < celdas.size(); i++){
            if(celdas.at(i) == x){
		return true;
	    }
            else if(celdas.at(i) == 0){
		return false;
	    }
        } 

    return false;
}


template <class Clave>
void Celdas<Clave>::print(void) const{
    for (int i=0; i<celdas.size(); i++)
        std::cout << std::fixed << std::setw(9)<<celdas.at(i)<< "  ";
    std::cout << std::endl;
}

template <class Clave>
void Celdas<Clave>::print_name(void) const{
    for (int i=0; i<celdas.size(); i++)
        std::cout << std::fixed << std::setw(12)<<celdas.at(i)<<"["<<celdas[i].get_name()<<"]"<<"  ";
    std::cout << std::endl;
}

template <class Clave>
void Celdas<Clave>::resize (int sz)
{
	celdas.resize(sz);
}
