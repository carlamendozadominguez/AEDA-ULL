/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tabla.h
 * Author: carla
 *
 * Created on 1 de abril de 2018, 19:36
 */

#ifndef TABLA_H
#define TABLA_H

#include "Celdas.h"
#include "fExploracionBase.h"
#include <cstdio>
#include <iostream>



template <class Clave>
class Tabla{

private:
	Celdas<Clave>* vCeldas_;
	int nCeldas_;
	int nClaves_;
	int nPruebas_;
	int count;
	fDispersionBase<Clave>* DispFunc_;
	fExploracionBase<Clave>* ExFunc_;

public:
	Tabla (int nCeldas, int nClaves, int DispFunc, int ExFunc, int nPruebas);
	~Tabla (void);
	
	int size (void) const;
	int Celdas_size (void) const;

	bool buscar (const Clave& x);
	bool insertar (const Clave& x);
    	void reset_count(void);
	int get_count(void);
    	void print (void) const;
	void print_name (void) const;
	
};




template <class Clave>
Tabla<Clave>::Tabla (int nCeldas, int nClaves, int DispFunc, int ExFunc, int nPruebas){

	nCeldas_= nCeldas;
	nClaves_ = nClaves;
	nPruebas_ = nPruebas;


	count = 0 ;
	vCeldas_ = new Celdas<Clave>[nCeldas];
	for (int i=0; i<nCeldas; i++)
		vCeldas_[i].resize(nClaves);
	
	switch (DispFunc)
	{
		case 1 : DispFunc_ = new fDispersionModulo<Clave> (nCeldas); break;
		case 2 : DispFunc_ = new fDispersionAleatorio<Clave> (nCeldas); break;
                case 3 : DispFunc_ = new fDispersionSuma<Clave> (nCeldas); break;
                default : std::cout << "La opción introducida para la función de dispersión no está permitida. " << std::endl; break;
	}
	
	switch (ExFunc)
	{
		case 1 : ExFunc_ = new fExploracionLineal<Clave> (nCeldas); break;
		case 2 : ExFunc_ = new fExploracionCuadratica<Clave> (nCeldas); break;
		case 3 : ExFunc_ = new fExploracionDoble<Clave> (nCeldas); break;
		case 4 : ExFunc_ = new fExploracionReDisp<Clave> (nCeldas); break;
		default : std::cout << "La opción introducida para la función de exploración no está permitida. " << std::endl; break;
	}
}

template <class Clave>
Tabla<Clave>::~Tabla (void)
{
	nCeldas_ = 0;
	nClaves_ = 0;
	
	if (vCeldas_ != NULL)
	{
		delete [] vCeldas_;
		vCeldas_ = NULL;
	}
}



template <class Clave>
int Tabla<Clave>::size (void) const
{
	return nCeldas_;
}

template <class Clave>
int Tabla<Clave>::Celdas_size (void) const
{
	return nClaves_;
}


template <class Clave>
bool Tabla<Clave>::buscar (const Clave& x)
{
	std::cout << std::endl << std::endl;
	std::cout << "Buscando la clave " << x <<", " <<x.get_name()<< " en la tabla. " << std::endl;
	int pos = DispFunc_->hash(x);
    count++;
	bool found = vCeldas_[pos].buscar(x);
	
	int i=0;
	while ((!found) && (i<=nPruebas_))
	{
		i++;
		int moving = ExFunc_->explore(x, i);
		if (moving + pos >= nCeldas_)
			pos = (pos + moving) % nCeldas_;
		else
			pos += moving;
        count++;
		found = vCeldas_[pos].buscar(x);
	}
	
	if (found)
		std::cout << "Clave " << x << " encontrada en la tabla, en la celda " << pos << "." << std::endl;
	else
		std::cout << "Clave " << x << " no encontrada en la tabla." << std::endl;
	return found;
}




template <class Clave>
bool Tabla<Clave>::insertar (const Clave& x)
{
	std::cout << std::endl << std::endl;
	std::string n= x.get_name();
	std::cout << "Intentando insertar la clave " << x <<","<< n << " en la tabla. " << std::endl;
	bool success = buscar(x);
    int i = 0;
	reset_count();
	
	if (!success)
	{
        int pos = DispFunc_->hash(x);
        std::cout<<"Insertando en la pos:"<<pos<<std::endl;
		count++;
        success = vCeldas_[pos].insertar(x);
        
        while ((!success) && (i<=nPruebas_))
        {
            i++;
            int desp = ExFunc_->explore(x,i);
			std::cout<<"UPS no se pudo!.Realizamos exploracion pos:"<<desp<<std::endl;
            if (pos + desp >= nCeldas_){
                pos = (pos + desp) % nCeldas_;
				std::cout<<"Se ha salido de la tabla, aplicamos modulo:"<<pos<<std::endl;
			}
            else{
                pos += desp;
				std::cout<<"Lo inserto en:"<<pos<<std::endl;
			}
            count++;
            success = vCeldas_[pos].insertar(x);
        }
	}
	
	else
		std::cout << "La clave " << x << " ya está en la tabla. " << std::endl;
	
	return success;	
}





template <class Clave>
void Tabla<Clave>::print (void) const
{
    std::cout << std::endl << std::endl << "IMPRIMIENDO LA TABLA HASH AL COMPLETO. " << std::endl;
    for (int i=0; i<nCeldas_; i++) {
        vCeldas_[i].print();
        std::cout << std::endl;
    }
}

template <class Clave>
void Tabla<Clave>::print_name (void) const
{
    std::cout << std::endl << std::endl << "IMPRIMIENDO LA TABLA HASH AL COMPLETO. " << std::endl;
    for (int i=0; i<nCeldas_; i++) {
        vCeldas_[i].print_name();
        std::cout << std::endl;
    }
}



template <class Clave>
void Tabla<Clave>::reset_count(void){
	count = 0;
}

template <class Clave>
int Tabla<Clave>::get_count(void){
	return count;
}

#endif /* TABLA_H */

