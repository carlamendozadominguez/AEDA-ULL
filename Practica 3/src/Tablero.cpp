/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tablero.cpp
 * Author: carla
 * 
 * Created on 24 de febrero de 2018, 11:57
 */

#include "Tablero.hpp"

Tablero::Tablero() {    
    rellena_tablero();
}

Tablero::Tablero(int m ,int n) {
    Matriz matrix(m,n);
    matriz = matrix;
    rellena_tablero();
}

Tablero::~Tablero() {}

//Inicialmente ponemos todo el tablero en blanco
void Tablero::rellena_tablero(void){
    for(int i = 0; i < matriz.get_m(); i++)
        for(int j = 0; j < matriz.get_n(); j++)
            matriz.set(i,j,0); // El 0 es blanco
        
        matriz.set(9,9,-1);
        matriz.set(9,8,-1);
        matriz.set(8,9,-1);
        matriz.set(8,8,-1);
    
}

int Tablero::get_m(){
    return matriz.get_m();
}

int Tablero::get_n(){
    return matriz.get_n();
}

void Tablero::cambiar_color(int i, int j, int color){ 
    matriz.set(i,j,color);
}

int Tablero::get_color(int i, int j){
    return matriz.get(i,j); 
}

//Mostramos el tablero entero, hormiga incluida
void Tablero::write(ostream& os, vector <Agente*> a){
    
    bool mostrada = 0;
    
    for(int i = 0; i < matriz.get_m(); i++){         
        for(int j = 0; j < matriz.get_n(); j++){
            mostrada = false;
            for(int k=0 ; k < a.size();k++){
                if ((a[k]->get_x() == i) && (a[k]->get_y() == j)){ //La pos de la hormiga
                    a[k]->write(os); //Muestra la hormiga
                    mostrada = true;
                }
            }
            if(!mostrada)
                if (matriz.get(i,j) == 0){
                    os << setw(2)<<'-'; //cuando se trata de un blanco
                }else if(matriz.get(i,j) == 1){
                    os <<setw(2)<< 'x'; //Cuando se trata de un negro
                }else if(matriz.get(i,j) == 2){
                    os <<setw(2)<< '*'; //Cuando se trata de un verde
                }else if(matriz.get(i,j) == 3){
                    os <<setw(2)<< '#'; //Cuando se trata de un rojo
                }else if(matriz.get(i,j) == -1){
                    os << setw(2)<<'$';
                }
        }
    
    os << endl;
} 

}        

Tablero& Tablero::operator=(const Tablero& other){
    
    if(this != &other){
        this->matriz = other.matriz;
    }
    
    return *this;
    
}